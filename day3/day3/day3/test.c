#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


int main()
{
	SListNode* pList = NULL;
	SListPushBack(&pList,1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SlistPrint(pList);

	SListNode* pos =  SListFind(pList, 2);
	if (pos)
	{
		pos->Data = 30;
	}
	
	SListPushFront(&pList,0);
	SlistPrint(pList);
	SListPopFront(&pList);
	SlistPrint(pList);

	SListInsertAfter(pList, 1);
	SListEarseAfter(pList);
	SlistPrint(pList);
}



