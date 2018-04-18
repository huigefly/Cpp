#ifndef TIMER_WARN_H__
#define TIMER_WARN_H__

#include <unistd.h>
#include <list>
#include "INotifer.h"
using namespace std;

class CTimerWarn
{
public:
	CTimerWarn(int nValue)
	{
		this->m_nTime = nValue;
	}
	
	~CTimerWarn()
	{
		this->m_listNotifer.clear();
	}
	
	int run()
	{
		for (int i = 0; i < this->m_nTime; i++)
		{
			printf ("second:%d\n", i);
			list<CINotifer*>::iterator it;
			for (it=this->m_listNotifer.begin(); it!=this->m_listNotifer.end(); it++)
			{
				(*it)->notify(&i);
			}
			sleep(1);
		}
	
		return 0;
	}
	
	int addNotifer(CINotifer* pNotifer)
	{
		if (pNotifer != NULL)
		{
			this->m_listNotifer.push_back(pNotifer);
		}
	
		return 0;
	}
	
	int removeNotifer(CINotifer* pNotifer)
	{
		if (pNotifer != NULL)
		{
			this->m_listNotifer.remove(pNotifer);
		}
	}
	
private:
	int m_nTime;
	list<CINotifer*> m_listNotifer;
};

#endif // TIMER_WARN_H__
