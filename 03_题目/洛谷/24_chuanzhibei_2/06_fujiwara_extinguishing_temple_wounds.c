// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// int main()
// {
//     /*
//         需求：藤原「灭罪寺院伤」
//         题目背景
//         藤原氏，权倾一时的重臣。凭借着炙手可热的权势，杀害了政敌长屋王而触碰到了最高的权力。

//         是天谴吗？即使修缮寺庙积德行善，藤原四兄弟最终覆灭在了天花之下。
        
//         题目描述
//         环环相扣的因果报应可看成平面上的 n 个小正方形，它们的边长分别为 1,2,3,⋯,n。初始时，编号较小的正方形被编号较大的正方形完全包含：

//         为了方便记录正方形的位置，我们取正方形左上角的坐标 (xi,yi) 为正方形的坐标。此时可以唯一确定该正方形。

//         现在需要将最小的正方形的位置移动到 (x end,y end)，移动过程满足：

//         每次最多移动一个正方形，可以往上下左右四个方向之一移动一个单位长度。
//         在移动过程中，需要保证较小正方形会被较大的正方形包含。
//         请求出最少次数。

//         输入格式
//         第一行有三个整数 n,x end,y end，含义如题面所示。

//         接下来 n 行，每行有两个整数 xi,yi，描述第 i 小的正方形左上角的坐标。

//         输出格式
//         输出共一行一个整数，表示最小的操作步数。

//         数据范围及约定
//         对于全部数据，1≤n≤10^5，0≤xi,yi,x end,y end≤10^9。
//     */

//     /*
//         对于正方形 k（边长 k）和 k-1（边长 k-1），k-1 被 k 包含的条件是：
//         k 的左边界 ≤ k-1 的左边界（x_k ≤ x_{k-1}）
//         k-1 的右边界 ≤ k 的右边界（x_{k-1} + (k-1) ≤ x_k + k → 简化为 x_k ≥ x_{k-1} - 1）
//         k 的下边界 ≤ k-1 的下边界（y_k - k ≤ y_{k-1} - (k-1) → 简化为 y_k ≤ y_{k-1} + 1）
//         k-1 的上边界 ≤ k 的上边界（y_{k-1} ≤ y_k）

//         综上，正方形 k 的最终位置需满足：
//         x_k ∈ [x_{k-1} - 1, x_{k-1}]
//         y_k ∈ [y_{k-1}, y_{k-1} + 1]

//     */

//     int n;
//     long long x_end, y_end;
//     // 读取n、目标坐标
//     scanf("%d %lld %lld", &n, &x_end, &y_end);

//     // 动态分配数组存储每个正方形的初始坐标（1-based索引）
//     long long *x = (long long *)malloc((n + 1) * sizeof(long long));
//     long long *y = (long long *)malloc((n + 1) * sizeof(long long));

//     // 读取每个正方形的初始坐标
//     for (int i = 1; i <= n; i++) 
//     {
//         scanf("%lld %lld", &x[i], &y[i]);
//     }

//     long long total_steps = 0;
//     long long prev_x = x_end;  // 前一个正方形（k-1）的最终x坐标
//     long long prev_y = y_end;  // 前一个正方形（k-1）的最终y坐标

//     // 处理最小正方形（k=1）的移动步数
//     total_steps += llabs(x[1] - prev_x) + llabs(y[1] - prev_y);

//     // 处理k=2到k=n的正方形
//     for (int i = 2; i <= n; i++) 
//     {
//         // 计算当前正方形的x范围：[prev_x-1, prev_x]
//         long long x_low = prev_x - 1;
//         long long x_high = prev_x;
//         long long x_final;
//         if (x[i] < x_low) 
//         {
//             x_final = x_low;
//         } 
//         else if (x[i] > x_high) 
//         {
//             x_final = x_high;
//         } 
//         else 
//         {
//             x_final = x[i];  // 初始位置在范围内，直接用初始值
//         }

//         // 计算当前正方形的y范围：[prev_y, prev_y+1]
//         long long y_low = prev_y;
//         long long y_high = prev_y + 1;
//         long long y_final;
//         if (y[i] < y_low) 
//         {
//             y_final = y_low;
//         } 
//         else if (y[i] > y_high) 
//         {
//             y_final = y_high;
//         } 
//         else 
//         {
//             y_final = y[i];  // 初始位置在范围内，直接用初始值
//         }

//         // 累加当前正方形的移动步数
//         total_steps += llabs(x[i] - x_final) + llabs(y[i] - y_final);

//         // 更新前一个正方形的坐标，供下一个正方形使用
//         prev_x = x_final;
//         prev_y = y_final;
//     }

//     // 输出总步数
//     printf("%lld\n", total_steps);

//     // 释放动态内存
//     free(x);
//     free(y);

//     return 0;
// }