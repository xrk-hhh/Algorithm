// // #include <bits/stdc++.h>
// // using namespace std;

// // #define ll long long
// // #define endl '\n'
// // #define INF 0x3f3f3f3f3f3f3f3fll

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int c;
// //     cin>>c;

// //     int T = 1;
// //     cin>>T;

// //     while (T--)
// //     {
// //         int n, k;
// //         cin>>n>>k;

// //         vector<int> a(n + 1);
// //         for (int i = 1; i <= n; i++)
// //         {
// //             cin>>a[i];
// //         }

// //         sort(a.begin(), a.end());

// //         ll minn = INF;
// //         ll ans = -INF;

// //         for (int i = 1; i <= n; i++)
// //         {
// //             ll tmp = 1LL * i * k - a[i];
// //             minn = min(tmp, minn);
// //             ans = max(ans, tmp - minn + k);
// //         }

// //         cout<<ans<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define INF 0x3f3f3f3f3f3f3f3fll

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int c;
//     cin>>c;

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         vector<ll> dp(n + 1);
//         dp[1] = k;
//         ll ans = -INF;

//         for (int i = 2; i <= n; i++)
//         {
//             ll tmp = dp[i - 1] + k - (a[i] - a[i - 1]);
//             dp[i] = max(k * 1LL, tmp);

//             ans = max(ans, dp[i]);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }