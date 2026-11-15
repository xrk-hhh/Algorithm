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
//         int n, m;
//         cin>>n>>m;

//         vector<ll> a(n), b(m);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin>>b[i];
//         }

//         int ans = 0;
//         // 处理两个数组，且涉及各自的合并操作
//         // 可考虑双指针
//         // 要求对应相等
//         // 则可直接遍历，该项不等，小的合并下一项即可
//         for (int i = 0, j = 0; i < n && j < m; )
//         {
//             if (a[i] == b[j])
//             {
//                 i++;
//                 j++;
//                 continue;
//             }

//             ll t1 = a[i], t2 = b[j];
//             while (t1 != t2)
//             {
//                 if (t1 > t2)
//                 {
//                     j++;
//                     t2 += b[j];
//                 }
//                 else if (t1 < t2)
//                 {
//                     i++;
//                     t1 += a[i];
//                 }
//                 ans++;
//             }
//             i++;
//             j++;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }