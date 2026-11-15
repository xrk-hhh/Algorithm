// 原始稿：03_题目/洛谷/05_String/15_statement_analysis.c
// 原文行号：1-56；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

char str[256];

int main()
{
    scanf("%s", str);
    
    int a = 0, b = 0, c = 0;
    int len = strlen(str);
    int start = 0;

    for (int i = 0; i < len; i++) 
    {
        if (str[i] == ';') 
        {
            for (int j = 0; j < (i - start) - 1; j++) 
            {
                if (str[start + j] == ':' && str[start + j + 1] == '=') 
                {
                    char var_l = str[start + j - 1];
                    char val_r = str[start + j + 2];
                    
                    int val;
                    if (val_r >= '0' && val_r <= '9') 
                    {
                        val = val_r - '0';
                    } 
                    else 
                    {
                        switch (val_r) 
                        {
                            case 'a': val = a; break;
                            case 'b': val = b; break;
                            case 'c': val = c; break;
                        }
                    }
                    
                    switch (var_l) 
                    {
                        case 'a': a = val; break;
                        case 'b': b = val; break;
                        case 'c': c = val; break;
                    }
                    break;
                }
            }
            start = i + 1;
        }
    }

    printf("%d %d %d\n", a, b, c);

    return 0;
}
