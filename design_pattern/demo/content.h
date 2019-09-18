#ifndef CONTENT_H__
#define CONTENT_H__

#include <list>

class CMetux
{

};

class CContent
{
    std::list<char*> m_listLog;
    static CContent* p;
public:
    static CContent* getIntance(){
        return p;
    }

    void add(char *p) {
        m_listLog.push_back(p);
    }

    char* pop(){
        char *p = m_listLog.front ();
        m_listLog.pop_front();
        return p;
    }

    int size(){
        return m_listLog.size();
    }
    ~CContent(){
        std::list<char*>::iterator it;
        for (it=m_listLog.begin(); it!=m_listLog.end(); it++){
            if ((*it) != NULL) {
                std::cout << "free" << *it << std::endl;
                free (*it);
            }
        }
    }
};

#endif // CONTENT_H__
