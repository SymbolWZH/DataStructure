#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
/*左右子树都是小堆*/
void AdjustDown(HPDataType* a, int n,int root)
{
	 
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		// 找出左右孩子中小的哪一个
		if ( child +1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		//如果孩子小于父亲则交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
	
}
/*向上调整*/
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if ( a[child ] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
/*初始化*/
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->_a, a, sizeof(HPDataType) * n);
	php->_size = n;
	php->_capacity = n;
	//构建堆
	for (int i = (n-1-1) / 2 ; i>=0; --i)
	{
		AdjustDown(php->_a, php ->_size, i);
	}
}
/*销毁*/
void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
/*添加*/
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType));

		php->_a = tmp;
	}
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size,php->_size - 1);
}
/*删除*/
void HeapPop(Heap* php, HPDataType x)
{
	assert(php);
	assert(php->_size > 0);
	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
/*堆顶*/
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	return php->_a[0];
}