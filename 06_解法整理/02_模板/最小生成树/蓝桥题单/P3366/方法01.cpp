// 原始稿：02_模板/最小生成树/蓝桥题单/P3366.cpp
// 原文行号：1-113；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

struct Edge
{
    int u, v, w;
};

bool cmp(const Edge& a, const Edge& b)
{
    return a.w < b.w;
}

// 并查集模板
struct DSU
{
    vector<int> fa, sz;
    DSU(int n)
    {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
        {
            return false;
        }
        if (sz[x] < sz[y])
        {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        // 最小生成树（Kruskal算法（基于边））
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++)
        {
            cin>>edges[i].u>>edges[i].v>>edges[i].w;
        }

        // 按权值升序排序
        sort(edges.begin(), edges.end(), cmp);

        DSU dsu(n);

        ll ans = 0;
        int cnt = 0;
        // 遍历排序后的边
        for (auto& e : edges)
        {
            // 边的两端点不在同一集合，则将该边加入最小生成树
            if (dsu.unite(e.u, e.v))
            {
                // 累加权值
                ans += e.w;
                // 边数加一
                cnt++;
                // 图连通
                if (cnt == n - 1)
                {
                    break;
                }
            }
        }

        // 图连通
        if (cnt == n - 1)
        {
            cout<<ans<<endl;
        }
        // 图不连通
        else
        {
            cout<<"orz"<<endl;
        }
    }

    return 0;
}
