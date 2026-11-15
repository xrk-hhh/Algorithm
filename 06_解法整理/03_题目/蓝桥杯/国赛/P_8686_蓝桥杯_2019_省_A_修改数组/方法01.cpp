// 原始稿：03_题目/蓝桥杯/国赛/P_8686_蓝桥杯_2019_省_A_修改数组.cpp
// 原文行号：1-88；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXV = 1e6 + 1e5;

// 并查集模板
struct DSU
{
    vector<int> fa;
    // vector<int> sz;
    DSU(int n)
    {
        fa.resize(n + 1);
        // sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    // bool unite(int x, int y)
    // {
    //     x = find(x), y = find(y);
    //     if (x == y)
    //     {
    //         return false;
    //     }

    //     if (sz[x] < sz[y])
    //     {
    //         swap(x, y);
    //     }

    //     fa[y] = x;
    //     sz[x] += sz[y];
    //     return true;
    // }

    // int size(int x)
    // {
    //     return sz[find(x)];
    // }

    // bool same(int x, int y)
    // {
    //     return find(x) == find(y);
    // }
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

        DSU dsu(MAXV);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;

            // 返回其根节点
            int fa = dsu.find(x);

            cout<<fa<<' ';
            // 根节点的根节点更新为 当前根节点 + 1
            dsu.fa[fa] = dsu.find(fa + 1);
        }
        cout<<endl;
    }

    return 0;
}
