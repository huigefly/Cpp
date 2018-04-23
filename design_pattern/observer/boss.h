#ifndef CBOSS_H__
#define CBOSS_H__

#include "INotifer.h"

// 模拟老板类
class CBoss : public CINotifer
{
public:
	// 编写通用接口
	virtual int notify(void *pParam){
		printf("CBoss notify:%d\n", *(int*)pParam);
	}
	virtual ~CBoss(){}
};

#endif // CBOSS_H__
