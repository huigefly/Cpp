#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

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
    printf ("a:%d, %p\n", a++, &a);
}

class c{
    static const int value = 100;
public:
    //c(int v) : value(v){} //编译出错，只能在定义的地方初始化
};

void *proc(void *lparam)
{
    printf ("thread:%d\n", pthread_self());
    func();
}

int main()
{
    const int a = 99;
    int i=100;
    while (i--){
        func();
    }

    pthread_t tid[10];
    for (int i=1; i<10; i++){
        pthread_create (&tid[i], NULL, proc, NULL);
    }

    sleep (4100);

    return 0;
}
