#include <iostream>
using namespace std;

// 位域
struct data_t{
    unsigned int a:4;
    unsigned int c;

    data_t(): c('a'){}; // 初始化表达式列表
};

int postmsg()
{
    return 123456;
}

class  CTest
{
    int nValue;
public:
    int postmsg();

};

int CTest::postmsg()
{
    return ::postmsg();
}

#if 0
// 懒汉模式
class CSingleton
{
    static CSingleton *p;
    CSingleton(){}
public:
    static CSingleton* getInstance(){
        if (p == NULL) {
            p = new CSingleton();
        }
        return p;
    }
    int get(){
        cout << "this p:" << this << endl;
    }    
};
CSingleton* CSingleton::p=NULL;
#else
// 饿汉模式
class CSingleton
{
    static CSingleton *p;
    CSingleton(){}
public:
    static CSingleton* getInstance(){
        return p;
    }
    int get(){
        cout << "this p:" << this << endl;
    }    
};
CSingleton* CSingleton::p=new CSingleton();  // 静态成员是对象的时候，定义时调用构造
#endif // 0
int main()
{
    data_t d;
    d.a = 15; // 16直接报错
    cout << "d.a:" << d.a  << "#" << endl;

    CTest ct;
    cout << postmsg() << endl;
    cout << ct.postmsg() << endl;

    CSingleton *pSingle1 = CSingleton::getInstance();
    pSingle1->get ();
    CSingleton *pSingle2 = CSingleton::getInstance();
    pSingle2->get ();
    return 0;
}