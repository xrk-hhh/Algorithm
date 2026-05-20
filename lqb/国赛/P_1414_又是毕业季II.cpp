// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXV = 1e6 + 10;
// int freq[MAXV], cnt[MAXV];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         int maxv = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;

//             freq[x]++;
//             maxv = max(maxv, x);
//         }

//         // 计算每个 d 的倍数个数
//         for (int d = 1; d <= maxv; d++)
//         {
//             for (int m = d; m <= maxv; m += d)
//             {
//                 cnt[d] += freq[m];
//             }
//         }

//         vector<int> ans(n + 1, 0);
//         // 从大到小枚举 d，保证第一次赋值给 k 的就是最大的 d
//         for (int d = maxv; d >= 1; d--)
//         {
//             int c = cnt[d];
//             for (int k = 1; k <= c && k <= n; k++)
//             {
//                 if (ans[k] == 0)
//                 {
//                     ans[k] = d;
//                 }
//             }
//         }

//         for (int k = 1; k <= n; k++)
//         {
//             cout<<ans[k]<<endl;
//         }
//     }

//     return 0;
// }