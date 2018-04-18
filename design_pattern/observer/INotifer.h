#ifndef INOTIFER_H__
#define INOTIFER_H__

class CINotifer
{
public:
	virtual int notify(void *pParam) = 0;
	virtual ~CINotifer(){}
};

#endif // INOTIFER_H__
