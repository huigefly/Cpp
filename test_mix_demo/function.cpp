#include <stdio.h>

int faunction(int a, float f)
{
	printf ("a:%d,f:%f\n", a, f);

	return 0;
}

int function (int a, float f, char z='a')
{
	printf ("a:%d, f:%f, z:%c\n", z, f, z);
	return 0;
}

int main()
{
	int a=100;
	float f=99.99;
	char z='f';
	
	function (a, f);
	function (a, f, z);

	return 0;
}
