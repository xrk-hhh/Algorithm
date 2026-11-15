// 原始稿：03_题目/洛谷/06_Function_Structure/20_set_sum.c
// 原文行号：1-23；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

#define ll long long

int s[40];

int main()
{
    ll sum = 0;
    int k = 0;
    while (scanf("%d", &s[k]) != EOF)
    {
        sum += s[k];
        k++;
    }

    ll pow = 1LL << (k - 1);
    ll res = sum * pow;

    printf("%lld\n", res);

    return 0;
}
