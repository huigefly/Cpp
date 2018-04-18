#ifndef CLERK_H__
#define CLERK_H__

#include "INotifer.h"

class CClerk : public CINotifer
{
public:
	virtual int notify(void *pParam){
		if (NULL != pParam)
			printf("CClerk notify:%d\n", *(int*)pParam);
	}
	virtual ~CClerk(){}
};

#endif // CLERK_H__
