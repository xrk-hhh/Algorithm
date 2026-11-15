// 原始稿：03_题目/蓝桥杯/国赛/P_8654_蓝桥杯_2017_国_C_合根植物.cpp
// 原文行号：1-86；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 并查集模板
struct DSU
{
    vector<int> fa, sz;
    int cnt;
    DSU(int n)
    {
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        cnt = n;
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
        cnt--;
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
        int n, m, k;
        cin>>n>>m>>k;

        DSU dsu(n * m);

        while (k--)
        {
            int a, b;
            cin>>a>>b;

            dsu.unite(a, b);
        }

        // 多少个连通块
        cout<<dsu.cnt<<endl;
    }

    return 0;
}
