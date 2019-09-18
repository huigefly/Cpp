#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

/*
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
*/

string sArr[] = {"WARN:", "ERRO:", "INFO:", "DEBU:"};

int main()
{
    ifstream in("sync-log.txt");
    ofstream of("new-sync-log");
    while(!in.eof()) {
        char szBuffer[1024] = {0};
        in.getline(szBuffer, 1024);
        int i = (rand()%4) + 0;
        of<< sArr[i] << szBuffer<<endl;
    }

    return 0;
}