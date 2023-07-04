#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include "Queue.h"
/*
栈的作用：后进先出
1. 如果有后进先出需求的地方，比如迷宫问题
2. 递归改成非递归
*/

void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 3);
	StackPush(&st, 4);
	

	while (!StackEmpty(&st))
	{
		printf("%d ",StackTop(&st));
		StackPop(&st);
	}
	printf("\n");

	StackDestory(&st);
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePop(&q);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	
	while (!QueueEmpty(&q))
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);
}
int main()
{
	TestQueue();
	//TestStack();
	return 0;
}