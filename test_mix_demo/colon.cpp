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

int main()
{
    data_t d;
    d.a = 15; // 16直接报错
    cout << "d.a:" << d.a  << "#" << endl;

    CTest ct;
    cout << postmsg() << endl;
    cout << ct.postmsg() << endl;
    return 0;
}