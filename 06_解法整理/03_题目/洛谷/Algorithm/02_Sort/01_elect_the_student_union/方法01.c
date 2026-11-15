// 原始稿：03_题目/洛谷/Algorithm/02_Sort/01_elect_the_student_union.c
// 原文行号：1-39；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

#define M 2000010

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int ballot[M];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &ballot[i]);
    }

    qsort(ballot, m, sizeof(int), cmp);

    printf("%d", ballot[0]);
    for (int i = 1; i < m; i++)
    {
        printf(" %d", ballot[i]);
    }

    printf("\n");

    return 0;
}

// 以上为快排，时间复杂度为 nlogn

// 考虑本题需排序数据均为非负整数，且值域小（1~999），故可考虑计数排序
