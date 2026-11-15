// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, k;
//         cin>>n>>k;

//         // 先计算前缀和模 k
//         vector<int> sum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             int a;
//             cin>>a;

//             sum[i] = (sum[i - 1] + a) % k;
//         }

//         // 再求前缀和模 k 余数为 r 的出现次数
//         vector<int> cnt(k, 0);
//         // sum[0] = 0，所以cnt[0] + 1
//         cnt[0]++;
//         for (int i = 1; i <= n; i++)
//         {
//             int r = sum[i];
//             cnt[r]++;
//         }

//         // 对于每个余数 r ，出现次数为cnt[r]，
//         // 区间为[l, r]，区间和为 sum[r] - sum[l - 1]
//         // 本题中，区间长度至少为 1
//         // 则要构成区间，得选两个位置
//         // C(cnt[r], 2)
//         ll ans = 0;
//         for (int r = 0; r < k; r++)
//         {
//             ans += (1LL * cnt[r] * (cnt[r] - 1) / 2);
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }