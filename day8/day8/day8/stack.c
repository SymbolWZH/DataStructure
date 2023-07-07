#define _CRT_SECURE_NO_WARNINGS
//ջ�Ͷ����������Ա�->��n��Ԫ�ع��ɵļ��ϣ��߼��ṹ��������
//˳��� ���� ջ ���� ��(�ַ���)
/*
ջ��һ����������Ա���ֻ�����ڹ̶���һ�˽��в����ɾ��Ԫ�ز������������ݲ����ɾ��������һ��
��Ϊջ������һ�˳�Ϊջ�ס�ջ�е�����Ԫ�����غ���ȳ�LIFO��Last In First Out����ԭ��*/
#include "stack.h"


/*��ʼ��*/
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDataType)*4);
	pst->_capacity = 4;
	pst->_top = 0;
}
/*����*/
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_capacity = pst->_top = 0;
}
/*��ջ*/
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//���ж��ڴ湻����
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			printf("�ڴ治��\n");
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
/*��ջ*/
void StackPop(Stack* pst)
{
	assert(pst && pst->_top > 0);
	--pst->_top;
}
/*�����С*/
int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}
/*����1�ǿ�  �� ����0 �Ƿǿ�*/
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
}
/*��ȡջ��������*/
STDataType StackTop(Stack* pst)
{
	assert(pst && pst->_top > 0);
	return pst->_a[pst->_top - 1];

}