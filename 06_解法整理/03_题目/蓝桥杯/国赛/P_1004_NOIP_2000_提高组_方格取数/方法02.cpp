// 原始稿：03_题目/蓝桥杯/国赛/P_1004_NOIP_2000_提高组_方格取数.cpp
// 原文行号：102-201；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n;
vector<vector<int>> a;
vector<vector<bool>> vis;
int ans = 0;

// dp 第二个人
int Second()
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int val = vis[i][j] ? 0 : a[i][j];
            if (i == 1 && j == 1)
            {
                dp[i][j] = val;
            }
            else if (i == 1)
            {
                dp[i][j] = dp[i][j - 1] + val;
            }
            else if (j == 1)
            {
                dp[i][j] = dp[i - 1][j] + val;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + val;
            }
        }
    }

    return dp[n][n];
}

// DFS 第一个人
void dfs(int x, int y, int sum)
{
    if (x == n && y == n)
    {
        ans = max(ans, sum + Second());
        return;
    }

    vis[x][y] = true;
    sum += a[x][y];
    // 向下
    if (x < n)
    {
        dfs(x + 1, y, sum);
    }
    // 向右
    if (y < n)
    {
        dfs(x, y + 1, sum);
    }

    vis[x][y] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        // 也可以一个 dp + 一个 DFS
        cin>>n;
        vis.resize(n + 1, vector<bool>(n + 1, false));
        a.resize(n + 1, vector<int>(n + 1));

        int x, y, v;
        while (cin>>x>>y>>v)
        {
            if (x == 0 && y == 0 && v == 0)
            {
                break;
            }

            a[x][y] = v;
        }

        dfs(1, 1, 0);

        cout<<ans<<endl;
    }

    return 0;
}
