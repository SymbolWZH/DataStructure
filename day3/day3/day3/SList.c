#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//创建节点
SListNode* BuyListNode( SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请节点失败\n");
		exit(-1);
	}
	newNode->Data = x;
	newNode->next = NULL;

	return newNode;
}
/*尾加*/
void SListPushBack(SListNode** pphead, SListDataType x)
{	
	SListNode* newNode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//找尾
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		
		tail->next = newNode;
	}
}

/*尾删*/
void SListPopBack(SListNode** pphead)
{
	//1 空
	if (*pphead == NULL)
	{
		return;
	}
	//2 一个
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3 一个以上
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		
		prev->next = NULL;
	}
	//找尾
	
}

/*头加*/
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}

	newNode->next =(*pphead)->next;
	*pphead = newNode;
}

/*头删*/
void SListPopFront(SListNode** pphead)
{
	//1 空
	if (*pphead == NULL)
	{
		return;
	}
	//2 一个+3 一个以上
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		(*pphead) = next;
	}
}

/*查找*/
SListNode* SListFind(SListNode* pphead, SListDataType x)
{
	if (pphead == NULL)
	{
		return;
	}
	SListNode* cur = pphead;
	while (cur)
	{
		if (cur->Data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

/*打印*/
void SlistPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->Data);
		cur = cur->next;
	}
	printf("NULL\n");
}

/*插入*/
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

/*插入*/
void SListEarseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->next)
	{
		SListNode*  next = pos->next;
		SListNode* nextnext = next->next;
		pos->next = nextnext;
		free(next);
	}
}

/*计数*/
void SlistSize(SListNode* phead)
{

}