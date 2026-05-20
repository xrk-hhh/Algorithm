// #include <stdio.h>

// int main()
// {
//     /*
//         需求：打分
//         题目描述：
//         现在有 n(n≤1000) 位评委给选手打分，分值从 0 到 10。
//         需要去掉一个最高分，去掉一个最低分（如果有多个最高或者最低分，也只需要去掉一个），剩下的评分的平均数就是这位选手的得分。
//         现在输入评委人数和他们的打分，请输出选手的最后得分，精确到 2 位小数。

//         输入格式：
//         第一行输入一个正整数 n，表示有 n 个评委。

//         第二行输入 n 个正整数，第 i 个正整数表示第 i 个评委打出的分值。

//         输出格式：
//         输出一行一个两位小数，表示选手的最后得分。

//         说明/提示：
//         数据保证，3≤n≤1000，每个评委打出的分值为为 0 到 10（含 0 与 10）之间的整数。
//     */

//     int n;
//     scanf("%d",&n);

//     // // 方法一：设置数组
//     // int arr[n];
//     // double sum = 0.00;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     scanf("%d",&arr[i]);
//     //     sum += arr[i];
//     // }
//     // int min = arr[0];
//     // int max = arr[0];
//     // for (int i = 1; i < n; i++)
//     // {
//     //     if (arr[i] < min)
//     //     {
//     //         min = arr[i];
//     //     }
//     //     if (arr[i] > max)
//     //     {
//     //         max = arr[i];
//     //     }
//     // }

//     // 方法二：不设置数组
//     int min = 11;
//     int max = -1;
//     double sum = 0.00;
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
//         sum += temp;
//     }
//     double score;
//     score = (sum - min - max) / (n - 2);
//     printf("%.2lf",score);
//     return 0;
// }