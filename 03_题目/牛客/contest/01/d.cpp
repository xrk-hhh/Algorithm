// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n + 1);
//         vector<int> nxt(n + 1);
//         int cnt = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             if (a[i] > 0)
//             {
//                 cnt++;
//             }
//             nxt[i] = max(nxt[i - 1], i + a[i]);
//         }

//         if (cnt <= k)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         auto check = [&](int mid) -> bool
//         {
//             int i = 1;
//             while (i <= n && a[i] == 0)
//             {
//                 i++;
//             }

//             int ans = 1;
//             int tim = 0;

//             while (i <= n)
//             {
//                 tim++;
//                 i = nxt[i];

//                 if (i >= n)
//                 {
//                     break;
//                 }

//                 if (i == nxt[i])
//                 {
//                     while (i <= n && i == nxt[i])
//                     {
//                         i++;
//                     }

//                     if (i <= n)
//                     {
//                         tim = 0;
//                         ans++;
//                     }
//                 }
//                 else
//                 {
//                     if (tim == mid)
//                     {
//                         i++;
//                         while (i <= n && a[i] == 0)
//                         {
//                             i++;
//                         }

//                         if (i <= n)
//                         {
//                             tim = 0;
//                             ans++;
//                         }
//                     }
//                 }
//             }
//             return ans <= k;
//         };

//         int l = 1, r = n;
//         while (l < r)
//         {
//             int mid = (l + r) / 2;

//             if (check(mid))
//             {
//                 r = mid;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         if (!check(l))
//         {
//             l = -1;
//         }

//         cout<<l<<endl;
//     }

//     return 0;
// }