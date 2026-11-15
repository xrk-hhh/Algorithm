#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 10;

vector<int> g[N];
ll a[N];
ll dp[N], maxx[N];
ll fact[N];

ll ksm(ll a, ll b, ll p)
{
    ll res = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % p;
        }
        b >>= 1;
        a = a *a  % p;
    }
    return res % p;
}

struct Child
{
    ll val, maxx, dp;
    bool operator<(const Child& other) const
    {
        if (val != other.val)
        {
            return val < other.val;
        }

        return maxx < other.maxx;
    }
};

void pre()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
}

void dfs(int u, int fa)
{
    vector<Child> children;
    for (int v : g[u])
    {
        if (v != fa)
        {
            dfs(v, u);
            if (dp[v] == 0)
            {
                dp[u] = 0;
                return;
            }

            children.push_back({a[v], maxx[v], dp[v]});
        }
    }

    if (children.empty())
    {
        dp[u] = 1;
        maxx[u] = a[u];
        return;
    }

    sort(children.begin(), children.end());

    for (int i = 0; i < children.size();)
    {
        int j = i;
        while (j < children.size() && children[j].val == children[i].val)
        {
            j++;
        }

        int eq = 0, gt = 0;
        for (int k = i; k < j; k++)
        {
            if (children[k].maxx > children[i].val)
            {
                gt++;
            }
            else if (children[k].maxx < children[i].val)
            {
                dp[u] = 0;
                return;
            }
        }

        i = j;
    }

    for (int i = 0; i + 1 < children.size(); i++)
    {
        if (children[i].maxx > children[i + 1].val)
        {
            dp[u] = 0;
            return;
        }
    }

    if (a[u] > children[0].val)
    {
        dp[u] = 0;
        return;
    }

    ll prod = 1;
    for (auto& ch : children)
    {
        prod = prod * ch.dp % mod;
    }

    for (int i = 0; i < children.size();)
    {
        int j = i;
        while (j < children.size() && children[j].val == children[i].val)
        {
            j++;
        }

        int eq = 0;
        for (int k = i; k < j; k++)
        {
            if (children[k].maxx == children[i].val)
            {
                eq++;
            }
        }

        prod = prod * fact[eq] % mod;

        i = j;
    }

    dp[u] = prod;
    maxx[u] = children.back().maxx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    pre();

    while (T--)
    {
        int n;
        cin>>n;

        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }

        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin>>u>>v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1, 0);

        if (dp[1] == 0)
        {
            cout<<0<<endl;
            continue;
        }

        ll tot = 1;
        for (int u = 1; u <= n; u++)
        {
            int cnt = g[u].size() - (u != 1);
            tot = tot * fact[cnt] % mod;
        }

        ll ans = dp[1] * ksm(tot, mod - 2, mod) % mod;

        cout<<ans<<endl;
    }

    return 0;
}