// 原始稿：03_题目/洛谷/06_Function_Structure/18_smnesty_for_prisoners_of_war.c
// 原文行号：63-86；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

char row[2050];

int main()
{
    int n;
    scanf("%d", &n);
    
    memset(row, ' ', 2<<n);
    
    n=(1 << n) - 1;
    for(int i = 0; i<=n; i++)
    {
    	for(int j = 0;j <= n; j++)
    	{
    		row[j << 1] = '0' + ((i | j) == n);
		}
		printf("%s\n", row);
	}
    
	return 0;
}
