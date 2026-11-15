// 原始稿：03_题目/洛谷/06_Function_Structure/16_monkey_eat_peaches.c
// 原文行号：1-19；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    else
    {
        long long ans = (3LL << (n - 1)) - 2;
        printf("%lld\n", ans);
        return 0;
    }
}
