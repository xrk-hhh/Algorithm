// 原始稿：03_题目/蓝桥杯/国赛/P_10577_蓝桥杯_2024_国_A_兔子集结.cpp
// 原文行号：1-157；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1e5 + 10;

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

// 结构体：存储 位置 + 编号
struct Node
{
    int pos, id;
} s[N];

bool cmp1(Node& x, Node& y)
{
    return x.pos < y.pos;
}

bool cmp2(Node& x, Node& y)
{
    return x.id < y.id;
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

        DSU dsu(n);
        for (int i = 1; i <= n; i++)
        {
            cin>>s[i].pos;
            s[i].id = i;
        }

        // 先按位置从小到大排序
        sort(s + 1, s + n + 1, cmp1);

        // 初始跟随方向：

        // 最左兔子只能选右边
        dsu.fa[1] = 2;
        // 最右兔子只能选左边
        dsu.fa[n] = n - 1;
        for (int i = 2 ; i <= n - 1; i++)
        {
            int lp = s[i - 1].pos, p = s[i].pos, rp = s[i + 1].pos;
            // 左边更近（或等距选左）
            if (p - lp <= rp - p)
            {
                // 选择左边的邻居
                dsu.fa[i] = i - 1;
            }
            else
            {
                // 选择右边的邻居
                dsu.fa[i] = i + 1;
            }
        }

        // 形成集结根：

        for (int i = 1; i <= n - 1; i++)
        {
            // 互相选择
            if (dsu.fa[i] == i + 1 && dsu.fa[i + 1] == i)
            {
                // 将自身设为根（停止移动）
                dsu.fa[i] = i;
                dsu.fa[i + 1] = i + 1;
                // 计算集结位置
                int p = (s[i].pos + s[i + 1].pos) >> 1;
                s[i].pos = s[i + 1].pos = p;
            }
        }

        // 路径压缩，所有兔子指向最终集结位置
        for (int i = 1; i <= n; i++)
        {
            if (dsu.fa[i] != i)
            {
                // 寻找 i 最终跟随的根
                int u = dsu.find(i);
                // 位置更新为根的位置
                s[i].pos = s[u].pos;
            }
        }

        // 再按 id 排序还原输入顺序
        sort(s + 1, s + n + 1, cmp2);

        for (int i = 1; i <= n; i++)
        {
            cout<<s[i].pos<<' ';
        }
        cout<<endl;
    }

    return 0;
}
