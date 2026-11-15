// 原始稿：03_题目/蓝桥杯/国赛/P_12220_蓝桥杯_2023_国_Java_B_星球.cpp
// 原文行号：1-82；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int INF = 0x3f3f3f3f;

struct Point
{
    int x, y, z, w;
};

// 获取两点间距离
double get_dist(Point& p1, Point& p2)
{
    double dist = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));

    return dist;
}

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

        vector<Point> p(n);
        for (int i = 0; i < n; i++)
        {
            cin>>p[i].x>>p[i].y>>p[i].z>>p[i].w;
        }

        // dp[mask][last]：在 mask 集合中，以 last 为结尾的最小能量
        vector<vector<double>> dp(1 << n, vector<double>(n, INF));
        // 初始化
        for (int i = 0; i < n; i++)
        {
            dp[1 << i][i] = 0;
        }

        for (int mask = 0; mask < (1 << n); mask++)
        {
            for (int last = 0; last < n; last++)
            {
                if (!(mask & (1 << last)))
                {
                    continue;
                }

                for (int nxt = 0; nxt < n; nxt++)
                {
                    if (mask & (1 << nxt))
                    {
                        continue;
                    }

                    double t = get_dist(p[last], p[nxt]) * p[nxt].w;

                    dp[mask | (1 << nxt)][nxt] = min(dp[mask | (1 << nxt)][nxt], dp[mask][last] + t);
                }
            }
        }

        double ans = INF;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[(1 << n) - 1][i]);
        }

        cout<<fixed<<setprecision(2)<<ans<<endl;
    }

    return 0;
}
