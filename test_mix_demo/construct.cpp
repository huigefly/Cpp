#include <stdio.h>
#include <iostream>
using namespace std;

class CBase
{
    int nValue;
public:
    int get() const {return nValue;}
};

class CTest : public CBase
{
public:
    CTest(){}
};

int main()
{
    CTest ct;

    return 0;
}