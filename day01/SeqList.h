#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"
//顺序表，有效数组在数组中必须是连续
//静态顺序表设计 
typedef int SLDataType;
#define N 10
// vector
typedef struct SeqList
{
     SLDataType * a;
     size_t size;    //有效数据的个数
     size_t capacity;//容量
}SL,SeqList;

/*
* 尾插尾删  头插头删
*/
void SeqListInit(SL*ps);
void SeqListDestory(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqlListPushBack(SL*ps,SLDataType x);
void SeqlListPopBack(SL*ps);
void SeqlListPushFront(SL*ps,SLDataType x);
void SeqlListPopFront(SL*ps);
//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
//查找
int SeqListFind(SL* ps, SLDataType x);
