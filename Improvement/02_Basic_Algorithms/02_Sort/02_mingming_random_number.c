// #include <stdio.h>

// int get_pivot(int *a, int low, int high);
// void quick_sort(int *a, int low, int high);
// int unique(int *a, int n);

// int main()
// {
//     /*
//         需求：明明的随机数
//         题目描述：
//         明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了 N 个 1 到 1000 之间的随机整数 (N≤100)，
//         对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。
//         然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
//         请你协助明明完成“去重”与“排序”的工作。

//         输入格式：
//         输入有两行
//         第 1 行为 1 个正整数，表示所生成的随机数的个数 N。
//         第 2 行有 N 个用空格隔开的正整数，为所产生的随机数。

//         输出格式：
//         输出也是两行
//         第 1 行为 1 个正整数 M，表示不相同的随机数的个数。
//         第 2 行为 M 个用空格隔开的正整数，为从小到大排好序的不相同的随机数。
//     */

//     int N;
//     scanf("%d", &N);

//     int num[105];
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d", &num[i]);
//     }

//     // 1. 排序（重复元素连续）
//     quick_sort(num, 0, N - 1);
//     // 2. 去重
//     int cnt = unique(num, N);

//     printf("%d\n", cnt);

//     for (int i = 0; i < cnt; i++)
//     {
//         printf("%d", num[i]);
//         if (i != cnt - 1)
//         {
//             printf(" ");
//         }
//     }

//     return 0;
// }

// // 三数取中法：选low、mid、high中间值作为基准，交换到low位置
// int get_pivot(int *a, int low, int high)
// {
//     int mid = low + (high - low) / 2;
//     // 交换使得a[low] <= a[mid] <= a[high]
//     if (a[low] > a[mid])
//     {
//         int tmp = a[low];
//         a[low] = a[mid];
//         a[mid] = tmp;
//     }
//     if (a[low] > a[high])
//     {
//         int tmp = a[low];
//         a[low] = a[high];
//         a[high] = tmp;
//     }
//     if (a[mid] > a[high])
//     {
//         int tmp = a[mid];
//         a[mid] = a[high];
//         a[high] = tmp;
//     }
//     // 把中间值（mid）交换到low位置，作为基准
//     int tmp = a[low];
//     a[low] = a[mid];
//     a[mid] = tmp;
//     return a[low];
// }

// void quick_sort(int *a, int low, int high)
// {
//     // 递归终止条件
//     if (low >= high)
//     {
//         return;
//     }

//     // 优化1：小范围用插入排序（减少递归调用）
//     if (high - low < 10)
//     {
//         for (int i = low + 1; i <= high; i++)
//         {
//             int tmp = a[i];
//             int j = i - 1;
//             while (j >= low && a[j] > tmp)
//             {
//                 a[j + 1] = a[j];
//                 j--;
//             }
//             a[j + 1] = tmp;
//         }
//         return;
//     }

//     // 优化2：三数取中选基准
//     int key = get_pivot(a, low, high);
//     int i = low, j = high;

//     // 正确的填坑逻辑
//     while (i < j)
//     {
//         // 从右找<=key的元素，填左边的坑
//         while (i < j && a[j] > key)
//         {
//             j--;
//         }
//         if (i < j)
//         { // 填坑，不立即自增
//             a[i] = a[j];
//             i++; // 填完后i右移
//         }

//         // 从左找>=key的元素，填右边的坑
//         while (i < j && a[i] < key)
//         {
//             i++;
//         }
//         if (i < j)
//         { // 填坑，不立即自减
//             a[j] = a[i];
//             j--; // 填完后j左移
//         }
//     }

//     // 基准值归位
//     a[i] = key;

//     // 递归处理左右子数组
//     quick_sort(a, low, i - 1);
//     quick_sort(a, i + 1, high);
// }
// // 有序数组去重，返回去重后的元素个数
// int unique(int *a, int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     int cnt = 1; // 至少有1个元素
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] != a[cnt - 1])
//         { // 与前一个不重复则保留
//             a[cnt++] = a[i];
//         }
//     }
//     return cnt;
// }