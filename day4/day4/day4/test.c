#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

/*
ʵ��������Ľṹ�ǳ�������������������������3������ṹ:
1.����˫��
2.��ͷ������ͷ
3.ѭ������ѭ��
�����˳���(����)���������ϵ:
1��˳������������Ļ�����ʵ����ɾ��ģ����Ҳ���ʱ���Զ�̬����
˳���ȱ��:
a�����ܴ���һ���ռ��˷�
b��������һЩЧ����ʧ
c���м����ͷ������ɾ����ʱ�临�Ӷ�Ϊ0(N)����ΪҪŲ������
��Щ����˭������ˣ�����
�����ȱ�ݣ������������
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