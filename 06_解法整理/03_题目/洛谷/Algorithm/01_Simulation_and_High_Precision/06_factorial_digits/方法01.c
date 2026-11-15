// 原始稿：03_题目/洛谷/Algorithm/01_Simulation_and_High_Precision/06_factorial_digits.c
// 原文行号：1-50；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>
#define MAX 2580

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, a;
        scanf("%d %d", &n, &a);

        int res[MAX] = {0};
        res[0] = 1;
        int res_len = 1;

        for (int i = 2; i <= n; i++)
        {
            int carry = 0;
            for (int j = 0; j < res_len; j++)
            {
                int product = res[j] * i + carry;
                res[j] = product % 10;
                carry = product / 10;
            }
            while (carry > 0)
            {
                res[res_len] = carry % 10;
                carry /= 10;
                res_len++;
            }
        }
        int cnt = 0;
        for (int i = res_len - 1; i >= 0; i--)
        {
            if (res[i] == a)
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}

// 以上方法为每一次循环计算n的阶乘

// 以下为预处理计算0到1000的阶乘
