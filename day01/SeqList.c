#include "SeqList.h"


void SeqListInit(SL *ps)
{
	/*s.a = NULL;
	s.size = 0;
	s.capacity = 0;*/

	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}
void SeqlListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//如果满了需要增容
	/*SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
		
	}
	printf("\n");
}
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
	}
}
//尾删
void SeqlListPopBack(SL* ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0;
	ps->size--;
	SeqListErase(ps, ps->size-1);
}
//头插头删
void SeqlListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListInsert(ps, 0, x);
	/*SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;*/
}
void SeqlListPopFront(SL* ps)
{
	assert(ps);
	SeqListErase(ps,0);
	/*int start = 0;
	while (start < ps->size-1)
	{
		ps->a[start] = ps->a[start+1];
		++start;
	}
	ps->size--;*/
}
//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps && pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	int InsertNum = pos;
	int end = ps->size - 1;
	while (end >= InsertNum)
	{
		ps->a[end+1] = ps->a[end];
		--end;
	}

	ps->a[InsertNum] = x;
	ps->size++;
}
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListErase(SL* ps, int pos)
{
	assert(pos >= 0 && pos < ps->size);
	int end = ps->size - 1;

	while (pos<end)
	{
		ps->a[pos] = ps->a[pos + 1];
		++pos;
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		++i;
	}
	return -1;
}