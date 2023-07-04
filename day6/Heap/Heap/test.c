#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"


void HeapSort(int* a, int n)
{
	//1. ����
	/*ʱ�临�Ӷ�
	��������N���ڵ㣬���߶� �� logN
	ʱ�临�Ӷ�ΪO(N)*/
	for (int i =( n- 1 -1) / 2 ; i >= 0 ; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}

}
int main()
{
	int array[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(array, sizeof(array) / sizeof(HPDataType));
	
	//Heap* hp;
	//HeapInit(&hp, array, sizeof(array) / sizeof(HPDataType));

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}