// 原始稿：03_题目/洛谷/Algorithm/01_Simulation_and_High_Precision/06_factorial_digits.c
// 原文行号：51-112；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

#define N 1010
#define MAX 2580

int fact[N][10];
int res[MAX];
int len;

void init()
{
    res[0] = 1;
    len = 1;
    fact[0][1] = 1;

    for (int i = 1; i <= 1000; i++)
    {
        int carry = 0;
        for (int j = 0; j < len; j++)
        {
            int tmp = res[j] * i + carry;
            res[j] = tmp % 10;
            carry = tmp / 10;
        }
        while (carry)
        {
            res[len] = carry % 10;
            carry /= 10;
            len++;
        }

        int cnt[10] = {0};
        for (int j = 0; j < len; j++)
        {
            cnt[res[j]]++;
        }

        for (int j = 0; j < 10; j++)
        {
            fact[i][j] = cnt[j];
        }

    }
}

int main()
{
    init();

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, a;
        scanf("%d %d", &n, &a);

        printf("%d\n", fact[n][a]);
    }

    return 0;
}
