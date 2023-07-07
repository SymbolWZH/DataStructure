#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
// ����ʵ�ֵĽӿ�
// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);
// ��������ݹ�ʵ��
int PartSort(int* a, int begin, int end);
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
int QuickSort3(int* a, int begin, int end);
void QuickSortNonR(int* a, int left, int right);
void _MergeSort(int* a, int left, int right, int* tmp);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp);
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);
// ������������ܶԱ�
void Swap(int* p1, int* p2);

const char* MergeSortFile(const char* file);