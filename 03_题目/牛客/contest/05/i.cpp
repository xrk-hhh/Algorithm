// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define i128 __int128_t

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m;
//         ll h;
//         cin>>n>>m>>h;

//         vector<int> vp(m), vf(m);
//         for (int i = 0; i < m; i++)
//         {
//             cin>>vp[i]>>vf[i];
//         }

//         auto check = [&](int k) -> bool
//         {
//             vector<ll> dif1(n + 2, 0), dif2(n + 2, 0);
//             for (int i = 0; i < k; i++)
//             {
//                 int p = vp[i];
//                 ll f = vf[i];

//                 int l = max(1, p - (int)f + 1);
//                 int r = min(n, p + (int)f - 1);

//                 if (l <= p - 1)
//                 {
//                     dif1[l] += f - p;
//                     dif1[p] -= f - p;

//                     dif2[l] += 1;
//                     dif2[p] -= 1;
//                 }

//                 dif1[p] += f + p;
//                 dif1[r + 1] -= f + p;

//                 dif2[p] -= 1;
//                 dif2[r + 1] += 1;
//             }

//             ll sum1 = 0, sum2 = 0;
//             for (int j = 1; j <= n; j++)
//             {
//                 sum1 += dif1[j];
//                 sum2 += dif2[j];

//                 i128 d = (i128)sum1 + (i128)sum2 * j;

//                 if (d > h)
//                 {
//                     return true;
//                 }
//             }
//             return false;
//         };

//         int l = 1, r = m;
//         int ans = m + 1;

//         while (l <= r)
//         {
//             int mid = (l + r) / 2;

//             if (check(mid))
//             {
//                 ans = mid;
//                 r = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         if (ans == m + 1)
//         {
//             cout<<"No"<<endl;
//         }
//         else
//         {
//             cout<<"Yes"<<endl;
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }