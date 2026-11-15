// #include <stdio.h>

// int main()
// {
//     /*
//         需求：评委打分
//         题目描述：
//         小 A 参加一个综艺节目。
//         一共有 n(3≤n≤10^6) 名评委参与打分（分数范围是 0 到 100 的整数），每个评委依次亮出自己的得分。

//         为了节目效果，要求从第三个评委开始，每当第 i 个评委给出打分后，立刻计算出出这个选手在前 i 名评委的打分中，
//         去掉一个最高分和一个最低分，剩下 i−2 个评委的平均分，保留 2 位小数。

//         输入格式：
//         第一行输入一个整数 n，表示评委人数。

//         第二行输出 n 个整数，表示各个评委的打分。

//         输出格式：
//         输出共 n−2 行，每行表示对应的答案。

//     */

//     int n;
//     scanf("%d",&n);

//     // 不需要数组存储
//     int judge_score;
//     // 最大值（最大值的最小值为0）
//     int max = 0;
//     // 最小值（最小值的最大值为100）
//     int min = 100;
//     // 初始化分数之和
//     double sum = 0.00;
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&judge_score);
//         sum += judge_score;
//         if (judge_score > max)
//         {
//             max = judge_score;
//         }
//         if (judge_score < min)
//         {
//             min = judge_score;
//         }
//         // 从第三位评委开始
//         if (i > 1)
//         {
//             double score = (sum - max - min) / (i - 1.0);
//             printf("%.2lf\n",score);
//         }
//     }

//     return 0;
// }