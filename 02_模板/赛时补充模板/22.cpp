#include <bits/stdc++.h>
using namespace std;

// dp[j]为容量不超过j的最大价值；w>0，c>=0
void bounded_pack(vector<long long> &dp, int W, int w, int v,
                  int c)
{
    c = min(c, W / w);
    for (long long k = 1; c; k <<= 1)
    {
        int z = min(k, (long long)c);
        for (int j = W; j >= z * w; j--)
            dp[j] = max(dp[j], dp[j - z * w] + 1LL * z * v);
        c -= z;
    }
}
// 按模w的剩余类单调队列，单类物品O(W)
void bounded_queue(vector<long long> &dp, int W, int w, int v,
                   int c)
{
    vector<long long> old = dp;
    for (int r = 0; r < w && r <= W; r++)
    {
        deque<int> q;
        for (int k = 0; r + k * w <= W; k++)
        {
            while (!q.empty() && q.front() < k - c)
                q.pop_front();
            auto value = [&](int t)
            { return old[r + t * w] - 1LL * t * v; };
            while (!q.empty() && value(q.back()) <= value(k))
                q.pop_back();
            q.push_back(k);
            dp[r + k * w] = value(q.front()) + 1LL * k * v;
        }
    }
}
