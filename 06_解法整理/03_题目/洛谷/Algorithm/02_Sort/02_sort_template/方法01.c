// 原始稿：03_题目/洛谷/Algorithm/02_Sort/02_sort_template.c
// 原文行号：1-34；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100010

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int a[MAXN];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    qsort(a, N, sizeof(int), cmp);

    printf("%d", a[0]);

    for (int i = 1; i < N; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}
