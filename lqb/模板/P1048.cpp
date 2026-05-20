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

//         vector<int> tt(m), v(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>tt[i]>>v[i];
//         }

//         // 01背包（采药）
//         vector<int> dp(t + 1, 0);
//         int cur = 0;
//         for (int i = 0; i < m; i++)
//         {
//             // 倒序更新，保证 dp[j - tt[i]]还没有被当前物品更新，以保证每个物品只取一次
//             for (int j = t; j >= tt[i]; j--)
//             {
//                 dp[j] = max(dp[j], dp[j - tt[i]] + v[i]);
//             }
//         }

//         cout<<dp[t]<<endl;
//     }

//     return 0;
// }