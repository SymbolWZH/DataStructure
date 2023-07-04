#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <assert.h>
//С��
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;

}Heap;
void Swap(HPDataType* p1, HPDataType* p2);
/*������������С��*/
void AdjustDown(HPDataType* a, int n,int root);
/*���ϵ���*/
void AdjustUp(HPDataType* a, int n, int root);
/*��ʼ��*/
void HeapInit(Heap* php ,HPDataType * a , int n);
/*����*/
void HeapDestory(Heap* php);
/*���*/
void HeapPush(Heap* php,HPDataType x);
/*ɾ��*/
void HeapPop(Heap* php,HPDataType x);
/*�Ѷ�*/
HPDataType HeapTop(Heap* php);
