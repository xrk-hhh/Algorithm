// 原始稿：03_题目/洛谷/Algorithm/02_Sort/03_mingming_s_random_number.c
// 原文行号：1-52；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

#define MAXN 110

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int unique(int* a, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[cnt - 1])
        {
            a[cnt++] = a[i];
        }
    }
    return cnt;
}

int num[MAXN];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    qsort(num, N, sizeof(int), cmp);

    int M = unique(num, N);

    printf("%d\n", M);
    printf("%d", num[0]);
    for (int i = 1; i < M; i++)
    {
        printf(" %d", num[i]);
    }

    return 0;
}
