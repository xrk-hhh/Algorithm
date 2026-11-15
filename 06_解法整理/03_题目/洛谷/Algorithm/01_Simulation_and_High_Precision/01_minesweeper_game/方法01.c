// 原始稿：03_题目/洛谷/Algorithm/01_Simulation_and_High_Precision/01_minesweeper_game.c
// 原文行号：1-85；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>

char c[110][110];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    for (int i = 1; i <= n; i++)
    {
        char temp[110];
        fgets(temp, 110, stdin);
        for (int j = 1; j <= m; j++)
        {
            c[i][j] = temp[j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '*')
            {
                continue;
            }

            int cnt = 0;
            
            if (c[i - 1][j - 1] == '*')
            {
                cnt++;
            }
            if (c[i - 1][j] == '*')
            {
                cnt++;
            }
            if (c[i - 1][j + 1] == '*')
            {
                cnt++;
            }
            if (c[i][j - 1] == '*')
            {
                cnt++;
            }
            if (c[i][j + 1] == '*')
            {
                cnt++;
            }
            if (c[i + 1][j - 1] == '*')
            {
                cnt++;
            }
            if (c[i + 1][j] == '*')
            {
                cnt++;
            }
            if (c[i + 1][j + 1] == '*')
            {
                cnt++;
            }
            c[i][j] = cnt + '0';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 以上为直接模拟，且通过数组下标设为1~n和1~m来规避数组越界问题
// 且输入时因为字符之间无空格，且有换行，故需使用getchar和fgets进行处理

// 以下为通过行偏移和列偏移量进行遍历
// 读取输入时该行为字符串类型，用%s
