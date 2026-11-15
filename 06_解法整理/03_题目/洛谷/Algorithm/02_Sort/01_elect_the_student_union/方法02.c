// 原始稿：03_题目/洛谷/Algorithm/02_Sort/01_elect_the_student_union.c
// 原文行号：40-67；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

#define N 1010

int cnt[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cnt[i]; j++)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
