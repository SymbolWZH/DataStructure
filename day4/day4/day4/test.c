#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

/*
实际中链表的结构非常多样，以下情况组合起来就有3种链表结构:
1.单向、双向
2.带头、不带头
3.循环、非循环
链表和顺序表(数组)的区别和联系:
1、顺序表就是在数组的基础上实现增删查改，并且插入时可以动态增长
顺序表缺陷:
a、可能存在一定空间浪费
b、增容有一些效率损失
c、中间或者头部插入删除，时间复杂度为0(N)，因为要挪动数据
这些问题谁来解决了，链表。
链表的缺陷：不能随机访问
*/

void TestList1()
{
	/*ListNode* List = NULL;
	ListInit(&List);*/

	ListNode* phead = ListInit();
	ListPushBack(phead,1);
	ListPushBack(phead,2);
	ListPushBack(phead, 3);
	ListPrint(phead);
}
void TestList2()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 21);
	ListPushBack(phead, 31);
	ListPrint(phead);

	ListNode* pos = ListFind(phead,3);
	ListInsert(pos, 30);
	ListPrint(phead);
}
int main()
{
	
	TestList1();
	return 0;
}