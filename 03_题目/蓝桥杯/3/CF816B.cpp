// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXX = 2e5;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, k, q;
//         cin>>n>>k>>q;

//         // 区间覆盖计数问题

//         // 差分数组，表示每个区间对覆盖次数的贡献
//         vector<int> d(MAXX + 2, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             int l, r;
//             cin>>l>>r;

//             d[l]++;
//             d[r + 1]--;
//         }

//         // 对 d 求前缀和得到每个温度点的实际覆盖次数
//         for (int i = 1; i <= MAXX; i++)
//         {
//             d[i] += d[i - 1];
//         }

//         // 用 sum 数组记录前缀中满足覆盖次数 ≥ k 的温度点个数
//         vector<int> sum(MAXX + 1, 0);
//         for (int i = 1; i <= MAXX; i++)
//         {
//             if (d[i] >= k)
//             {
//                 sum[i] = sum[i - 1] + 1;
//             }
//             else
//             {
//                 sum[i] = sum[i - 1];
//             }
//         }

//         while (q--)
//         {
//             int a, b;
//             cin>>a>>b;

//             int ans = sum[b] - sum[a - 1];

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }