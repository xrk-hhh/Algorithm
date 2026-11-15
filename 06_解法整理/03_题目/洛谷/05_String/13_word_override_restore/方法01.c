// 原始稿：03_题目/洛谷/05_String/13_word_override_restore.c
// 原文行号：1-28；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

char s[265];

int main() 
{
    int b = 0, g = 0;

    scanf("%s", s);

    int len = strlen(s);
    for (int i = 0; i < len; i++) 
    {
        if (s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y') 
        {
            b++;
        }
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l') 
        {
            g++;
        }
    }

    printf("%d\n%d", b, g);

    return 0;
}
