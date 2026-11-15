// 原始稿：03_题目/蓝桥杯/国赛/P_9420_蓝桥杯_2023_国_B_子_2023_双子数.cpp
// 原文行号：1-160；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 欧式筛
vector<int> linearSieve(int n)
{
    vector<bool> isComposite(n + 1, false);
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (!isComposite[i])
        {
            primes.push_back(i);
        }

        for (int p : primes)
        {
            if (i * p > n)
            {
                break;
            }

            isComposite[i * p] = true;
            if (i % p == 0)
            {
                break;
            }
        }
    }

    return primes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        // string s;
        // for (int i = 1; i <= 2023; i++)
        // {
        //     s += to_string(i);
        // }

        // vector<ll> dp(5, 0);
        // dp[0] = 1;
        // for (char c : s)
        // {
        //     if (c == '2')
        //     {
        //         dp[3] += dp[2];
        //         dp[1] += dp[0];
        //     }
        //     else if (c == '0')
        //     {
        //         dp[2] += dp[1];
        //     }
        //     else if (c == '3')
        //     {
        //         dp[4] += dp[3];
        //     }
        // }

        // ll ans1 = dp[4];

        // cout<<ans1<<endl;
        // // 5484660609

        // l <= p²q² <= r
        // 即 sqrt(l) <= pq <= sqrt(r)
        // 那么，就可以固定 p，然后在 primes 中二分查找 q，且 p < q

        // ll l = 2333, r = 23333333333333;
        // ll L = ceil(sqrtl(l)), R = sqrtl(r);

        // vector<int> primes = linearSieve(R);
        // int m = primes.size();

        // ll ans2 = 0;
        // for (int i = 0; i < m; i++)
        // {
        //     int p = primes[i];
        //     // 向上取整
        //     ll low = (L + p - 1) / p;
        //     // 向下取整
        //     ll high = R / p;
        //     if (low <= p)
        //     {
        //         low = p + 1;
        //     }
        //     if (low > high)
        //     {
        //         continue;
        //     }

        //     // 在 primes 中二分查找 q
        //     int lL = lower_bound(primes.begin(), primes.end(), low) - primes.begin();
        //     int rR = upper_bound(primes.begin(), primes.end(), high) - primes.begin() - 1;

        //     if (lL <= rR)
        //     {
        //         ans2 += rR - lL + 1;
        //     }
        // }

        // cout<<ans2<<endl;
        // // // 947303
        // // 947293

        ll l = 2333, r = 23333333333333;
        int n = sqrtl(r);
        vector<int> primes = linearSieve(n);
        int m = primes.size();

        ll ans2 = 0;
        for (int i = 0; i < m; i++)
        {
            int p = primes[i];
            for (int j = i + 1; j < m; j++)
            {
                int q = primes[j];

                ll t = 1LL * p * q;
                t = t * t;
                if (t > r)
                {
                    break;
                }

                if (t >= l && t <= r)
                {
                    ans2++;
                }
            }
        }

        cout<<ans2<<endl;


        // string ans[] = 
        // {
        //     "5484660609",
        //     "947293"
        // };
        // char op;
        // cin>>op;

        // cout<<ans[op - 'A']<<endl;
    }

    return 0;
}
