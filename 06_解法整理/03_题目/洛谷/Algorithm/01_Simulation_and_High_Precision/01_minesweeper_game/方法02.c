// 原始稿：03_题目/洛谷/Algorithm/01_Simulation_and_High_Precision/01_minesweeper_game.c
// 原文行号：86-144；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

int main() 
{
    // 雷区最大规模为100x100，数组开105x105预留冗余
    char grid[105][105];
    int n, m;
    // 读取行数n和列数m
    scanf("%d %d", &n, &m);
    
    // 读取n行雷区布局
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", grid[i]);
    }
    
    // 定义8个相邻方向的坐标偏移量（行偏移dx，列偏移dy）
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // 遍历每个格子
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (grid[i][j] == '*') 
            {
                // 当前是地雷格，直接输出'*'
                printf("*");
            } 
            else 
            {
                // 当前是非地雷格，统计周围地雷数
                int mine_count = 0;
                for (int k = 0; k < 8; k++) 
                {
                    // 计算相邻格子的坐标
                    int x = i + dx[k];
                    int y = j + dy[k];
                    // 检查坐标是否在合法范围内（避免越界）
                    if (x >= 0 && x < n && y >= 0 && y < m) 
                    {
                        // 若相邻格子是地雷，计数+1
                        if (grid[x][y] == '*') 
                        {
                            mine_count++;
                        }
                    }
                }
                // 将计数转换为字符输出（'0' + 数字 = 对应字符）
                printf("%c", '0' + mine_count);
            }
        }
        // 每行结束后换行
        printf("\n");
    }
    
    return 0;
}
