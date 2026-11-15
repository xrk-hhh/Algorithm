// 原始稿：03_题目/洛谷/Algorithm/04_Recursion_and_Recurrence/01_counting_stairs.c
// 原文行号：1-37；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>

long long cnt(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 3;
    }
    else
    {
        return cnt(n - 1) + cnt(n - 2);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    long long ans = cnt(N);
    printf("%d\n", ans);

    return 0;
}

// 以上为纯递归方法，当N太大时，将会超时

// 以下使用动态规划dp
