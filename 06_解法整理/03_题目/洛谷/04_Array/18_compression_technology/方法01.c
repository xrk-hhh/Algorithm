// 原始稿：03_题目/洛谷/04_Array/18_compression_technology.c
// 原文行号：1-45；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

#define MAXN 40010

char str[MAXN];

int main()
{
    int N;
    int num;
    int idx = 0;
    for (int i = 0; scanf("%d", &num) != EOF; i++)
    {
        if (i == 0)
        {
            N = num;
            continue;
        }
        if ((i & 1) == 1)
        {
            for (int j = 0; j < num; j++)
            {
                str[idx++] = '0';
            }
        }
        else
        {
            for (int j = 0; j < num; j++)
            {
                str[idx++] = '1';
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", str[i * N + j]);
        }
        printf("\n");
    }

    return 0;
}
