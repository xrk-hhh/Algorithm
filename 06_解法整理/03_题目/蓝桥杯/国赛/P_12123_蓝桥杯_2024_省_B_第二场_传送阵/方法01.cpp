// 原始稿：03_题目/蓝桥杯/国赛/P_12123_蓝桥杯_2024_省_B_第二场_传送阵.cpp
// 原文行号：1-100；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

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

    int size(int x)
    {
        return sz[find(x)];
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
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
        int n;
        cin>>n;

        DSU dsu(n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;
            dsu.unite(i, x);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // 只取根节点，避免重复
            if (dsu.find(i) == i)
            {
                ans = max(ans, dsu.size(i));
            }
        }

        // 尝试用一次魔法连接两个相邻的环
        for (int i = 1; i < n; i++)
        {
            // 原来不在一个环中，那就直接贡献两个环的大小
            if (!dsu.same(i, i + 1))
            {
                ans = max(ans, dsu.size(i) + dsu.size(i + 1));
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
