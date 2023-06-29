#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;
// 节点
//链表其实就是针对顺序表的缺点来设计的 补足的就是顺序表的缺点
typedef struct SListNode
{
	SListDataType Data;
	struct SListNode* next;
}SListNode;

/*尾加*/
void SListPushBack(SListNode** phead, SListDataType x);

/*尾删*/
void SListPopBack(SListNode** pphead);

/*头加*/
void SListPushFront(SListNode** pphead, SListDataType x);

/*头删*/
void SListPopFront(SListNode** pphead);

/*查找*/
SListNode* SListFind(SListNode* pphead, SListDataType x);

void SListInsertAfter(SListNode* pos, SListDataType x);
/*指定删除*/
void SListEarseAfter(SListNode* pos);

/*打印*/
void SlistPrint(SListNode* phead);


/*计数*/
void SlistSize(SListNode* phead);