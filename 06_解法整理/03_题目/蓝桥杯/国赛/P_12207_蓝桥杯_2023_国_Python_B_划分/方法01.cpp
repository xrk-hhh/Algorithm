// 原始稿：03_题目/蓝桥杯/国赛/P_12207_蓝桥杯_2023_国_Python_B_划分.cpp
// 原文行号：1-115；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 4e5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n = 40;
        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        // 01背包：bitset 优化
        // 大小至少为 sum + 1
        // dp[i] = true/false 表示能否选出和为 i 的子集。
        bitset<N> dp;
        dp[0] = 1;
        for (ll x : a)
        {
            dp |= (dp << x);
        }

        ll ans = 0;
        for (int i = 0; i < sum; i++)
        {
            if (dp[i])
            {
                ans = max(ans, i * (sum - i));
            }
        }

        cout<<ans<<endl;
        // 12873625444

        // // 当 ai 值较大时，使用折半搜索
        // // 将 40 个数分成两半（各约 20 个），分别枚举所有子集的和，得到两个数组 b, c
        // // 然后对 c 排序，对 b 中每个和 x，二分查找最接近 sum / 2 - x的值
        // // 得到候选总和，计算乘积。

        // int m = n >> 1;
        // vector<ll> b, c;
        // for (int mask = 0; mask < (1 << m); mask++)
        // {
        //     ll s = 0;
        //     for (int i = 0; i < m; i++)
        //     {
        //         if (mask >> i & 1)
        //         {
        //             s += a[i];
        //         }
        //     }

        //     b.push_back(s);
        // }
        // for (int mask = 0; mask < (1 << (n - m)); mask++)
        // {
        //     ll s = 0;
        //     for (int i = 0; i < n - m; i++)
        //     {
        //         if (mask >> i & 1)
        //         {
        //             s += a[m + i];
        //         }
        //     }

        //     c.push_back(s);
        // }

        // sort(c.begin(), c.end());
        // // 去重优化二分
        // c.erase(unique(c.begin(), c.end()), c.end());

        // ll ans = 0;
        // for (ll x : b)
        // {
        //     ll tar = (sum >> 1) - x;
        //     auto it = lower_bound(c.begin(), c.end(), tar);
        //     // 检查附近几个值
        //     for (int d = -1; d <= 1; d++)
        //     {
        //         if (it + d >= c.begin() && it + d < c.end())
        //         {
        //             ll y = *(it + d);
        //             ll s = x + y;
        //             if (s > 0 && s < sum)
        //             {
        //                 ans = max(ans, s * (sum - s));
        //             }
        //         }
        //     }
        // }

        // cout<<ans<<endl;
        // // 12873625444

        // cout<<"12873625444"<<endl;
    }

    return 0;
}
