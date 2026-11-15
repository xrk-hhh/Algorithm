// 原始稿：03_题目/洛谷/Algorithm/04_Recursion_and_Recurrence/01_counting_stairs.c
// 原文行号：38-65；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>

#define MAXN 5010

long long dp[MAXN];

int main()
{
    int N;
    scanf("%d", &N);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("%lld\n", dp[N]);

    return 0;
}

// 以上代码无使用高精度，本题N最大为5000，long long只能存储64位，而此时结果约为1045位

// 以下为加上高精度的解法
