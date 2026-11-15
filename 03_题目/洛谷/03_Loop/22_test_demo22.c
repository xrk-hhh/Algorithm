// #include <stdio.h>

// int main()
// {
//     /*
//         需求：求极差 / 最大跨度值 / 最大值和最小值的差
//         题目描述：
//         给出 n 和 n 个整数 ai 求这 n 个整数中的极差是什么。
//         极差的意思是一组数中的最大值减去最小值的差。

//         输入格式：
//         第一行输入一个正整数 n，表示整数个数。

//         第二行输入 n 个整数 a1,a2,...,an，以空格隔开。

//         输出格式：
//         输出一个整数，表示这 n 个整数的极差。

//         说明/提示:
//         数据保证，1≤n≤100，0≤ai≤1000。
//     */

//     int n;
//     scanf("%d",&n);

//     // // 方法一：设置数组
//     // // 定义数组存储 ai
//     // int arr[n];
//     // for (int i = 0; i < n; i++)
//     // {
//     //     scanf("%d",&arr[i]);
//     // }
//     // // min：最小值
//     // int min = arr[0];
//     // // max：最大值
//     // int max = arr[0];
//     // // 前面已经初始化 min 和 max 为 arr[0] 了，故 i 从 1 到 n-1
//     // for (int i = 1; i < n; i++)
//     // {
//     //     if (arr[i] > max)
//     //     {
//     //         max = arr[i];
//     //     }
//     //     if (arr[i] < min)
//     //     {
//     //         min = arr[i];
//     //     }
//     // }

//     // 方法二：不设置数组
//     // 初始化最小值设置大点，最大值设置小点
//     int min = 1001, max = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int temp;
//         scanf("%d",&temp);
//         if (temp < min)
//         {
//             min = temp;
//         }
//         if (temp > max)
//         {
//             max = temp;
//         }
//     }
//     // 极差为 max - min
//     int range = max - min; 
//     printf("%d",range);
//     return 0;
// }