// #include <stdio.h>
// // 包含abs函数（计算绝对值）
// #include <stdlib.h>

// int main()
// {
//     /*
//         需求：旗鼓相当的对手
//         题目描述：
//         现有 N 名同学参加了期末考试，并且获得了每名同学的信息：语文、数学、英语成绩（均为不超过 150 的自然数）。
//         如果某对学生 ⟨i,j⟩ 的每一科成绩的分差都不大于 5，且总分分差不大于 10，那么这对学生就是“旗鼓相当的对手”。
//         现在想知道这些同学中，有几对“旗鼓相当的对手”？同样一个人可能会和其他好几名同学结对。

//         输入格式：
//         第一行一个正整数 N。

//         接下来 N 行，每行三个整数，其中第 i 行表示第 i 名同学的语文、数学、英语成绩。最先读入的同学编号为 1。

//         输出格式：
//         输出一个整数，表示“旗鼓相当的对手”的对数。

//         说明/提示：
//         数据保证，2≤N≤1000 且每科成绩为不超过 150 的自然数。
//     */

//     int N;
//     scanf("%d",&N);

//     int Chinese[N];
//     int Math[N];
//     int English[N];
//     int total[N];
//     // 存储每位同学的三科成绩和总分
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d %d %d",&Chinese[i],&Math[i],&English[i]);
//         total[i] = Chinese[i] + Math[i] + English[i];
//     }
//     // 记录符合条件的对数
//     int count = 0;
//     // 外层循环：第i位同学
//     for (int i = 0; i < N; i++)
//     {
//         // 内层循环：只判断i之后的同学（j > i），避免重复计数
//         for (int j = i + 1; j < N; j++)
//         {
//             // 计算三科分差的绝对值和总分分差的绝对值
//             int C_diff = abs(Chinese[i] - Chinese[j]);
//             int M_diff = abs(Math[i] - Math[j]);
//             int E_diff = abs(English[i] - English[j]);
//             int t_diff = abs(total[i] - total[j]);

//             // 判断是否符合“旗鼓相当”的条件
//             if (C_diff <= 5 && M_diff <=5 && E_diff <=5 && t_diff <=10) 
//             {
//                 count++;
//             }
//         }
//     }

//     printf("%d",count);
//     return 0;
// }