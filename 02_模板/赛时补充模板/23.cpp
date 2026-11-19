#include <bits/stdc++.h>
using namespace std;

// 同组最多选一个；pair为{重量,价值}；每个新组调用一次
void group_pack(vector<long long> &dp, int W,
                const vector<pair<int, int>> &g)
{
    vector<long long> old = dp;
    for (auto e : g)
        for (int j = e.first; j <= W; j++)
            dp[j] = max(dp[j], old[j - e.first] + e.second);
} // 至多容量：初值0；恰好容量：仅dp[0]=0，其余负无穷并跳过不可达项
