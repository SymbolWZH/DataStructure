#define _CRT_SECURE_NO_WARNINGS
//栈和队列属于线性表->有n个元素构成的集合，逻辑结构呈现线性
//顺序表 链表 栈 队列 串(字符串)
/*
栈：一种特殊的线性表，其只允许在固定的一端进行插入和删除元素操作。进行数据插入和删除操作的一端
称为栈顶，另一端称为栈底。栈中的数据元素遵守后进先出LIFO（Last In First Out）的原则。*/
#include "stack.h"


/*初始化*/
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDataType)*4);
	pst->_capacity = 4;
	pst->_top = 0;
}
/*销毁*/
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_capacity = pst->_top = 0;
}
/*入栈*/
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//先判断内存够不够
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			printf("内存不足\n");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}
/*出栈*/
void StackPop(Stack* pst)
{
	assert(pst && pst->_top > 0);
	--pst->_top;
}
/*计算大小*/
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
/*返回1是空  ， 返回0 是非空*/
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}
/*获取栈顶的数据*/
STDataType StackTop(Stack* pst)
{
	assert(pst && pst->_top > 0);
	return pst->_a[pst->_top - 1];

}