#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int MAXN = 1000010;

struct Node
{
    int l, r;
    int L, R, par;
    bool dg;
    ll cnt; 
} tree[4 * MAXN];

int rt, tot = 0;

int build(int l, int r, int p = 0)
{
    int u = tot++;
    tree[u].l = l;
    tree[u].r = r;
    tree[u].par = p;
    tree[u].dg = false;

    if (l == r)
    {
        tree[u].L = -1;
        tree[u].R = -1;
        tree[u].cnt = 1;

        return u;
    }

    int mid = (l + r) >> 1;

    tree[u].L = build(l, mid, u);
    tree[u].R = build(mid + 1, r, u);
    tree[u].cnt = 1;

    return u;
}

int find(int u, int l, int r)
{
    while (tree[u].l != l || tree[u].r != r)
    {
        int mid = (tree[u].l + tree[u].r) >> 1;

        if (r <= mid)
        {
            u = tree[u].L;
        }
        else
        {
            u = tree[u].R;
        }
    }
    return u;
}

void update(int u)
{
    ll sum = 0;

    if (tree[u].L != -1)
    {
        sum += tree[tree[u].L].cnt;
    }
    if (tree[u].R != -1)
    {
        sum += tree[tree[u].R].cnt;
    }

    tree[u].cnt = sum;

    for (int p = tree[u].par; p; p = tree[p].par)
    {
        if (!tree[p].dg)
        {
            break;
        }

        sum = 0;
        if (tree[p].L != -1)
        {
            sum += tree[tree[p].L].cnt;
        }

        if (tree[p].R != -1)
        {
            sum += tree[tree[p].R].cnt;
        }

        tree[p].cnt = sum;
    }
}

void dg(int u)
{
    if (tree[u].dg)
    {
        return;
    }

    tree[u].dg = true;

    update(u);
}

ll query(int u, int l, int r)
{
    if (tree[u].r < l || tree[u].l > r)
    {
        return 0;
    }

    if (tree[u].l >= l && tree[u].r <= r)
    {
        return tree[u].cnt;
    }

    ll res = 0;

    if (!tree[u].dg)
    {
        res = 1;
    }

    int mid = (tree[u].l + tree[u].r) >> 1;

    if (tree[u].L != -1 && l <= mid)
    {
        res += query(tree[u].L, l, r);
    }

    if (tree[u].R != -1 && r > mid)
    {
        res += query(tree[u].R, l, r);
    }

    return res;
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

        rt = build(1, n);
        for (int i = 0; i < n; i++)
        {
            int op, l, r;
            cin>>op>>l>>r;

            if (op == 1)
            {
                int node = find(rt, l, r);
                dg(node);
            }
            else
            {
                cout<<query(rt, l ,r)<<endl;
            }
        }
    }

    return 0;
}