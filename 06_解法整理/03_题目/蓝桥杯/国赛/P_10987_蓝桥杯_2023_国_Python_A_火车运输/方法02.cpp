// 原始稿：03_题目/蓝桥杯/国赛/P_10987_蓝桥杯_2023_国_Python_A_火车运输.cpp
// 原文行号：69-136；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXA = 1e3 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, a, b;
        cin>>n>>a>>b;

        vector<int> w(n);
        for (int i = 0; i < n; i++)
        {
            cin>>w[i];
        }

        // dp[i] 为一个 bitset<B+1>：当 A 背包已用 i 时，B 背包所有可能的已用容量集合
        vector<bitset<MAXA>> dp(a + 1);
        dp[0].set(0);
        
        for (int x : w)
        {
            // 不选当前物品
            auto ndp = dp;
            // 倒序遍历 A 容量
            for (int i = a; i >= 0; i--)
            {
                // 放入 A
                if (i >= x)
                {
                    ndp[i] |= dp[i - x];
                }

                // 放入 B（左移 x 位）
                ndp[i] |= (dp[i] << x);
            }

            dp = move(ndp);
        }

        int ans = 0;
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= b; j++)
            {
                if (dp[i][j])
                {
                    ans = max(ans, i + j);
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
