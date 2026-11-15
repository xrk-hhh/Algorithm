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
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<int> add(n / 2, 0);
//         vector<int> sub(n / 2, 0);
//         for (int i = 0; i < n / 2; i++)
//         {
//             int dif = a[n - 1 - i] - a[i];
//             if (dif > 0)
//             {
//                 add[i] = dif;
//             }
//             else if (dif < 0)
//             {
//                 sub[i] = -dif;
//             }
//         }

//         // 注意需要开 ll
//         ll ans = 0;
//         for (int i = 0; i < n / 2; i++)
//         {
//             ll cnt = 0;
//             if (add[i] && add[i + 1] && i + 1 < n / 2)
//             {
//                 cnt += min(add[i], add[i + 1]);
//                 add[i] -= cnt;
//                 add[i + 1] -= cnt;
//             }
//             if (add[i])
//             {
//                 cnt += add[i];
//                 add[i] = 0;
//             }

//             if (sub[i] && sub[i + 1] && i + 1 < n / 2)
//             {
//                 cnt += min(sub[i], sub[i + 1]);
//                 sub[i] -= cnt;
//                 sub[i + 1] -= cnt;
//             }
//             if (sub[i])
//             {
//                 cnt += sub[i];
//                 sub[i] = 0;
//             }

//             ans += cnt;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }