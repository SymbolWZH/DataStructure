#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SListDataType;
// �ڵ�
//������ʵ�������˳����ȱ������Ƶ� ����ľ���˳����ȱ��
typedef struct SListNode
{
	SListDataType Data;
	struct SListNode* next;
}SListNode;

/*β��*/
void SListPushBack(SListNode** phead, SListDataType x);

/*βɾ*/
void SListPopBack(SListNode** pphead);

/*ͷ��*/
void SListPushFront(SListNode** pphead, SListDataType x);

/*ͷɾ*/
void SListPopFront(SListNode** pphead);

/*����*/
SListNode* SListFind(SListNode* pphead, SListDataType x);

void SListInsertAfter(SListNode* pos, SListDataType x);
/*ָ��ɾ��*/
void SListEarseAfter(SListNode* pos);

/*��ӡ*/
void SlistPrint(SListNode* phead);


/*����*/
void SlistSize(SListNode* phead);