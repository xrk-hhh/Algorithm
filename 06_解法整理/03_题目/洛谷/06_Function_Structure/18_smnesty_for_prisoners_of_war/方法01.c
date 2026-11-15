// 原始稿：03_题目/洛谷/06_Function_Structure/18_smnesty_for_prisoners_of_war.c
// 原文行号：1-62；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>

int a[1024][1024];

void divide(int x, int y, int s) 
{
    if (s == 1) 
    {
        return;
    }
    int half = s / 2;

    for (int i = x; i < x + half; i++) 
    {
        for (int j = y; j < y + half; j++) 
        {
            a[i][j] = 0;
        }
    }

    divide(x, y + half, half);
    divide(x + half, y, half);
    divide(x + half, y + half, half);
}

int main() 
{
    int n;
    scanf("%d", &n);

    int x = 1 << n;

    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < x; j++) 
        {
            a[i][j] = 1;
        }
    }

    divide(0, 0, x);

    for (int i = 0; i < x; i++) 
    {
        printf("%d", a[i][0]);
        for (int j = 1; j < x; j++) 
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}


// 以上为手动赋值+分治递归


// 以下为通过位运算技巧和一维字符数组直接构造结果
