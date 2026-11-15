// #include <stdio.h>

// int main()
// {
//     /*
//         需求：分类平均
//         题目描述：
//         给定 n 和 k，将从 1 到 n 之间的所有正整数可以分为两类：
//         A 类数可以被 k 整除（也就是说是 k 的倍数），而 B 类数不能。
//         请输出这两类数的平均数，精确到小数点后 1 位，用空格隔开。

//         数据保证两类数的个数都不会是 0。

//         输入格式：
//         输入两个正整数 n 与 k。

//         输出格式：
//         输出一行，两个实数，分别表示 A 类数与 B 类数的平均数。精确到小数点后一位。

//         说明/提示：
//         数据保证，1≤n≤10000，1≤k≤100。
//     */
//     int n, k;
//     scanf("%d %d",&n,&k);

//     int sumA = 0, countA = 0;
//     int sumB = 0, countB = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (i % k == 0)
//         {
//             sumA += i;
//             countA++;
//         }
//         else
//         {
//             sumB += i;
//             countB++;
//         }
//     }
//     double averageA = (double)sumA / countA;
//     double averageB = (double)sumB / countB;

//     printf("%.1lf %.1lf",averageA,averageB);

//     return 0;
// }