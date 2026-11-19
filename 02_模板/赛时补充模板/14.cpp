#include <bits/stdc++.h>
using namespace std;

// 返回[0,N]中数字0..9各出现多少次，数字0本身计一次0
struct DigitDP
{
    struct R
    {
        long long ways = 0;
        array<long long, 10> cnt{};
    };
    R memo[20][2];
    bool vis[20][2]{};
    string s;
    R dfs(int p, bool tight, bool started)
    {
        if (p == (int)s.size())
        {
            R z;
            z.ways = 1;
            if (!started)
                z.cnt[0] = 1;
            return z;
        }
        int left = s.size() - p;
        if (!tight && vis[left][started])
            return memo[left][started];
        R ans;
        int up = tight ? s[p] - '0' : 9;
        for (int d = 0; d <= up; d++)
        {
            bool ns = started || d != 0;
            R z = dfs(p + 1, tight && d == up, ns);
            ans.ways += z.ways;
            for (int k = 0; k < 10; k++)
                ans.cnt[k] += z.cnt[k];
            if (ns)
                ans.cnt[d] += z.ways;
        }
        if (!tight)
            vis[left][started] = true, memo[left][started] = ans;
        return ans;
    }
    array<long long, 10> calc(long long n)
    {
        if (n < 0)
            return {};
        s = to_string(n);
        memset(vis, 0, sizeof vis);
        return dfs(0, true, false).cnt;
    }
}; // N<=10^17时各项可放long long；更大上界需扩展统计类型
