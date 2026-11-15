// 原始稿：03_题目/蓝桥杯/3/P1101.cpp
// 原文行号：1-140；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        vector<string> b(n, string(n, '*'));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] != 'y')
                {
                    continue;
                }
                else
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                        {
                            if (a[nx][ny] != 'i')
                            {
                                continue;
                            }
                            else
                            {
                                int nxx = nx + dx[k];
                                int nyy = ny + dy[k];
                                if (nxx >= 0 && nxx < n && nyy >= 0 && nyy < n)
                                {
                                    if (a[nxx][nyy] != 'z')
                                    {
                                        continue;
                                    }
                                    else
                                    {
                                        int nxxx = nxx + dx[k];
                                        int nyyy = nyy + dy[k];
                                        if (nxxx >= 0 && nxxx < n && nyyy >= 0 && nyyy < n)
                                        {
                                            if (a[nxxx][nyyy] != 'h')
                                            {
                                                continue;
                                            }
                                            else
                                            {
                                                int nxxxx = nxxx + dx[k];
                                                int nyyyy = nyyy + dy[k];
                                                if (nxxxx >= 0 && nxxxx < n && nyyyy >= 0 && nyyyy < n)
                                                {
                                                    if (a[nxxxx][nyyyy] != 'o')
                                                    {
                                                        continue;
                                                    }
                                                    else
                                                    {
                                                        int nxxxxx = nxxxx + dx[k];
                                                        int nyyyyy = nyyyy + dy[k];
                                                        if (nxxxxx >= 0 && nxxxxx < n && nyyyyy >= 0 && nyyyyy < n)
                                                        {
                                                            if (a[nxxxxx][nyyyyy] != 'n')
                                                            {
                                                                continue;
                                                            }
                                                            else
                                                            {
                                                                int nxxxxxx = nxxxxx + dx[k];
                                                                int nyyyyyy = nyyyyy + dy[k];
                                                                if (nxxxxxx >= 0 && nxxxxxx < n && nyyyyyy >= 0 && nyyyyyy < n)
                                                                {
                                                                    if (a[nxxxxxx][nyyyyyy] != 'g')
                                                                    {
                                                                        continue;
                                                                    }
                                                                    else
                                                                    {
                                                                        b[i][j] = 'y';
                                                                        b[nx][ny] = 'i';
                                                                        b[nxx][nyy] = 'z';
                                                                        b[nxxx][nyyy] = 'h';
                                                                        b[nxxxx][nyyyy] = 'o';
                                                                        b[nxxxxx][nyyyyy] = 'n';
                                                                        b[nxxxxxx][nyyyyyy] = 'g';
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout<<b[i]<<endl;
        }
    }

    return 0;
}

// 以上为 shi山 代码（暴力，嵌套了 3 层循环和 7 个 if）

// 以下为正经做法
