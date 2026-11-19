#include <bits/stdc++.h>
using namespace std;

vector<int> mobius_prefix(int n)
{
    vector<int> mu(n + 1), p;
    vector<char> vis(n + 1);
    if (!n)
        return mu;
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            p.push_back(i), mu[i] = -1;
        for (int q : p)
        {
            if (1LL * i * q > n)
                break;
            vis[i * q] = 1;
            if (i % q == 0)
            {
                mu[i * q] = 0;
                break;
            }
            mu[i * q] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++)
        mu[i] += mu[i - 1];
    return mu;
}
long long coprime_count(int A, int B, const vector<int> &pre)
{
    if (A <= 0 || B <= 0)
        return 0;
    long long ans = 0;
    for (int l = 1, r; l <= min(A, B); l = r + 1)
    {
        r = min(A / (A / l), B / (B / l));
        ans += 1LL * (pre[r] - pre[l - 1]) * (A / l) * (B / l);
    }
    return ans;
} // gcd(x,y)=k的前缀计数调用coprime_count(A/k,B/k,pre)
