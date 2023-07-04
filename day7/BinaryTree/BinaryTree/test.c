#define _CRT_SECURE_NO_WARNINGS
/*
��
	��ѣ��������и��״��ڵ��ں���
	С�ѣ��������и���С�ڵ��ں���
*/

#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;

/*ǰ�����*/
void PrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%c ", root->_data);
    PrevOrder(root->_left);
    PrevOrder(root->_right);
}
/*�������*/
void BinaryTreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    if (root == NULL)
        return;
    QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        printf("%c", front->_data);
        if (front->_left)
        {
            QueuePush(&q, front->_left);
        }
        if (front->_right)
        {
            QueuePush(&q, front->_right);
        }
    }
    QueueDestory(&q);
    printf("\n");

}
/*�������*/
void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    InOrder(root->_left);
    printf("%c ", root->_data);
    InOrder(root->_right);
}
/*�ж϶������Ƿ���ȫ������*/
//�Ƿ���1  ���Ƿ���0
int BinaryTreeComplete(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    if (root == NULL)
        return;
    QueuePush(&q, root);
    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        if (front == NULL)
            break;

        QueuePush(&q, root->_left);
        QueuePush(&q, root->_right);
    }

    while (!QueueEmpty(&q))
    {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);

        if (front)
        {
            QueueDestory(&q);
            return 0;
        }
    }
    return 1;

}
/*�������*/
void PostOrder(BTNode* root)
{
    if (root == NULL)
    {
        printf("NULL ");
        return;
    }
    PostOrder(root->_left);
    PostOrder(root->_right);
    printf("%c ", root->_data);
}
/*��Ҷ��������*/
int TreeDepth(BTNode* root)
{
    if (root == NULL)
        return 0;
    if (root->_left == NULL && root->_right == NULL)
        return 1;

    return  TreeLeafSize(root->_left) >= TreeLeafSize(root->_right) ? TreeLeafSize(root->_left)+1 : TreeLeafSize(root->_right)+1;
}
/*��Ҷ�ӽ�����*/
int TreeLeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    if (root->_left == NULL && root->_right == NULL)
        return 1;

    return  TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
/*��������k��ڵ����*/
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }

    return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
/*����������ֵΪx�Ľڵ�*/
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if (root == NULL)
        return NULL;
    if (root->_data == x)
        return root;

    BTNode* node = BinaryTreeFind(root->_left, x);
    if (node)
    {
        return node;
    }
    node = BinaryTreeFind(root->_right, x);
    if (node)
    {
        return node;
    }
    return node;
}

/*����*/
void DestoryTree(BTNode* root)
{
    if (root == NULL) 
        return;
    DestoryTree(root->_left);
    DestoryTree(root->_right);
    free(root);

}
/*������С*/
int TreeSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    else
        return 1+TreeSize(root->_left) + TreeSize(root->_right);
}
//void TreeSize(BTNode* root, int * psize)
//{
//    if (root == NULL)
//        return 0;
//    else
//        (*psize)++;
//
//    TreeSize(root->_left, psize);
//    TreeSize(root->_right, psize);
//
//}
BTNode* CreateNode(int x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    if (node == NULL)
        return NULL;
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;

    return node;
}
int main()
{
    BTNode* A = CreateNode('A');
    BTNode* B = CreateNode('B');
    BTNode* C = CreateNode('C');
    BTNode* D = CreateNode('D');
    BTNode* E = CreateNode('E');
    A->_left = B;
    A->_right = C;
    B->_left = D;
    B->_right = E;

    PrevOrder(A);
    printf("\n");
    InOrder(A);
    printf("\n");
    PostOrder(A);
    printf("\n");
 /*   int sizea = 0;
    TreeSize(A, &sizea);
    printf("TreeSize = %d\n", sizea);
    int sizeb = 0;
    TreeSize(B, &sizeb);
    printf("TreeSize = %d\n", sizeb);*/
    printf("TreeSize = %d\n", TreeSize(A));
    printf("TreeSize = %d\n", TreeSize(A));

    
    printf("TreeLeafSize = %d\n", TreeLeafSize(A));

    BinaryTreeLevelOrder(A);
    printf("TreeDepth = %d\n", TreeDepth(A));
    
    return 0;
}
