#include "string.h"
#include <iostream>

using namespace std;

int main()
{
  String s1("hello"); 
  String s2("world"); // 调用构造
    
  String s3(s2);
  cout << s3 << endl;
  
  s3 = s1;            // 调用赋值
  cout << s3 << endl;     
  cout << s2 << endl;  
  cout << s1 << endl;      
}
