// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_N 100010

// // 快速排序（修复逻辑+三数取中优化）
// void quick_sort(int *a, int low, int high);
// // 三数取中法选基准（避免有序数组退化）
// int get_pivot(int *a, int low, int high);

// int main()
// {
//     /*
//         需求：【模板】排序
//         题目描述：
//         将读入的 N 个数从小到大排序后输出。

//         输入格式：
//         第一行为一个正整数 N。

//         第二行包含 N 个空格隔开的正整数 ai，为你需要进行排序的数。

//         输出格式：
//         将给定的 N 个数从小到大输出，数之间空格隔开，行末换行且无空格。

//         说明/提示：
//         对于 20% 的数据，有 1≤N≤10^3；

//         对于 100% 的数据，有 1≤N≤10^5，1≤ai≤10^9。
//     */

//     int N;
//     scanf("%d", &N);

//     // 全局数组避免栈溢出（局部数组1e5个int约400KB，也可，但全局更安全）
//     static int a[MAX_N];
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d", &a[i]);
//     }

//     quick_sort(a, 0, N - 1);

//     for (int i = 0; i < N; i++)
//     {
//         if (i > 0)
//         {
//             printf(" ");
//         }
//         printf("%d", a[i]);
//     }
//     printf("\n");

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