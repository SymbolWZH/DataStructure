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
/*初始化*/
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = pq->_tail = NULL;
}

/*销毁*/
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
/*入队列*/
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("内存不足\n");
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
/*出队列*/
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
/*取头数据*/
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
/*计算大小*/
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
/*返回1是空  ， 返回0 是非空*/
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return !pq->_head;
}