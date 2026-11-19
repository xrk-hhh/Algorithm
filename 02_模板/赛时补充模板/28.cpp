#include <bits/stdc++.h>
using namespace std;

long long triangle(const vector<vector<int>> &a)
{
    if (a.empty())
        return 0;
    vector<long long> dp(a.back().begin(), a.back().end());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[j] = a[i][j] + max(dp[j], dp[j + 1]);
    return dp[0];
} // 自底向上，无需给负权路径补0；带障碍时将不可达设负无穷
