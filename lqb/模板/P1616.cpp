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
//         int t, m;
//         cin>>t>>m;

//         vector<int> a(m), b(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>a[i]>>b[i];
//         }

//         // 完全背包（疯狂的采药）
//         vector<ll> dp(t + 1, 0);
//         for (int i = 0; i < m; i++)
//         {
//             // 正序，因为每个物品可以取无限次
//             for (int j = a[i]; j <= t; j++)
//             {
//                 dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
//             }
//         }

//         cout<<dp[t]<<endl;
//     }

//     return 0;
// }