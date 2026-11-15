// #include <stdio.h>
// #include <stdlib.h>

// // 手动实现max（避免部分编译器不兼容math.h的情况）
// long long max(long long a, long long b) 
// {
//     return a > b ? a : b;
// }

// int main()
// {
//     /*
//         需求：1024程序员节发橙子
//         题目描述：
//         每年的 1024 程序员节日，黑马程序员都会举办大型的庆祝活动。
//         今年的程序员节也不例外，每个班级的同学都发了橙子。

//         班级里有 n 名同学从前到后排成一排，且已经得知了这些同学的成绩，其中第 i 名同学的成绩是 ai。
//         班主任想根据同学们上个阶段的考试成绩来评定发橙子的数量。
//         为了激励成绩优秀同学，发橙子时需要满足如下要求：

//         1.相邻同学中成绩好的同学的橙子必须更多。
//         2.若相邻的同学成绩一样，则它们分到的数量必须平等。
//         3.每个同学至少分配一个橙子
//         4.由于预算有限，班主任希望在符合要求的情况下发出尽可能少的橙子。
//         请问，至少需要准备多少橙子呢？

//         输入格式：
//         第一行是一个整数 n，表示学生数量。

//         接下来一行有 n 个整数，第 i 个整数 ai，表示第 i 个同学的成绩。

//         输出格式：
//         输出答案，也就是需要最少准备多少个橙子。

//         说明/提示：
//         数据规模与约定
//         对于全部的测试点，保证 1≤n≤10^6，0≤ai≤10^9。
    
//     */

//     int n;
//     scanf("%d", &n);
//     // // 第一步：读取n（此时终端会等待输入，需确保VS Code用集成终端）
//     // if (scanf("%d", &n) != 1) 
//     // {
//     //     return 1;  // 输入错误处理
//     // }

//     // 动态分配成绩数组（替代变长数组，兼容所有编译器）
//     int *score = (int *)malloc(n * sizeof(int));
//     // if (score == NULL) 
//     // {
//     //     printf("内存分配失败\n");
//     //     return 1;
//     // }

//     // 读取n个成绩
//     for (int i = 0; i < n; i++) 
//     {
//         scanf("%d", &score[i]);
//     }

//     // 动态分配橙子数组（初始化为1，每个同学至少1个）
//     long long *orange = (long long *)malloc(n * sizeof(long long));
//     // if (orange == NULL) 
//     // {
//     //     printf("内存分配失败\n");
//     //     free(score);  // 释放已分配的内存
//     //     return 1;
//     // }
//     for (int i = 0; i < n; i++) 
//     {
//         orange[i] = 1;
//     }

//     // 第二步：左→右遍历，保证右边比左边成绩高时橙子更多、成绩相同则相等
//     for (int i = 1; i < n; i++) 
//     {
//         if (score[i] > score[i-1]) 
//         {
//             orange[i] = orange[i-1] + 1;
//         } 
//         else if (score[i] == score[i-1]) 
//         {
//             orange[i] = orange[i-1];  // 成绩相同，橙子数相等
//         }
//         // 成绩更低时，保持初始值1，后续右→左遍历调整
//     }

//     // 第三步：右→左遍历，保证左边比右边成绩高时橙子更多、成绩相同则相等
//     for (int i = n-2; i >= 0; i--) 
//     {
//         if (score[i] > score[i+1]) 
//         {
//             orange[i] = max(orange[i], orange[i+1] + 1);
//         } 
//         else if (score[i] == score[i+1]) 
//         {
//             orange[i] = max(orange[i], orange[i+1]);  // 成绩相同，橙子数相等
//         }
//     }

//     // 第四步：计算总橙子数
//     long long total = 0;
//     for (int i = 0; i < n; i++) 
//     {
//         total += orange[i];
//     }

//     // 输出结果（long long用%lld）
//     printf("%lld\n", total);

//     // 释放动态内存（避免内存泄漏）
//     free(score);
//     free(orange);
//     return 0;
// }
