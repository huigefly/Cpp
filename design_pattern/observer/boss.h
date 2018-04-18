#ifndef CBOSS_H__
#define CBOSS_H__

#include "INotifer.h"

class CBoss : public CINotifer
{
public:
	virtual int notify(void *pParam){
		printf("CBoss notify:%d\n", *(int*)pParam);
	}
	virtual ~CBoss(){}
};

#endif // CBOSS_H__
