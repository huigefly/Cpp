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
    //int nNum = sizeof (cbg) / sizeof (cbg[0]);
    printf ("%d, %d\n", sizeof (cbg), sizeof (cbg[0]));
    int nNum = 4;
    for (int i=0; i<nNum; i++) {
        (*cbg[i])(p);
    }
}

int size(int *arr[])
{
    printf ("size:%p,%d, %d\n", arr, sizeof (arr), sizeof (arr[0]));

    return 0;
}

int main()
{
    int i=100, a=1, b=2, c=3;
    int *arr[] = {&a, &b, &c, &i};
    cb_get arrcb = {getA, getB, getC, getD};
    printf ("%d\n", sizeof (arrcb)/sizeof (arrcb[0]));
    cry(arrcb, "helloworld");
    size(arr);
    printf ("ex %p, size:%d\n", arr, sizeof (arr)/sizeof (arr[0]));
    return 0;
}