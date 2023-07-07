#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <assert.h>
typedef int STDataType;
typedef struct 
{
	STDataType* _a;
	int _top; //ջ���±�
	int _capacity;
}Stack;
/*��ʼ��*/
void StackInit(Stack* pst);
/*����*/
void StackDestory(Stack* pst);
/*��ջ*/
void StackPush(Stack* pst,STDataType x);
/*��ջ*/
void StackPop(Stack* pst);
/*�����С*/
int StackSize(Stack* pst);
/*����1�ǿ�  �� ����0 �Ƿǿ�*/
int StackEmpty(Stack* pst);
/*��ȡջ��������*/
STDataType StackTop(Stack* pst);
