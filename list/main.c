#include <stdio.h>
#include "list.h"

int main()
{
	node_t *pHead = NULL;
	int i = 0;
	printf ("ready add\n");
	for (i=0; i<10; i++) {
		add (&pHead, i);
	}
	printf ("ready print\n");
	print (pHead);
	pHead = reverse (pHead);
	printf ("ready reverse\n");
	print (pHead);

	return 0;
}
