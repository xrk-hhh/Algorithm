// 原始稿：04_训练与工具/牛客新手130题/07/40.cpp
// 原文行号：1-39；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int a[1010][1010];

int main()
{
    int n, m;
    cin>>n>>m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                a[i][j] = 1;
            }
            else if (i >= 2 && j == 1)
            {
                a[i][j] = a[i - 1][j];
            }
            else if(i == 1 && j >= 2)
            {
                a[i][j] = a[i][j - 1];
            }
            else
            {
                a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MOD;
            }
        }
    }

    cout<<a[n][m];

    return 0;
}
