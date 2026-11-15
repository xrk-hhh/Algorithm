// 原始稿：03_题目/蓝桥杯/国赛/P_12212_蓝桥杯_2023_国_Python_B_最大阶梯.cpp
// 原文行号：1-111；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 计算网格中“左上直角”阶梯的最大边长
int calc(const vector<vector<bool>>& g)
{
    int h = g.size();
    if (h == 0)
    {
        return 0;
    }

    int w = g[0].size();
    // dp[i][j]：以每个格子 (i, j) 为左上角，向右下方延伸的同色阶梯的最大边长
    // （阶梯形状为：第 1 行 k 个，第 2 行 k-1 个，…，第 k 行 1 个，左上角为直角）
    vector<vector<int>> dp(h, vector<int>(w, 0));
    int ans = 0;
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            // 不是目标颜色
            if (!g[i][j])
            {
                dp[i][j] = 0;
            }
            else
            {
                int r = (j + 1 < w) ? dp[i][j + 1] : 0;
                int d = (i + 1 < h) ? dp[i + 1][j] : 0;
                dp[i][j] = 1 + min(r, d);
            }

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

// 顺时针旋转90度
vector<vector<bool>> rotate(const vector<vector<bool>>& g)
{
    int h = g.size(), w = g[0].size();
    vector<vector<bool>> res(w, vector<bool>(h));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            res[j][h - 1 - i] = g[i][j];
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int h;
        cin>>h;

        vector<vector<int>> col(h, vector<int>(h));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < h; j++)
            {
                cin>>col[i][j];
            }
        }

        int ans = 0;
        // 颜色范围 0..10
        for (int c = 0; c <= 10; c++)
        {
            vector<vector<bool>> mat(h, vector<bool>(h));
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < h; j++)
                {
                    mat[i][j] = (col[i][j] == c);           
                }
            }

            // 四个旋转方向
            auto g0 = mat;
            auto g90 = rotate(g0);
            auto g180 = rotate(g90);
            auto g270 = rotate(g180);

            ans = max(ans, calc(g0));
            ans = max(ans, calc(g90));
            ans = max(ans, calc(g180));
            ans = max(ans, calc(g270));
        }

        cout<<ans<<endl;
    }

    return 0;
}
