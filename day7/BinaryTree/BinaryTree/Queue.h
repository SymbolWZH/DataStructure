#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
extern struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;
/*初始化*/
void QueueInit(Queue* pq);
/*销毁*/
void QueueDestory(Queue* pq);
/*入队列*/
void QueuePush(Queue* pq, QDataType x);
/*出队列*/
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
/*计算大小*/
int QueueSize(Queue* pq);
/*返回1是空  ， 返回0 是非空*/
int QueueEmpty(Queue* pq);