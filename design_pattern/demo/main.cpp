#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

typedef void (*cb_handle)(string&);
typedef enum {warn=0,info=1,erro=2,debu=3}log_enum_t;

class COb
{
protected:
    int flag;
public:
    virtual void recv(const string&);
    COb(log_enum_t t):flag(t){}
};

class CSubject
{
protected:
    list<COb*> m_listOb;
    list<char*> m_listLog;
public:
    virtual void add(COb* p) = 0;
    virtual void del(COb* p) = 0;   
    virtual void notify() = 0;
    virtual void addLine(char* p) = 0;
    ~CSubject(){
        list<char*>::iterator it;
        for (it=m_listLog.begin(); it!=m_listLog.end(); it++){
            if ((*it) != NULL) {
                 cout << "free" << *it << endl;
                free (*it);
            }
        }
    }
};

class CSvr : public CSubject
{
public:
    void add(COb* p){
        m_listOb.push_back (p);
    }
    void del(COb* p){
        list<COb*>::iterator it;
        for (it=m_listOb.begin(); it!=m_listOb.end(); it++) {
            if ((*it) == p) {
                m_listOb.erase(it);
            }
        }
    }
    void notify(){
        list<COb*>::iterator it;
        for (it=m_listOb.begin(); it!=m_listOb.end(); it++) {
            string s = "helloworld";
            (*it)->recv (s);
        }
    }
    void addLine(char* p){
        m_listLog.push_back (p);
    }

};

class CWarn : public COb
{
public:
    void recv(const string& sLine){
        cout << "CWarn:" << sLine << endl;
    }
    CWarn():COb(warn){}
};
class CInfo : public COb
{
public:
    void recv(const string& sLine){
        cout << "CInfo:" << sLine << endl;
    }
    CInfo():COb(info){}
};
class CErro : public COb
{
public:
    void recv(const string& sLine){
        cout << "CErro:" << sLine << endl;
    }
    CErro():COb(erro){}
};
class CDebu : public COb
{
public:
    void recv(const string& sLine){
        cout << "CDebu:" << sLine << endl;
    }
    CDebu():COb(debu){}
};

class CReadMsg
{
    char *m_pszBuffer;
    ifstream m_in;
public:
    void proc(CSubject* ps){
        while (!m_in.eof ()){
            m_pszBuffer = (char *)malloc (1024);
            m_in.getline(m_pszBuffer, 1024);
            ps->addLine(m_pszBuffer);
            //cout << szBuffer << endl;
        }
    }
    CReadMsg(){
        m_in.open("new-sync-log");
    }
    ~CReadMsg(){m_in.close ();}
};


int main()
{
    CSvr svr;
    CReadMsg rm;
    rm.proc(&svr);

    sleep (1000);

    return 0;
}