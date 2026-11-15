// 原始稿：03_题目/蓝桥杯/国赛/luogu_imitation/T_753822_玩具.cpp
// 原文行号：1-96；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 998244353;
const int N = 26, tarN = 5;
const string s = "abcdefghijklmnopqrstuvwxyz";
const string tar = "aeiou";
const int tarx = 341799, tary = 5;

ll ans = 0;
vector<vector<char>> g; 

void dfs(int x, int y, ll cnt)
{
    if (x == tarx && y == tary)
    {
        ans = max(ans, cnt);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        bool ok = false;
        for (int j = 0; j < tarN; j++)
        {
            if (g[x][y] == tar[j])
            {
                ok = true;
                break;
            }
        }

        ll ncnt;
        if (ok)
        {
            ncnt = cnt * (N - tarN) % mod;
        }
        else
        {
            ncnt = cnt * N % mod;
        }
        
        if (y < tary)
        {
            if (x < tarx && (y & 1))
            {
                g[x + 1][y] = s[i];
                dfs(x + 1, y, ncnt);
            }
            else if (x == tarx && (y & 1))
            {
                g[x][y + 1] = s[i];
                dfs(x, y + 1, ncnt);
            }
            else if (x == tarx && (!(y & 1)))
            {
                g[1][y] = s[i];
                dfs(1, y, ncnt);
            }
            else if (x == 1 && (!(y & 1)))
            {
                g[1][y + 1] = s[i];
                dfs(x, y + 1, ncnt);
            }
        }
        else
        {
            g[x + 1][y] = s[i];
            dfs(x + 1, y, ncnt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        g.resize(tarx + 1, vector<char>(tary + 1));

        dfs(1, 1, 1);

        cout<<ans<<endl;
    }

    return 0;
}
