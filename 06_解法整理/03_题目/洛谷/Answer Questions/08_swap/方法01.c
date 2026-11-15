// 原始稿：03_题目/洛谷/Answer Questions/08_swap.c
// 原文行号：1-22；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int a = 10;
    int b = 20;
    printf("%d %d\n",a,b);

    swap(&a, &b);
    printf("%d %d",a,b);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
