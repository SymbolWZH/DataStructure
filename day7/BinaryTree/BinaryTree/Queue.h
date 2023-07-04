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
/*��ʼ��*/
void QueueInit(Queue* pq);
/*����*/
void QueueDestory(Queue* pq);
/*�����*/
void QueuePush(Queue* pq, QDataType x);
/*������*/
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
/*�����С*/
int QueueSize(Queue* pq);
/*����1�ǿ�  �� ����0 �Ƿǿ�*/
int QueueEmpty(Queue* pq);