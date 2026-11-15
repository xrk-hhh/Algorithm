// // #include <stdio.h>
// // #include <stdlib.h>

// // #define MAXN 5000010

// // int cmp(const void* a, const void* b)
// // {
// //     return *(int*)a - *(int*)b;
// // }

// // int num[MAXN];

// // int main()
// // {
// //     int n, k;
// //     scanf("%d %d", &n, &k);

// //     for (int i = 0; i < n; i++)
// //     {
// //         scanf("%d", &num[i]);
// //     }

// //     qsort(num, n, sizeof(int), cmp);

// //     printf("%d\n", num[k]);

// //     return 0;
// // }


// // 以上为快排暴力解决
// // 本题只需找到第k小的数，无需对整个数组排序
// // 故可考虑使用 快速选择
// /*
//     快速选择基于快速排序的分治逻辑，但无需排序整个数组：
//     选基准：随机选择一个元素作为基准（避免最坏情况）。
//     分区：将数组分为两部分，左半部分≤基准，右半部分≥基准，得到基准的最终位置p。
//     分治缩小范围：
//     若p == k：基准就是第 k 小数，直接返回。
//     若p > k：第 k 小数在左半部分，递归 / 循环处理左区间。
//     若p < k：第 k 小数在右半部分，递归 / 循环处理右区间。
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// // 交换两个int类型的元素
// void swap(int *x, int *y) 
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// // 快速选择算法（非递归实现，避免大n时栈溢出）
// int quick_select(int *a, int l, int r, int k) 
// {
//     while (l < r) 
//     {
//         // 随机选基准（避免最坏情况，如数组有序）
//         int rand_idx = l + rand() % (r - l + 1);
//         swap(&a[rand_idx], &a[r]); // 基准移到区间末尾，方便分区
//         int pivot = a[r];

//         // 分区：将<=pivot的元素移到左半部分，返回基准的最终位置p
//         int i = l;
//         for (int j = l; j < r; j++) 
//         {
//             if (a[j] <= pivot) 
//             {
//                 swap(&a[i], &a[j]);
//                 i++;
//             }
//         }
//         swap(&a[i], &a[r]); // 基准移到最终位置
//         int p = i;

//         // 根据p和k的关系缩小范围
//         if (p == k) 
//         {
//             return a[p];
//         } 
//         else if (p > k) 
//         {
//             r = p - 1;
//         } 
//         else 
//         {
//             l = p + 1;
//         }
//     }
//     return a[l]; // 当l==r时，该元素就是第k小数
// }

// int main() 
// {
//     srand((unsigned int)time(NULL)); // 初始化随机数种子，保证基准随机

//     int n, k;
//     scanf("%d %d", &n, &k);

//     // 分配数组（n最大5e5，堆内存足够）
//     int *a = (int*)malloc(n * sizeof(int));
//     for (int i = 0; i < n; i++) 
//     {
//         scanf("%d", &a[i]);
//     }

//     // 调用快速选择，找第k小数
//     int result = quick_select(a, 0, n - 1, k);
//     printf("%d\n", result);

//     free(a); // 释放内存，避免泄漏
//     return 0;
// }