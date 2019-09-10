#include <cstdio>

class CTest{
    int nValue;

public:
    CTest(int i):nValue(i){}
    int get(){return nValue;}
    friend int getValue(CTest *ct);
};

int getValue(CTest *ct)
{
    return ct->get();
}

int main()
{
    CTest ct(15698);
    printf ("%d\n",getValue (&ct));

    return 0;
}