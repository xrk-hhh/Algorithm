#include <bits/stdc++.h>
using namespace std;

int lcs(const string &a, const string &b)
{
    vector<int> dp(b.size() + 1);
    for (char x : a)
    {
        int pre = 0;
        for (int j = 1; j <= (int)b.size(); j++)
        {
            int z = dp[j];
            dp[j] =
                x == b[j - 1] ? pre + 1 : max(dp[j], dp[j - 1]);
            pre = z;
        }
    }
    return dp.back();
}
int permutation_lcs(const vector<int> &a, const vector<int> &b)
{
    int n = a.size();
    vector<int> pos(n + 1), tail;
    for (int i = 0; i < n; i++)
        pos[a[i]] = i;
    for (int v : b)
    {
        int x = pos[v];
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end())
            tail.push_back(x);
        else
            *it = x;
    }
    return tail.size();
} // 两个排列必须同为1..n；含重复值时不能直接用此映射
