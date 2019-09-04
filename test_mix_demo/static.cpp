#include <stdio.h>
#include <stdlib.h>

// g_sa和get 只能在该文件中使用, 使用extern也是无效
static int g_sA;
static int get()
{
    return g_sA;
}

// 不管调用几次，只会初始化一次
void func()
{
    static int a = 100;
    printf ("a:%d\n", a++);
}

int main()
{
    int i=100;
    while (i--){
        func();
    }
    return 0;
}