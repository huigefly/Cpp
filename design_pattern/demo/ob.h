#ifndef OB_H__
#define OB_H__

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <unistd.h>

typedef enum {warn=0,info=1,erro=2,debu=3}log_enum_t;

class COb
{
protected:
    log_enum_t flag;
    std::list<char*> m_listLine;
    std::ofstream of;
public:
    virtual void recv(char * sLine){
        m_listLine.push_back(sLine);
    }
    virtual log_enum_t getFlag() const { return flag; }
    virtual void handle() {
        while (1){
            if (m_listLine.size () == 0) {
                sleep (1);
            }else{
                char *p = m_listLine.front ();
                m_listLine.pop_front();
                exec(p);
            }
        }
    }
    virtual void exec(char *p) = 0;
    COb(log_enum_t t, const char *p):flag(t), of(p){}
    virtual ~COb(){
        of.close ();
    }
};

class CWarn : public COb
{
public:
    friend void *procOb(void *lparam);
    void exec(char *p){
        of << "cwarn:" << p << std::endl; sleep (0.5);
    }
    CWarn():COb(warn, "warn.log"){}
};
class CInfo : public COb
{
public:
    friend void *procOb(void *lparam);
    void exec(char *p){
        of << "cinfo:" << p << std::endl;sleep (0.5);
    }
    CInfo():COb(info, "info.log"){}
};
class CErro : public COb
{
public:
    friend void *procOb(void *lparam);
    void exec(char *p){
        of << "cerro:" << p << std::endl; sleep (0.5);
    }
    CErro():COb(erro, "erro.log"){}
};
class CDebu : public COb
{
public:
    friend void *procOb(void *lparam);
    void exec(char *p){
        of << "cdebu:" << p << std::endl; sleep (0.5);
    }
    CDebu():COb(debu, "debu.log"){}
};

#endif //OB_H__
