// 原始稿：03_题目/蓝桥杯/国赛/P_12216_蓝桥杯_2023_国_Java_B_互质.cpp
// 原文行号：1-74；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// const int mod = 1e9 + 7;
// const int N = 2023;

// ll ksm(ll a, ll b)
// {
//     ll res = 1;
//     a = a % mod;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res * a % mod;
//         }
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        // int n = 2023;
        // for (int p = 2; p * p <= n; p++)
        // {
        //     if (n % p == 0)
        //     {
        //         int cnt = 0;
        //         while (n % p == 0)
        //         {
        //             n /= p;
        //             cnt++;
        //         }

        //         cout<<p<<'^'<<cnt;
        //         if (n > 1)
        //         {
        //             cout<<'*';
        //         }
        //     }
        // }
        // if (n > 1)
        // {
        //     cout<<n<<"^1";
        // }
        // cout<<endl;

        // 2023 = 7^1 * 17^2
        

        // ll ans = (7 - 1) * (17 - 1);
        // ans = ans * ksm(7, N - 1) % mod;
        // ans = ans * ksm(17, (N << 1) - 1) % mod;

        // cout<<ans<<endl;

        cout<<"640720414"<<endl;
    }

    return 0;
}
