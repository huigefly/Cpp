#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class CTest
{
    int nVlaue;
    static int nCount;
public:
    CTest():nVlaue(100){
        nCount++;
        cout << "CTest:" << nCount << endl;
    }
    ~CTest(){
        nCount--;
        cout << "~CTest:" << nCount << endl;
    }
    int get()const {return nCount;}
};
int CTest::nCount = 0;

void* operator new(size_t sz)
{
    printf ("current use global new, size:%d\n", sz); // avoid use cout
    void *p = malloc (sz);
    if (NULL == p) {
        printf ("in new malloc error\n");
    }
    return p;
}

void operator delete(void *p)
{
    printf ("current use global delete"); // avoid use cout
    free (p);
}

int main()
{
    int ll = 1000;
    string a = "a";
    string s = "helloworld" + a;

    CTest *pct = new CTest[10];
    for (int i=0; i<10; i++) {
        cout << pct[i].get() << endl;
    }
    delete[] pct;
    cout << "-------------------------------" << endl;
#if 1
    void **p = new void*[10];
    int nSize = sizeof (void *);
    cout << "size:" << nSize << endl;
    memset (p, 0, 10 * nSize);
    for (int i=0; i<10; i++){
        char szBuf[1024] = {""};
        sprintf (szBuf, "helloworld_%d", i);
        p[i] = (char *)malloc (1024);
        memcpy (p[i], szBuf, strlen (szBuf));
    }
    cout << "size:" << nSize << endl;
    for (int i=0; i<10; i++){
        cout << (char *)p[i] << endl;
    }
#endif //0
    return 0;
}