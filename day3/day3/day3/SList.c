#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//�����ڵ�
SListNode* BuyListNode( SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("����ڵ�ʧ��\n");
		exit(-1);
	}
	newNode->Data = x;
	newNode->next = NULL;

	return newNode;
}
/*β��*/
void SListPushBack(SListNode** pphead, SListDataType x)
{	
	SListNode* newNode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		//��β
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		
		tail->next = newNode;
	}
}

/*βɾ*/
void SListPopBack(SListNode** pphead)
{
	//1 ��
	if (*pphead == NULL)
	{
		return;
	}
	//2 һ��
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3 һ������
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
	//��β
	
}

/*ͷ��*/
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

/*ͷɾ*/
void SListPopFront(SListNode** pphead)
{
	//1 ��
	if (*pphead == NULL)
	{
		return;
	}
	//2 һ��+3 һ������
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		(*pphead) = next;
	}
}

/*����*/
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

/*��ӡ*/
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

/*����*/
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newNode = BuyListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

/*����*/
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

/*����*/
void SlistSize(SListNode* phead)
{

}