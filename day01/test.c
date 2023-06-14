#include <stdio.h>
#include <stdlib.h>
//数据结构：在内存中存储数据
// 请计算一下Func基本操作执行了多少次?
// void Func1(int N)
// {
//     int count = 0;
//     for (int i =0;i<N;++ i)
//     {
//         for (int j = 0; j <N ;++ j)
//         {
//             ++count;
//         }
//     }
//     for (int k = 0; k <2 * N ;++ k)
//     {
//         ++count;
//     }
//     int M = 10;
//     while(M--)
//     {
//     ++count;
//     }
//     printf("%d\n",count);
//     //时间复杂度 N^2 +2*N + 10
// }
// int main()
// {
//     Func1(10);
//     return 0;
// }
// 实际中我们计算时间复杂度时，我们其实并不一定要计算精确的执行次数，而只需要大概执行次数，那么这
// 里我们使用大O的渐进表示法。
// 大O符号(BigOnotation):是用于描述函数渐进行为的数学符号。
// 推导大O阶方法:
// 1、用常数1取代运行时间中的所有加法常数。
// 2、在修改后的运行次数函数中，只保留最高阶项。
// 3、如果最高阶项存在且不是1，则去除与这个项目相乘的常数。得到的结果就是大O阶。
// 使用大O的渐进表示法以后，Func1的时间复杂度为:
// O(N^2)

// long long * Fibonacci(size_t N)
// {
//     long long * fibArray = malloc(sizeof(long long)*(N+1));
//     fibArray[0] = 0;
//     fibArray[1] = 1;

//     for (int i = 2; i <= N; i++)
//     {
//        fibArray[i] = fibArray[i-1]+fibArray[i-2];
//     }
    
//     return fibArray;
// }

// 数组nums包含从0到n的所有整数，但其中缺了一个。
// 请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
// int missingNumber(int* nums, int numsSize){
//     int n=0;
//     for(int i=0;i<numsSize;i++)
//     {
//         n ^= nums[i];
//     }
//     for(int j=0;j<=numsSize;j++)
//     {
//          n ^= j;
//     }
//     return n;
// }
// 数据结构实际两种结构:
// 1、物理结构 (内存中如何存)
// 2、逻辑结构(是我们想象出来的)
// 线性表:
// 物理结构:数组、链表