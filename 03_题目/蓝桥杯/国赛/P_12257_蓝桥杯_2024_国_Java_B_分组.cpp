// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // int n;
// // vector<int> a;

// // bool check(int x)
// // {
// //     for (int i = 0; i < x; i++)
// //     {
// //         // a[0],a[1],..,a[x-1] 与 a[n-x],a[n-x+1],...,a[n-1] 一一配对
// //         // 即最小的 x 个与最大的 x 个配对
// //         if (a[n - x + i] < (a[i] << 1))
// //         {
// //             return false;
// //         }
// //     }

// //     return true;
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         cin>>n;
// //         a.resize(n);
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin>>a[i];
// //         }

// //         sort(a.begin(), a.end());

// //         // 特判一下，(全局 max < min * 2) 和 (n < 2)
// //         if ((a[n - 1] < (a[0] << 1)) || n < 2)
// //         {
// //             cout<<0<<endl;
// //             return 0;
// //         }

// //         // 二分答案
// //         int l = 1, r = n >> 1;
// //         while (l < r)
// //         {
// //             int mid = (l + r + 1) >> 1;
// //             if (check(mid))
// //             {
// //                 l = mid;
// //             }
// //             else
// //             {
// //                 r = mid - 1;
// //             }
// //         }

// //         cout<<r<<endl;
// //     }

// //     return 0;
// // }

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

//         sort(a.begin(), a.end());

//         if ((a[n - 1] < (a[0] << 1)) || n < 2)
//         {
//             cout<<0<<endl;
//             return 0;
//         }

//         // 双指针，最低分和最高分
//         int ans = 0;
//         int l = (n >> 1) - 1, r = n - 1;
//         vector<bool> vis(n, false);
//         while (l >= 0)
//         {
//             if ((a[l] << 1) > a[r])
//             {
//                 l--;
//             }
//             else
//             {
//                 ans++;
//                 vis[l] = vis[r] = true;
//                 l--;
//                 r--;
//                 while (r >= 0 && vis[r])
//                 {
//                     r--;
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }