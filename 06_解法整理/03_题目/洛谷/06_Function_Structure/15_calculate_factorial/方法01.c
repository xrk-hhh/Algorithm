// 原始稿：03_题目/洛谷/06_Function_Structure/15_calculate_factorial.c
// 原文行号：1-25；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

long long fac(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else
    {
        long long tmp = x * fac(x - 1);
        return tmp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    long long ans = fac(n);
    printf("%lld", ans);

    return 0;
}
