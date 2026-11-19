#include <bits/stdc++.h>
using namespace std;

struct PST
{
    struct N
    {
        int l, r, c;
    };
    vector<N> t;
    vector<int> rt;
    PST(int n) : t(1), rt(n + 1) {}
    int add(int p, int l, int r, int x)
    {
        int q = t.size();
        t.push_back(t[p]);
        t[q].c++;
        if (l < r)
        {
            int m = (l + r) / 2;
            if (x <= m)
            {
                int z = add(t[p].l, l, m, x);
                t[q].l = z;
            }
            else
            {
                int z = add(t[p].r, m + 1, r, x);
                t[q].r = z;
            }
        }
        return q;
    }
    int kth(int a, int b, int l, int r, int k)
    {
        if (l == r)
            return l;
        int c = t[t[b].l].c - t[t[a].l].c, m = (l + r) / 2;
        return k <= c ? kth(t[a].l, t[b].l, l, m, k)
                      : kth(t[a].r, t[b].r, m + 1, r, k - c);
    }
}; // 值先离散化至[1,V]；rt[i]=add(rt[i-1],1,V,a[i])
// 查询[l,r]第k小：kth(rt[l-1],rt[r],1,V,k)，答案再映射回原值
