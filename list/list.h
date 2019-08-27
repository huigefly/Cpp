#ifndef LIST_H__
#define LIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int nValue;
	struct node *pNext;
}node_t;

int add(node_t **ppHead, int nValue)
{
	node_t *pHead = *ppHead;
#if 0
	//printf ("pphead:%p, phead:%p, *pphead:%p\n", ppHead, pHead, *ppHead);
	if (*ppHead == NULL) {
		(*ppHead) = (node_t*)malloc (sizeof (node_t));
		(*ppHead)->nValue = nValue;
		(*ppHead)->pNext = NULL;
		//printf ("value 1:%d\n", nValue);
	} else {
		node_t **tmp = &((*ppHead)->pNext);
		while (*tmp) {
			tmp = &(*tmp)->pNext;
		}
		//printf ("value:%d\n", nValue);
		(*tmp) = (node_t*)malloc (sizeof (node_t));
		(*tmp)->nValue = nValue;
		(*tmp)->pNext = NULL;
	}
#else 
		node_t **tmp = ppHead;
		while (*tmp) {
			tmp = &(*tmp)->pNext;
		}
		//printf ("value:%d\n", nValue);
		(*tmp) = (node_t*)malloc (sizeof (node_t));
		(*tmp)->nValue = nValue;
		(*tmp)->pNext = NULL;
#endif //0
	
	return 0;
}

int print(node_t *pHead)
{
	node_t *tmp = pHead;
	while (tmp) {
		printf ("print value:%d\n", tmp->nValue);
		tmp = tmp->pNext;
	}
	
	return 0;
}

int del(node_t *pHead, int nValue)
{
	return 0;
}

node_t* reverse(node_t *pHead)
{
	node_t *pCur = pHead;
	node_t *pPre = NULL;
	node_t *pNewHead = NULL;
	while (pCur) {
		node_t *pNext = pCur->pNext;
		if (NULL == pNext) {
			pNewHead = pCur;
		}
		pCur->pNext = pPre;
		pPre = pCur;
		pCur = pNext;
	}

	return pNewHead;
}

#endif // LIST_H__
