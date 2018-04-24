#include <stdio.h>
#include <stdlib.h>
#if 0
	#include "decorate.h"
#else
	#include "decoratePlus.h"
#endif

int main()
{
	CBase *base = new CPrintMid();
	base->Print();
	printf ("\n");

	return 0;
}