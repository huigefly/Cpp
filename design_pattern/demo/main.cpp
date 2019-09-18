#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "sub.h"
#include "content.h"
using namespace std;

typedef void (*cb_handle)(string&);

CContent* CContent::p = new CContent();

class CReadMsg
{
    char *m_pszBuffer;
    ifstream m_in;
public:
    void proc(){
        while (!m_in.eof ()){
            m_pszBuffer = (char *)malloc (1024);
            memset (m_pszBuffer, 0, 1024);
            m_in.getline(m_pszBuffer, 1024);
            CContent::getIntance()->add(m_pszBuffer);
            //cout << m_pszBuffer << endl;
        }
    }
    CReadMsg(){
        m_in.open("new-sync-log");
    }
    ~CReadMsg(){m_in.close ();}
};

void *proc(void *lparam)
{
    CSvr *psvr = (CSvr*)lparam;
    pthread_detach (pthread_self());
    CContent *pc = CContent::getIntance();
    while (pc->size() > 0){
        char *line = pc->pop();
        if (strstr(line, "WARN")){
            //cout << "proc:"<< line << endl << "size:" << pc->size() << endl;
            psvr->notify (line, warn);
        }else if (strstr(line, "ERRO")){
            psvr->notify (line, erro);
        }else if (strstr(line, "INFO")){
            psvr->notify (line, info);
        }else if (strstr(line, "DEBU")){
            psvr->notify (line, debu);
        }
            
    } 
    cout << "thread exit" << endl;
}

void *procOb(void *lparam)
{
    COb *pob = (COb*)lparam;
    pob->handle();
}

int main()
{
    COb *pob[4] = {new CWarn(),new CInfo(),new CDebu(),new CErro() };
    CSvr svr;
    pthread_t obtid[4];
    for (int i=0; i<4; i++){
        svr.add(pob[i]);
        pthread_create (&obtid[i], NULL, procOb, pob[i]);
    }

    CReadMsg rm;
    rm.proc();

    pthread_t tid;
    pthread_create(&tid, NULL, proc, (void *)&svr);

    sleep (1000);

    return 0;
}