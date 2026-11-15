// 原始稿：03_题目/洛谷/04_Array/17_turn_on_the_light.c
// 原文行号：1-42；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

#define N 2000010

int flag[N];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        double a;
        int t;
        scanf("%lf %d", &a, &t);
        
        long long a_int = (long long)(a * 1000000 + 1e-8);

        for (int k = 1; k <= t; k++)
        {
            long long l = (k * a_int) / 1000000;
            if (flag[l] == 1)
            {
                flag[l] = 0;
            }
            else
            {
                flag[l] = 1;
            }
        }
    }
    
    for (int i = 1; i < N; i++)
    {
        if (flag[i] == 1)
        {
            printf("%d", i);
            return 0;
        }
    }
}
