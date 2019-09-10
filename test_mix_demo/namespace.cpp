#include <stdio.h>
#include <stdlib.h>

namespace huige{
    int g_value = 9999;
    const char* getName ()
    {
        return "zhengfh";
    }

    class CTest{
        int nValue;

    public:
        CTest(int i):nValue(i){}
        int get(){return nValue;}
        friend int getValuea(CTest *ct);
    };
    int getValuea(CTest *ct);
}

int huige::getValuea(huige::CTest *ct)
{
    return ct->nValue;
}


int main()
{
    huige::CTest ct(9965);
    printf ("%s,%d\n", huige::getName(), getValuea(&ct));
    return 0;
}