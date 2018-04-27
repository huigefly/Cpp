#ifndef DECORATE_H__
#define DECORATE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// define interface
class CBase
{
public:
	virtual int Print() = 0;
	
	virtual const char* StringA() = 0;
	virtual const char* StringB() = 0;
};

class CStringEasy : public CBase
{
public:
	virtual const char* StringA()
	{
		return "easyToA";
	}
	
	virtual const char* StringB()
	{
		return "easyToB";
	}
};

class CStringMid : public CBase
{
public:
	virtual const char* StringA()
	{
		return "midToA";
	}
	
	virtual const char* StringB()
	{
		return "midToB";
	}
};

class CPrintEasy : public CStringEasy
{
public:
	virtual int Print()
	{
		string sBuffer = CStringEasy::StringA();
		printf ("CPrintEasy print:%s", sBuffer.c_str());
		return 0;
	}
};

class CPrintEasyPlus : public CStringEasy
{
public:
	virtual int Print()
	{
		string sBuffer = CStringEasy::StringA();
		printf ("CPrintEasyPlus print:%s", sBuffer.c_str());
		
		return 0;
	}
};

class CPrintMid : public CStringMid
{
public:
	virtual int Print()
	{
		string sBuffer = CStringMid::StringA();
		printf ("CPrintMid print:%s", sBuffer.c_str());
		return 0;
	}
};

class CPrintMidPlus : public CStringMid
{
public:
	virtual int Print()
	{
		string sBuffer = CStringMid::StringA();
		printf ("CPrintMidPlus print:%s", sBuffer.c_str());
		return 0;
	}
};

#endif // DECORATE_H__
