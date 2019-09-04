#include <stdio.h>
#include <stdlib.h>

int getA(const char *p){
    printf ("getA:%s\n", p);
    return 0;
}

int getB(const char *p){
    printf ("getB:%s\n", p);
    return 0;
}
int getD(const char *p){
    printf ("getD:%s\n", p);
    return 0;
}

int getC(const char *p){
    printf ("getC:%s\n", p);
    return 0;
}

typedef int (*cb_get[])(const char *p);

int cry(cb_get cbg, const char *p)
{
    // 如何取到函数指针数据大小
    //int nNum = sizeof (cbg) / sizeof (cbg[0]);
    printf ("%d, %d\n", sizeof (cbg), sizeof (cbg[0]));
    int nNum = 4;
    for (int i=0; i<nNum; i++) {
        (*cbg[i])(p);
    }
}

int main()
{
    int i=100;
    cb_get arrcb = {getA, getB, getC, getD};
    printf ("%d\n", sizeof (arrcb)/sizeof (arrcb[0]));
    cry(arrcb, "helloworld");
    return 0;
}