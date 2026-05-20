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

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int sum = 0;
//             int x = i;
//             int idx = 1;
//             // 是否取走了
//             vector<bool> vis(n + 1, false);
//             while (true)
//             {
//                 if (!vis[x])
//                 {
//                     if (a[x] == idx)
//                     {
//                         sum += a[x];
//                         // 重新数数
//                         idx = 0;
//                         vis[x] = true;
//                     }
//                     idx++;
//                 }
//                 // 当 x = n时，+1 后变为 1
//                 x = x % n + 1;
//                 // 无法再取牌了
//                 if (idx > n || sum == n * (n + 1) / 2)
//                 {
//                     break;
//                 }
//             }
//             ans = max(ans, sum);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }