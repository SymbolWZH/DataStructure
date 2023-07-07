#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <assert.h>
typedef int STDataType;
typedef struct 
{
	STDataType* _a;
	int _top; //栈顶下标
	int _capacity;
}Stack;
/*初始化*/
void StackInit(Stack* pst);
/*销毁*/
void StackDestory(Stack* pst);
/*入栈*/
void StackPush(Stack* pst,STDataType x);
/*出栈*/
void StackPop(Stack* pst);
/*计算大小*/
int StackSize(Stack* pst);
/*返回1是空  ， 返回0 是非空*/
int StackEmpty(Stack* pst);
/*获取栈顶的数据*/
STDataType StackTop(Stack* pst);
