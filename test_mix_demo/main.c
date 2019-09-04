#include <stdio.h>

// const 常量
void constUse(const int value)
{
	//value = 100;		// 不允许

#define SIZE 1029 		//	C里面常规用法
	char buf[] = "helloworld";
	char buf2[] = "NIHAO";
	char const * ccpp = buf;  	// 作用和以下一样
	const char *ccp = buf;     	//指向const char 的指针, 保护的是指针指向的内容而不是指针本身
	//ccp[0] = 'G';			// 这个目的是要改变指针指向的内容的值，编译报错
	char * const cpc = buf;  //这是一个const 的指针，指向char，那意味着该指针本身不能被改变，但是内容可以改变
	cpc[0] = 'N';		//意味着该指针本身不能被改变，但是内容可以改变
	//cpc = buf2;		// 指针本身不能改变

	int d = 100;
	int const * const p = &d;
	const int * const pp = &d;
	// *p = 99;	 // 不允许
	d = 99;    // 那如果是这样情况呢，不是尴尬吗
	printf ("d:%d, d:%d\n", *p, *pp);

	int *u = &d, v = 89; // u 是指针， v是int类型，易混淆
	

	printf ("1:%s,2:%s,3:%s\n", ccp, cpc, ccpp); 
}

void u (const int * cip)
{
	//int *p = cip; // 不推荐，强制类型转换
	int i = *cip; // 纯粹地get值
	//*cip = 2;  // 企图修改。不行

}

int main()
{
	int value = 99;
	constUse (value);

	const int a;
#if 0
	// 位域
	struct stu{
		int value:4; 	// int占用32个字节，第一位为符号位，所以一般采用unsigned int 具体看情况。所以最大值为7。
	};


	struct stu a;
	a.value = 7;
	printf ("a.value:%d\n", a.value);
#endif // 0

	return 0;
}
