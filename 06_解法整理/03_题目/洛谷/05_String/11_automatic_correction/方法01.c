// 原始稿：03_题目/洛谷/05_String/11_automatic_correction.c
// 原文行号：1-24；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

char str[110];

int main()
{
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
        {
            str[i] -= 'a' - 'A';
        }
    }

    printf("%s\n", str);

    return 0;
}
