#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
// 排序实现的接口
// 插入排序
void InsertSort(int* a, int n);
// 希尔排序
void ShellSort(int* a, int n);
// 选择排序
void SelectSort(int* a, int n);
// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n);
// 快速排序递归实现
int PartSort(int* a, int begin, int end);
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
int QuickSort3(int* a, int begin, int end);
void QuickSortNonR(int* a, int left, int right);
void _MergeSort(int* a, int left, int right, int* tmp);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp);
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);
// 测试排序的性能对比
void Swap(int* p1, int* p2);

const char* MergeSortFile(const char* file);