// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXV = 2e4 + 10;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, V;
//         cin>>V>>n;

//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>v[i];
//         }

//         // vector<bool> dp(V + 1, false);
//         // dp[0] = true;
//         // for (int x : v)
//         // {
//         //     for (int i = V; i >= x; i--)
//         //     {
//         //         if (dp[i - x])
//         //         {
//         //             dp[i] = true;
//         //         }
//         //     }
//         // }

//         // 01 背包
//         bitset<MAXV> dp;
//         dp[0] = true;
//         for (int x : v)
//         {
//             dp |= (dp << x);
//         }

//         int maxx = 0;
//         for (int i = V; i >= 0; i--)
//         {
//             if (dp[i])
//             {
//                 maxx = i;
//                 break;
//             }
//         }

//         cout<<V - maxx<<endl;
//     }

//     return 0;
// }