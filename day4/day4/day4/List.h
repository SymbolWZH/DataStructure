#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

void ListPushBack(ListNode* phead ,LTDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
void ListPrint(ListNode* phead);

void* ListInsert(ListNode* phead, LTDataType x);
void* ListErase(ListNode* phead);
void ListClear(ListNode* phead);
//void ListInit(ListNode** phead);

ListNode* ListInit();
ListNode* BuyListNode(LTDataType x);
ListNode* ListFind(ListNode* phead, LTDataType x);
ListNode* ListDestroy(ListNode** pphead);
