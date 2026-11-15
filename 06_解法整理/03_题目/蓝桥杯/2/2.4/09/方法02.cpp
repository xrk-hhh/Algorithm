// 原始稿：03_题目/蓝桥杯/2/2.4/09.cpp
// 原文行号：103-166；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        // 正确性说明：
        // 若两个数 x 和 y 满足 x & y ≠ 0，则存在至少一位 b 使得两者在该位均为1。
        // 因此，x 可以接在任何一个以某位为1结尾的序列后面，只要该位也在 x 中为1。

        // dp[i] 表示当前已遍历的所有数字中，以某个数字结尾且该数字的第 b 位为 1 的最长子序列的长度。

        int n;
        cin>>n;

        // 1e9 < 2^30
        vector<int> dp(31, 0);
        int maxx = 0;
        // 遍历每个数
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            
            // 计算以x结尾的最长长度 cur
            int cur = 0;
            for (int b = 0; b < 31; b++)
            {
                if ((x >> b) & 1)
                {
                    cur = max(cur, dp[b]);
                }
            }
            // 加上当前数
            cur++;

            // 更新 dp 数组
            for (int b = 0; b < 31; b++)
            {
                if ((x >> b) & 1)
                {
                    dp[b] = max(dp[b], cur);
                }
            }
            
            // 更新全局答案
            maxx = max(maxx, cur);
        }

        cout<<maxx<<endl;
    }

    return 0;
}
