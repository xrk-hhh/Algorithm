// 原始稿：03_题目/洛谷/Practice/P_3275_SCOI_2011_糖果.cpp
// 原文行号：146-290；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, k;
        cin>>n>>k;

        vector<vector<pair<int, int>>> g(n + 1);
        bool bad = false;
        for (int i = 0; i < k; i++)
        {
            int x, a, b;
            cin>>x>>a>>b;

            if (x == 1)
            {
                g[a].push_back({b, 0});
                g[b].push_back({a, 0});
            }
            else if (x == 2)
            {
                if (a == b)
                {
                    bad = true;
                }
                g[a].push_back({b, 1});
            }
            else if (x == 3)
            {
                g[b].push_back({a, 0});
            }
            else if (x == 4)
            {
                if (a == b)
                {
                    bad = true;
                }
                g[b].push_back({a, 1});
            }
            else if (x == 5)
            {
                g[a].push_back({b, 0});
            }
        }

        if (bad)
        {
            cout<<-1<<endl;
            return 0;
        }

        vector<vector<pair<int, int>>> ng(n + 2);
        for (int i = 1; i <= n; i++)
        {
            ng[0].push_back({i, 1});
        }
        for (int i = 1; i <= n; i++)
        {
            for (auto binding_value_01 : g[i])
            {
                auto v = binding_value_01.first;
                auto w = binding_value_01.second;
                ng[i].push_back({v, w});
            }
        }

        // SLF-SPFA版
        int tot = n + 1;
        vector<ll> dist(tot, -INF);
        vector<int> cnt(tot, 0);
        vector<bool> inq(tot, false);
        // 双端队列 dq 优化
        deque<int> dq;
        dist[0] = 0;
        dq.push_back(0);
        inq[0] = true;
        cnt[0] = 1;
        bool pos_cycle = false;
        while (!dq.empty())
        {
            int u = dq.front();
            dq.pop_front();

            inq[u] = false;
            for (auto binding_value_02 : ng[u])
            {
                auto v = binding_value_02.first;
                auto w = binding_value_02.second;
                if (dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    if (!inq[v])
                    {
                        // SLF优化
                        if (!dq.empty() && dist[v] > dist[dq.front()])
                        {
                            dq.push_front(v);
                        }
                        else
                        {
                            dq.push_back(v);
                        }
                        // 可能是由于洛谷数据特性，此处不加 inq[v] = true反而能 AC，加了后却会 TLE 一个点
                        inq[v] = true;
                        if (++cnt[v] > tot)
                        {
                            pos_cycle = true;
                            break;
                        }
                    }
                }
            }
            if (pos_cycle)
            {
                break;
            }
        }

        if (pos_cycle)
        {
            cout<<-1<<endl;
            return 0;
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dist[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
