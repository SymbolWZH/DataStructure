#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//保证有一次是小于一

		for (int  i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if ( tmp < a[end] )
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
	
	
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini, maxi;
		mini = maxi = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}
// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
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
void HeapSort(int* a, int n)
{
	//排升序，建大堆还是小堆
	for (int i = (n - 1 - 1) / 2 ; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}
// 冒泡排序
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				int exchange = 1;
			}
		}
		if (exchange == 0)
			break;

		--end;
	}
	
}
int GetMinIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
}

// 快速排序版本  
int PartSort(int* a, int begin, int end)
{
	int key = end;
	while (begin < end)
	{
		//begin找大
		if (begin < end && a[begin] <= key)
		{
			++begin;
		}
		//end找小
		if (begin < end && a[end] >= key)
		{
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]); 

	return begin;
}
//快排 时间复杂度 N*(logN) 空间复杂度 O(logN)
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;
	if ((right - left + 1) > 10)
	{
		int div = QuickSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1 , right);

	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}
//快排挖坑法
int QuickSort2(int* a, int begin, int end)
{
	int midIndex = GetMinIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	//坑
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			++begin;
			//begin找大
		a[end] = a[begin];
		{
			++begin;
		}
		//左边找到比key大的填到右边的坑,begin位置就形成的新的坑
		//end找小
		while (begin < end && a[end] >= key)
			--end;
		a[begin] = a[end];
		 
	}

	a[begin] = key;
	return begin;
}
// 快速排序前后指针法
int QuickSort3(int* a, int begin, int end)
{
	int prev = begin - 1;
	int cur = begin;
	int keyindex = end;
	while (cur < end)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		++cur;
	}
	Swap(&a[++prev], &a[keyindex]);

	return prev;
}
/*递归改非递归-- 1、改循环(斐波那契数列求解)一些简单递归才能改循环 2、栈模拟存储数据非递归
非递归 : 1、提高效率(递归建立栈帧还是有消耗的，但是对于现代的计算机，这个优化微乎其微可以忽略不计忽略不
	     2、递归最大缺陷是，如果栈帧的深度太深，可能会导致栈溢出。因为系统栈空间一般不大在M别
	      数据结构栈模拟非递归，数据是存储在堆上的，堆是G级别的空间*/
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		//[begin end]
		int div = QuickSort3(a, begin, end);

		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}

		if (begin  < div -1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}

	StackDestory(&st);
}
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	
	int mid = (left + right) / 2;

	
	//[left,mid] [mid+1,right] 有序则可以合并，现在他们没有序 子问题解决
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//归并 有序
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
			
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];

	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];

	}
	for (int i = left; i <=right; i++)
	{
		a[i] = tmp[i];
	}
}
// 归并排序递归实现 时间复杂的 O(N*logN) 空间：O(N)
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);

	_MergeSort(a, 0,n - 1, tmp);

	free(tmp);
}
void MergeArr(int* a, int begin1, int end1, int begin2, int end2,int * tmp)
{
	int left = begin1, right = end2;
	int index = begin1;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	int gap = 1;

	while (gap < n )
	{
		for (int i = 0; i < n;i+= 2*gap)
		{
			//[i,i+gap] [i+gap , i+2*gap]

			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// 1、合并时只有第一组,就不需要合并
			if (begin2 >= n)
				break;
			// 2、合并时第二组只有部分数据，需要修正end边界
			if(end2 >= n)
				end2= n-1;
			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	free(tmp);
}
void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* foutFile1 = fopen(file1, "r");
	if (foutFile1 == NULL)
	{
		printf("foutFile1打开文件失败\n");
	}
	FILE* foutFile2 = fopen(file2, "r");
	if (foutFile2 == NULL)
	{
		printf("foutFile2打开文件失败\n");
	}

	FILE* foutMfile = fopen(mfile, "w");
	if (foutMfile == NULL)
	{
		printf("foutMfile打开文件失败\n");
	}
	int num1, num2;
	int ret1 = fscanf(foutFile1, "%d\n", &num1);
	int ret2 = fscanf(foutFile2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(foutMfile, "%d\n", num1);
			ret1 = fscanf(foutFile1, "%d\n", &num1);
		}
		else
		{
			fprintf(foutMfile, "%d\n", num2);
			ret2 = fscanf(foutFile2, "%d\n", &num2);
		}
	}
	
	while (ret1 != EOF)
	{
		fprintf(foutMfile, "%d\n", num1);
		ret1 = fscanf(foutFile1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(foutMfile, "%d\n", num2);
		ret2 = fscanf(foutFile2, "%d\n", &num2);
	}
	fclose(foutFile1);
	fclose(foutFile2);
	fclose(foutMfile);

}
const char * MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("fout打开文件失败\n");
		exit(-1);
	}
	//分割成一段一段的数据，内存排序后存到小文件
	int n = 10;
	int* a[10];
	int i = 0;
	int num = 0;
	int filei = 1;
	const char subfile[50];

	while (fscanf(fout,"%d\n",&num) != EOF)
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);
			sprintf(subfile, "%d", filei++);
			FILE * fin = fopen(subfile,"w");
			if (fin == NULL)
			{
				printf("fin打开文件失败\n");
				exit(-1);
			}
			for (int i = 0; i < n; i++)
			{
				fprintf(fin,"%d\n", a[i]);
			}
			fclose(fin);
			i = 0;
			memset(a, 0, sizeof(int) * n);
			a[i++] = num;
		}
	}
	//利用互相归并到文件，
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";
	char AllFileName[100][50] = { "1" };
	int AllFileNameSize = 1;
	for (int i = 2; i < filei-1; i++)
	{
		sprintf(AllFileName[AllFileNameSize++], "%d", i);
		_MergeFile(file1, file2, mfile);
		sprintf(AllFileName[AllFileNameSize++],"%s", mfile);
		//第一次合并完成之后
		strcpy(file1, mfile);
		sprintf(file2, "%d", i+1);
		if(i + 1 == filei - 1)
			sprintf(AllFileName[AllFileNameSize++], "%s", file2);
		sprintf(mfile, "%s%d", mfile, i+1);

	}

	int length = 0;
	int ret;
	while (strcmp(AllFileName[length], "") != 0)
	{
		++length;
	}
	for (int i = 0; i < length -1; i++)
	{
		ret = remove(AllFileName[i]);
		if (ret == 0)
			printf("文件:%s  删除成功\n", AllFileName[i]);
		else
			printf("文件删除失败\n");
	}
	ret = rename(AllFileName[length-1],"mergeFile.txt");
	if (ret == 0)
		printf("文件重命名成功\n");
	else
		printf("文件重命名失败\n");
	ret = remove(AllFileName[length - 1]);
	if (ret == 0)
		printf("文件:%s  删除成功\n", AllFileName[i]);
	else
		printf("文件删除失败\n");
	fclose(fout); 
}
// 计数排序 时间复杂度O(N+range) 空间复杂度O(range) 只适用于整型
void CountSort(int* a, int n)
{
	int min, max;
	for (int i = 1; i < n; i++)
	{
		assert(a);
		max = a[0];
		min = a[0];
		if (min > a[i])
			min = a[i];
		
		if (max < a[i])
			max = a[i];
	}

	int range = max - min + 1;
	int* countArr =(int*)malloc(sizeof(int) * range);
	memset(countArr, 0, sizeof(int) * range);

	for (int i = 0; i < range; i++)
	{
		countArr[a[i]-min]++;
	}
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (countArr[j]--)
		{
			a[index++] = j + min;
		}
	}
	free(countArr);
}		

// 测试排序的性能对比