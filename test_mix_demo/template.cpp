#include <iostream>
using namespace std;

template<class T>
//template<class T, int size=100> // size可以是特例的常量
class CTest
{
    enum { size= 100};
    T a[size];
public:
    // 内联函数定义
    T& operator[](int i){
        return a[i];
    }
    T& get(int i);
};

// 非内联函数定义
template<class T>  // 这句话不能漏
T& CTest<T>::get(int i)
{
    return a[i];
}

class CInt
{
    int nValue;
public:
    int set(int i) { nValue=i;return 0; }
    int get() const { return nValue; }

    CInt(){} // 构造一定得有，才能在模板中使用？
    CInt(int i):nValue(i){ }
};

int main()
{
    // 实例化
    CTest<int> ct1;
    CTest<char> ct2;
    CTest<CInt> ct3;
    for (int i=0; i<100; i++){
        ct1[i] = i;
        ct2[i] = i;
        ct3[i].set(i);
    }

    for (int i=0; i<100; i++){
        cout << "ct1:" << ct1[i] << ":-> " << ct1.get(i) << endl;
        cout << "ct2:" << ct2[i] << ":-> " << ct2.get(i) << endl;
        cout << "ct3:" << ct3[i].get() << ":-> " << ct3[i].get() << endl;
    }

    return 0;
}