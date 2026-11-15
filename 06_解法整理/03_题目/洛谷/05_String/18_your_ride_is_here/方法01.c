// 原始稿：03_题目/洛谷/05_String/18_your_ride_is_here.c
// 原文行号：1-39；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

#define MOD 47

char g[10];
char h[10];

int main()
{
    scanf("%s", g);
    scanf("%s", h);

    int l_g = strlen(g);
    int l_h = strlen(h);

    int num_g = 1, num_h = 1;
    for (int i = 0; i < l_g; i++)
    {
        int num = g[i] - 'A' + 1;
        num_g = num_g * num % MOD;
    }
    for (int i = 0; i < l_h; i++)
    {
        int num = h[i] - 'A' + 1;
        num_h = num_h * num % MOD;
    }

    if (num_g == num_h)
    {
        printf("GO\n");
    }
    else
    {
        printf("STAY\n");
    }

    return 0;
}
