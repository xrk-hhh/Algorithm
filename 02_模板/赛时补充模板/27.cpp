#include <bits/stdc++.h>
using namespace std;

int edit_distance(const string &a, const string &b)
{
    vector<int> dp(b.size() + 1);
    iota(dp.begin(), dp.end(), 0);
    for (int i = 1; i <= (int)a.size(); i++)
    {
        int pre = dp[0];
        dp[0] = i;
        for (int j = 1; j <= (int)b.size(); j++)
        {
            int z = dp[j];
            dp[j] = min({dp[j] + 1, dp[j - 1] + 1,
                         pre + (a[i - 1] != b[j - 1])});
            pre = z;
        }
    }
    return dp.back();
}
