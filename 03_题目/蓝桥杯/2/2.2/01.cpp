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
//         int n;
//         cin>>n;

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<ll> sum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             sum[i] = sum[i - 1] + a[i];
//         }

//         set<tuple<ll, int, int>> S;

//         for (int l = 1; l <= n; l++)
//         {
//             for (int r = l; r <= n; r++)
//             {
//                 S.insert({sum[r] - sum[l - 1], l, r});
//             }
//         }

//         ll ans = 1e18;
//         for (int i = 1; i < n; i++)
//         {
//             for (int r = i; r <= n; r++)
//             {
//                 ll val = sum[r] - sum[i - 1];
//                 S.erase({val, i, r});
//             }
            
//             for (int j = 1; j <= i; j++)
//             {
//                 ll cur = sum[i] - sum[j - 1];

//                 auto it = S.lower_bound({cur, INT_MIN, INT_MIN});

//                 if (it != S.end())
//                 {
//                     ans = min(ans, llabs(get<0>(*it) - cur));
//                 }
//                 if (it != S.begin())
//                 {
//                     it--;
//                     ans = min(ans, llabs(get<0>(*it) - cur));
//                 }
//             }
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }