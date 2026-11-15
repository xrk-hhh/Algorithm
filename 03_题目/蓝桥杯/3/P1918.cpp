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

//         // 方法一：哈希表，时间复杂度 O(n)

//         // 键：瓶子数，值：位置
//         // unordered_map<int, int> pos;
//         // for (int i = 1; i <= n; i++)
//         // {
//         //     int x;
//         //     cin>>x;

//         //     pos[x] = i;
//         // }

//         // int Q;
//         // cin>>Q;

//         // while (Q--)
//         // {
//         //     int m;
//         //     cin>>m;

//                 // 查找键
//         //     auto it = pos.find(m);

//         //     if (it != pos.end())
//         //     {
//         //         cout<<it->second<<endl;
//         //     }
//         //     else
//         //     {
//         //         cout<<0<<endl;
//         //     }
//         // }

//         // 方法二：排序 + 二分查找，时间复杂度 O(nlongn)

//         // 瓶子数，位置
//         vector<pair<int, int>> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i].first;
//             a[i].second = i + 1;
//         }

//         // 按瓶子数排序
//         sort(a.begin(), a.end());

//         int Q;
//         cin>>Q;

//         while (Q--)
//         {
//             int m;
//             cin>>m;

//             // 二分查找瓶子数等于 m 的位置
//             int l = 0, r = n - 1;
//             int ans = 0;
//             while (l <= r)
//             {
//                 int mid = (l + r) >> 1;
//                 if (a[mid].first < m)
//                 {
//                     l = mid + 1;
//                 }
//                 else if (a[mid].first > m)
//                 {
//                     r = mid - 1;
//                 }
//                 else
//                 {
//                     ans = a[mid].second;
//                     break;   
//                 }
//             }
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }