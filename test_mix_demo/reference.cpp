#include <iostream>
using namespace std;

int a = 100;
int b = 99;
int& ar = a;
int* ap = &a;

class CTest
{
    int m_nValue;
public:
    CTest(int nValue=100):m_nValue(nValue){}
};

int change(int **p){
    *(*p) = 6666;
    return 0;
}

int changer(int*& p){
    *p = 19988;
    return 0;
}

int main()
{
    ar = b;
    ap = &b;
    
    cout << "a:" << ar << endl;

    CTest ct1(1999);
    CTest ct2(6666);
    cout << "ct1:" << &ct1 << endl;
    cout << "ct2:" << &ct2 << endl;
    CTest& ctr1 = ct1;
    cout << "ctr1:" << &ctr1 << endl;
    CTest& ctr2 = ct2;
    cout << "ctr2:" << &ctr2 << endl;
    ctr1 = ctr2;  // 编译器不报错，但是没有效果
    cout << "ctr1:" << &ctr1 << endl;

    int value = 100;
    int* pValue = &value;
    change (&pValue);
    cout << "value:" << value << endl;
    changer (pValue);
    cout << "value:" << value << endl;
    
    return 0;
}