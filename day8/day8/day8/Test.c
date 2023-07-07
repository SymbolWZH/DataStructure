#define _CRT_SECURE_NO_WARNINGS
/*ÅÅÐò*/

#include<time.h>   //ÓÃµ½clock()º¯Êý
#include "Sort.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestInert()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	InsertSort(array, sizeof(array) / sizeof(int));
	PrintArray(array, sizeof(array) / sizeof(int));
}

void TestShellSort()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	ShellSort(array, sizeof(array) / sizeof(int));
	PrintArray(array, sizeof(array) / sizeof(int));
}

void TestSelectSort()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	SelectSort(array, sizeof(array) / sizeof(int));
	PrintArray(array, sizeof(array) / sizeof(int));
}

void TestPartSort()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	PartSort(array,0, sizeof(array) / sizeof(int)-1);
	PrintArray(array, sizeof(array) / sizeof(int));
}
void TestQuickSortNonR()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	QuickSortNonR(array, 0, sizeof(array) / sizeof(int) - 1);
	PrintArray(array, sizeof(array) / sizeof(int));
}

void TestMergeSort()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	MergeSort(array,  sizeof(array) / sizeof(int) );
	PrintArray(array, sizeof(array) / sizeof(int));
}
void TestMergeSortNonR()
{
	int array[] = { 3,1,4,1,7,9,8,2,0,5,99,55,88,1,2,4,5,8,6,9,4,3,5,2,4,8,9,3,54,97,32,54,288,901 };
	MergeSortNonR(array, sizeof(array) / sizeof(int));
	PrintArray(array, sizeof(array) / sizeof(int));
}
int main()
{
	int begintime, endtime;
	/*begintime = clock();
	TestInert();
	endtime = clock();
	printf("TestInert time is %dms\n", endtime - begintime);
	
	begintime = clock();
	TestShellSort();
	endtime = clock();
	printf("TestShellSort time is %dms\n", endtime - begintime);


	begintime = clock();
	TestSelectSort();
	endtime = clock();
	printf("TestSelectSort time is %dms\n", endtime - begintime);

	begintime = clock();
	TestPartSort();
	endtime = clock();
	printf("TestPartSort time is %dms\n", endtime - begintime);


	begintime = clock();
	TestQuickSortNonR();
	endtime = clock();
	printf("TestQuickSortNonR time is %dms\n", endtime - begintime);*/
	
	/*begintime = clock();
	TestMergeSort();
	endtime = clock();
	printf("TestMergeSort time is %dms\n", endtime - begintime);*/

	/*begintime = clock();
	TestMergeSortNonR();
	endtime = clock();
	printf("TestMergeSortNonR time is %dms\n", endtime - begintime);*/

	MergeSortFile("sort.txt");
	return 0;
}