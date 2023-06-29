#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

/*��ʼ��*/
ListNode* ListInit()
{
	ListNode * phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
/*��ӡ*/
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", phead->data);
		cur = cur->next;
	}
	printf("\n");
}
/*�����ڵ�*/
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		return;
	}
	node->next = NULL;
	node->prev = NULL;
	node->data = x;

	return node;
}
/*β��ڵ�*/
void ListPushBack(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	
	ListNode* tail = phead->prev;
	ListNode* newNode = BuyListNode(x);

	tail->next = newNode;
	newNode->prev = tail;

	newNode->next = phead;
	phead->prev = newNode;*/

	ListInsert(phead, x);

}
/*βɾ�ڵ�*/
void ListPopBack(ListNode* phead)
{
	/*assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;
	
	tailPrev->next = phead;
	phead->prev = tailPrev;

	free(tail);
	tail = NULL;*/

	ListErase(phead->prev);

}
/*ͷ��*/
void ListPushFront(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	ListNode* first = phead->next;
	ListNode* newnode = BuyListNode(x);
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;*/

	ListInsert(phead->next, x);
}
/*ͷɾ*/
void ListPopFront(ListNode* phead)
{
	/*assert(phead);
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);*/

	ListErase(phead->next);
}
/*����*/
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

/*����*/
void* ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newNode = BuyListNode(x);

	newNode->next = pos;
	pos->prev = newNode;
	posPrev->next = newNode;
	newNode->prev = posPrev;
}
/*ɾ��*/
void* ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}
/*ɾ������*/
ListNode* ListDestroy(ListNode**pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}

/*�����������ݽڵ� ����ͷ�ڵ� ���Լ���ʹ��*/
void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = phead;
	phead->prev = phead;
}