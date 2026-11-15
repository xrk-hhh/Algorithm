// 原始稿：03_题目/洛谷/06_Function_Structure/17_goldbach_conjecture.c
// 原文行号：78-115；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

int main() 
{
    int N;
    scanf("%d", &N);

    int max_num = N;
    int is_prime[max_num + 1];
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;

    for (int i = 2; i * i <= max_num; ++i) 
    {
        if (is_prime[i]) 
        {
            for (int j = i * i; j <= max_num; j += i) 
            {
                is_prime[j] = 0;
            }
        }
    }

    for (int x = 4; x <= N; x += 2) 
    {
        for (int p = 2; p <= x; ++p) 
        {
            if (is_prime[p] && is_prime[x - p]) 
            {
                printf("%d=%d+%d\n", x, p, x - p);
                break;
            }
        }
    }

    return 0;
}
