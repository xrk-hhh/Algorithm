#include <bits/stdc++.h>
using namespace std;

struct Treap
{
    struct N
    {
        int l, r, sz, key;
        unsigned pri;
    };
    vector<N> t;
    int root = 0;
    mt19937 rng{712367};
    Treap() : t(1) {}
    int sz(int x)
    {
        return x ? t[x].sz : 0;
    }
    void up(int x)
    {
        t[x].sz = sz(t[x].l) + sz(t[x].r) + 1;
    }
    // 按严格小于k分裂，k用long long避免key-1溢出
    void split(int p, long long k, int &a, int &b)
    {
        if (!p)
        {
            a = b = 0;
            return;
        }
        if (t[p].key < k)
        {
            a = p;
            split(t[p].r, k, t[p].r, b);
            up(a);
        }
        else
        {
            b = p;
            split(t[p].l, k, a, t[p].l);
            up(b);
        }
    }
    int merge(int a, int b)
    {
        if (!a || !b)
            return a ? a : b;
        if (t[a].pri < t[b].pri)
        {
            t[a].r = merge(t[a].r, b);
            up(a);
            return a;
        }
        t[b].l = merge(a, t[b].l);
        up(b);
        return b;
    }
    void insert(int k)
    {
        int a, b;
        split(root, k, a, b);
        int x = t.size();
        t.push_back({0, 0, 1, k, (unsigned)rng()});
        root = merge(merge(a, x), b);
    }
    void erase(int k)
    {
        int a, b, c;
        split(root, k, a, b);
        split(b, (long long)k + 1, b, c);
        if (b)
            b = merge(t[b].l, t[b].r); // 一次只删一个
        root = merge(merge(a, b), c);
    }
    int rank(int k)
    {
        int a, b;
        split(root, k, a, b);
        int z = sz(a) + 1;
        root = merge(a, b);
        return z;
    }
    int kth(int k)
    { // 1<=k<=sz(root)
        int p = root;
        while (1)
        {
            int z = sz(t[p].l);
            if (k == z + 1)
                return t[p].key;
            if (k <= z)
                p = t[p].l;
            else
                k -= z + 1, p = t[p].r;
        }
    }
    // 前驱/后继不存在返回false
    bool neighbor(int k, bool successor, int &ans)
    {
        int p = root;
        bool ok = false;
        while (p)
        {
            if (successor ? t[p].key > k : t[p].key < k)
            {
                ans = t[p].key;
                ok = true;
                p = successor ? t[p].l : t[p].r;
            }
            else
                p = successor ? t[p].r : t[p].l;
        }
        return ok;
    }
};
