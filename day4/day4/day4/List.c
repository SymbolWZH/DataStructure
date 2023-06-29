#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

/*初始化*/
ListNode* ListInit()
{
	ListNode * phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
/*打印*/
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
/*创建节点*/
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
/*尾插节点*/
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
/*尾删节点*/
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
/*头插*/
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
/*头删*/
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
/*查找*/
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

/*插入*/
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
/*删除*/
void* ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}
/*删除所有*/
ListNode* ListDestroy(ListNode**pphead)
{
	assert(*pphead);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}

/*清理所有数据节点 保留头节点 可以继续使用*/
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