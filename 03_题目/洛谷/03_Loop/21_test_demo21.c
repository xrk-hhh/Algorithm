// // #include <stdio.h>
// // #include <math.h>

// // int main()
// // {
// //     /*
// //         需求：月落乌啼算钱（斐波那契数列）
// //         题目背景：
// //         （本道题目木有隐藏歌曲……不用猜了……）

// //         《爱与愁的故事第一弹·heartache》最终章。

// //         吃完 pizza，月落乌啼知道超出自己的预算了。为了不在爱与愁大神面前献丑，只好还是硬着头皮去算钱……

// //         题目描述：
// //         算完钱后，月落乌啼想着：“你坑我！”于是当爱与愁大神问多少钱时，月落乌啼说了一堆乱码。
// //         爱与愁大神说：“算了算了，我只问第 n 样菜价格多少？”
// //         月落乌啼写出了：
// //         Fn = ( ( (1 + sqrt5) / 2 ) ^ n -( (1 - sqrt5) / 2 ) ^ n ) / sqrt5   
// //         由于爱与愁大神学过编程，于是就用 1 分钟的时间求出了 Fn 的结果。月落乌啼为此大吃一惊。你能学学爱与愁大神求出 Fn 的值吗？

// //         输入格式：
// //         一行一个自然数 n。

// //         输出格式：
// //         只有 1 行一个实数 Fn ，保留两位小数。

// //         说明/提示：
// //         对于所有数据：0≤n≤48。

// //     */

// //     // 方法一：直接模拟（也可用pow）
// //     int n;
// //     scanf("%d",&n);

// //     double Fn;
// //     double product1 = 1.00, product2 = 1.00;
// //     for (int i = 0; i < n; i++)
// //     {
// //         product1 *= ( 1 + sqrt(5) ) / 2.00;
// //         product2 *= ( 1 - sqrt(5) ) / 2.00;
// //     }
// //     Fn = (product1 - product2) / sqrt(5);
// //     printf("%.2lf",Fn);

// //     return 0;
// // }

// // 方法二：记忆化递归（可处理较大n）
// #include <stdio.h>
// #include <stdlib.h>

// long long* memo;  // 动态数组指针

// // 初始化记忆化数组
// void init_memo(int n) 
// {
//     memo = (long long*)calloc(n + 1, sizeof(long long));
//     for (int i = 0; i <= n; i++) 
//     {
//         memo[i] = -1;
//     }
// }

// // 记忆化递归计算斐波那契数
// long long fib_memo(int n) 
// {
//     if (n <= 1) 
//     {
//         return n;
//     }
//     if (memo[n] != -1) 
//     {
//         return memo[n];
//     }
//     memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
//     return memo[n];
// }

// int main() 
// {
//     int n;
//     printf("请输入斐波那契数列的项数 n：");
//     scanf("%d", &n);

//     init_memo(n);  // 动态初始化数组
//     long long result = fib_memo(n);
//     printf("斐波那契数列第 %d 项为：%lld\n", n, result);

//     free(memo);  // 释放动态内存

//     return 0;
// }