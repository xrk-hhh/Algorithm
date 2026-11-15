// 原始稿：03_题目/洛谷/Algorithm/02_Sort/04_find_the_k_th_smallest_number.c
// 原文行号：1-43；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

#define MAXN 5000010

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int num[MAXN];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    qsort(num, n, sizeof(int), cmp);

    printf("%d\n", num[k]);

    return 0;
}


// 以上为快排暴力解决
// 本题只需找到第k小的数，无需对整个数组排序
// 故可考虑使用 快速选择
// /*
//     快速选择基于快速排序的分治逻辑，但无需排序整个数组：
//     选基准：随机选择一个元素作为基准（避免最坏情况）。
//     分区：将数组分为两部分，左半部分≤基准，右半部分≥基准，得到基准的最终位置p。
//     分治缩小范围：
//     若p == k：基准就是第 k 小数，直接返回。
//     若p > k：第 k 小数在左半部分，递归 / 循环处理左区间。
//     若p < k：第 k 小数在右半部分，递归 / 循环处理右区间。
// */
