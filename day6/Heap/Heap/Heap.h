#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <assert.h>
//小堆
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;

}Heap;
void Swap(HPDataType* p1, HPDataType* p2);
/*左右子树都是小堆*/
void AdjustDown(HPDataType* a, int n,int root);
/*向上调整*/
void AdjustUp(HPDataType* a, int n, int root);
/*初始化*/
void HeapInit(Heap* php ,HPDataType * a , int n);
/*销毁*/
void HeapDestory(Heap* php);
/*添加*/
void HeapPush(Heap* php,HPDataType x);
/*删除*/
void HeapPop(Heap* php,HPDataType x);
/*堆顶*/
HPDataType HeapTop(Heap* php);
