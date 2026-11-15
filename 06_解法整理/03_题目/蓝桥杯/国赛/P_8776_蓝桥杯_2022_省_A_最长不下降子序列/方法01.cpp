// 原始稿：03_题目/蓝桥杯/国赛/P_8776_蓝桥杯_2022_省_A_最长不下降子序列.cpp
// 原文行号：1-218；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXA = 1e6;
const int INFV = MAXA + 1;
const int MINV = 0;
const int NINF = -1e9;

struct SegTree
{
    struct Node
    {
        int maxPre, maxSuf, best;
    };

    vector<Node> tree;
    int n;

    SegTree(int sz)
    {
        n = sz;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int u, int l, int r)
    {
        tree[u] = {NINF, NINF, NINF};
        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void pushup(int u)
    {
        tree[u].maxPre = max(tree[u << 1].maxPre, tree[u << 1 | 1].maxPre);
        tree[u].maxSuf = max(tree[u << 1].maxSuf, tree[u << 1 | 1].maxSuf);

        tree[u].best = max({tree[u << 1].best, tree[u << 1 | 1].best, tree[u << 1].maxPre + tree[u << 1 | 1].maxSuf});
    }

    void updatePre(int u, int l, int r, int pos, int v)
    {
        if (l == r)
        {
            tree[u].maxPre = max(tree[u].maxPre, v);
            tree[u].best = max(tree[u].best, tree[u].maxPre + tree[u].maxSuf);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            updatePre(u << 1, l, mid, pos, v);
        }
        else
        {
            updatePre(u << 1 | 1, mid + 1, r, pos, v);
        }

        pushup(u);
    }
    void updateSuf(int u, int l, int r, int pos, int v)
    {
        if (l == r)
        {
            tree[u].maxSuf = v;
            tree[u].best = max(tree[u].best, tree[u].maxPre + tree[u].maxSuf);
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            updateSuf(u << 1, l, mid, pos, v);
        }
        else
        {
            updateSuf(u << 1 | 1, mid + 1, r, pos, v);
        }

        pushup(u);
    }

    int getBest()
    {
        return tree[1].best;
    }
};

struct BIT
{
    vector<int> t;
    int n;
    BIT(int sz)
    {
        n = sz;
        t.resize(sz + 2, 0);
    }
    
    void update(int i, int v)
    {
        for (; i <= n; i += i & -i)
        {
            t[i] = max(t[i], v);
        }
    }

    int query(int i)
    {
        int res = 0;
        for (; i > 0; i -= i & -i)
        {
            res = max(res ,t[i]);
        }
        return res;
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
        int n, k;
        cin>>n>>k;

        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        a[0] = MINV;
        a[n + 1] = INFV;

        vector<int> pre(n + 2, 0);
        BIT bitPre(MAXA);
        for (int i = 1; i <= n; i++)
        {
            int v = bitPre.query(a[i]);
            pre[i] = v + 1;
            bitPre.update(a[i], pre[i]);
        }

        vector<int> suf(n + 2, 0);
        BIT bitSuf(MAXA);
        for (int i = n; i >= 1; i--)
        {
            int rev = MAXA - a[i] + 1;
            int v = bitSuf.query(rev);
            suf[i] = v + 1;
            bitSuf.update(rev, suf[i]);
        }

        SegTree seg(INFV + 1);

        seg.updatePre(1, 0, INFV, MINV, pre[0]);

        vector<multiset<int>> maxSuf(INFV + 1);
        auto insertR = [&](int i) 
        {
            int v = a[i];
            maxSuf[v].insert(suf[i]);
            seg.updateSuf(1, 0, INFV, v, *maxSuf[v].rbegin());
        };
        auto eraseR = [&](int i) 
        {
            int v = a[i];
            auto it = maxSuf[v].find(suf[i]);
            if (it != maxSuf[v].end())
            {
                maxSuf[v].erase(it);
            }
            int nmax = maxSuf[v].empty() ? NINF : *maxSuf[v].rbegin();
            seg.updateSuf(1, 0, INFV, v, nmax);
        };

        insertR(n + 1);
        for (int i = k + 1; i <= n; i++) 
        {
            insertR(i);
        }

        int ans = 0;
        for (int l = 1; l + k - 1 <= n; l++) 
        {
            int r = l + k - 1;
            ans = max(ans, k + seg.getBest());
            if (l + k <= n) 
            {
                int vL = a[l];
                static vector<int> curMaxPre(INFV + 1, NINF);
                curMaxPre[vL] = max(curMaxPre[vL], pre[l]);
                seg.updatePre(1, 0, INFV, vL, curMaxPre[vL]);

                eraseR(l + k);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
