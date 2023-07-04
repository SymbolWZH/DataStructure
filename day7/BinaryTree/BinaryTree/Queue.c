#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Queue.h"


typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
/*��ʼ��*/
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

/*����*/
void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}
/*�����*/
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("�ڴ治��\n");
		exit(-1);
	}
	newnode->_data = x;
	newnode->_next = NULL;

	if (pq->_head == NULL)
	{
		pq->_head = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}
/*������*/
void QueuePop(Queue* pq)
{
	assert(pq && pq->_head);
	QueueNode* next = pq->_head->_next;
	free(pq->_head);
	pq->_head = next;

	if (pq->_head == NULL)
	{
		pq->_tail = NULL;
	}
}
/*ȡͷ����*/
QDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_head);
	return pq->_head->_data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_tail);
	return pq->_tail->_data;
}
/*�����С*/
int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}
/*����1�ǿ�  �� ����0 �Ƿǿ�*/
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return !pq->_head;
}