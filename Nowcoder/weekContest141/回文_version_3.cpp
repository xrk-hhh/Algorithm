// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int C = 26;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, q;
//         cin>>n>>q;

//         string s;
//         cin>>s;
//         s = " " + s;

//         vector<vector<int>> pre(C, vector<int>(n + 1, 0));
//         for (int c = 0; c < C; c++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 pre[c][i] = pre[c][i - 1] + ((s[i] - 'a') == c);
//             }
//         }

//         vector<vector<ll>> A(C, vector<ll>(n + 1, 0));
//         vector<vector<ll>> sum(C, vector<ll>(n + 1, 0));
//         for (int c = 0; c < C; c++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 A[c][i] = A[c][i - 1] + pre[c][i];
//                 sum[c][i] = sum[c][i - 1] + 1LL * pre[c][i - 1] * pre[c][i];
//             }
//         }

//         while (q--)
//         {
//             int l, r, x;
//             cin>>l>>r>>x;

//             if (x == 1)
//             {
//                 cout<<r - l + 1<<endl;
//             }
//             else if (x == 2)
//             {
//                 ll ans = 0;
//                 for (int c = 0; c < C; c++)
//                 {
//                     ll cnt = pre[c][r] - pre[c][l - 1];

//                     ans += cnt * (cnt - 1) >> 1;
//                 }

//                 cout<<ans<<endl;
//             }
//             else
//             {
//                 ll ans = 0;
//                 for (int c = 0; c < C; c++)
//                 {
//                     ll pr = pre[c][r], pl = pre[c][l - 1];
//                     ll sum1 = A[c][r - 1] - (l - 2 >= 0 ? A[c][l - 2] : 0);
//                     ll sum2 = A[c][r] - A[c][l - 1];
//                     ll sum3 = sum[c][r] - sum[c][l - 1];

//                     ll t = pr * sum1 - sum3 - pl * pr * (r - l + 1) + pl * sum2;

//                     ans += t;
//                 }

//                 cout<<ans<<endl;
//             }
//         }
//     }

//     return 0;
// }