#ifndef SUB_H__
#define SUB_H__

#include <list>
#include <string>
#include "ob.h"

class CSubject
{
protected:
    std::list<COb*> m_listOb;
public:
    virtual void add(COb* p) = 0;
    virtual void del(COb* p) = 0;   
    virtual void notify(char * p, log_enum_t flag) = 0;
    virtual ~CSubject(){ }
};

class CSvr : public CSubject
{
public:
    void add(COb* p){
        m_listOb.push_back (p);
    }
    void del(COb* p){
        std::list<COb*>::iterator it;
        for (it=m_listOb.begin(); it!=m_listOb.end(); it++) {
            if ((*it) == p) {
                m_listOb.erase(it);
            }
        }
    }
    void notify(char * p, log_enum_t flag){
        std::list<COb*>::iterator it;
        for (it=m_listOb.begin(); it!=m_listOb.end(); it++) {
            if (flag == (*it)->getFlag())
                (*it)->recv (p);
        }
    }
};

#endif //SUB_H__