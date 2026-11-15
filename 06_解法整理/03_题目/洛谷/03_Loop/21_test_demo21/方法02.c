// 原始稿：03_题目/洛谷/03_Loop/21_test_demo21.c
// 原文行号：51-94；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

long long* memo;  // 动态数组指针

// 初始化记忆化数组
void init_memo(int n) 
{
    memo = (long long*)calloc(n + 1, sizeof(long long));
    for (int i = 0; i <= n; i++) 
    {
        memo[i] = -1;
    }
}

// 记忆化递归计算斐波那契数
long long fib_memo(int n) 
{
    if (n <= 1) 
    {
        return n;
    }
    if (memo[n] != -1) 
    {
        return memo[n];
    }
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}

int main() 
{
    int n;
    printf("请输入斐波那契数列的项数 n：");
    scanf("%d", &n);

    init_memo(n);  // 动态初始化数组
    long long result = fib_memo(n);
    printf("斐波那契数列第 %d 项为：%lld\n", n, result);

    free(memo);  // 释放动态内存

    return 0;
}
