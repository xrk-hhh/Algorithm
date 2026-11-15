// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, K;
//         cin>>n>>K;

//         //    (a + b + c) % K = 0 
//         // -> (a % K + b % K + c % K) = (0 or K or 2K)

//         // 按余数分类
//         vector<vector<ll>> maxx(K, vector<ll>(3, 0));
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin>>a;

//             int mod = a % K;
//             // 维护最大的三个数
//             if (maxx[mod][0] < a)
//             {
//                 maxx[mod][2] = maxx[mod][1];
//                 maxx[mod][1] = maxx[mod][0];
//                 maxx[mod][0] = a;
//             }
//             else if (maxx[mod][1] < a)
//             {
//                 maxx[mod][2] = maxx[mod][1];
//                 maxx[mod][1] = a;
//             }
//             else if (maxx[mod][2] < a)
//             {
//                 maxx[mod][2] = a;
//             }
//         }

//         ll ans = 0;
//         // 第一个余数
//         for (int i = 0; i < K; i++)
//         {
//             // 第二个余数
//             for (int j = 0; j < K; j++)
//             {
//                 // 三种可能的余数和
//                 for (int l = 0; l <= 2 * K; l += K)
//                 {
//                     // 第三个余数
//                     int x = l - i - j;
//                     if (x < 0 || x >= K)
//                     {
//                         continue;
//                     }
//                     // 注意重复余数的情况
//                     ll sum = maxx[i][0] + maxx[j][i == j] + maxx[x][(i == x) + (j == x)];
//                     if (sum > ans)
//                     {
//                         ans = sum;
//                     }
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }