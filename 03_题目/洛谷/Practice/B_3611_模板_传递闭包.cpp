// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         int n;
// //         cin>>n;

// //         vector<vector<int>> a(n, vector<int>(n));
// //         for (int i = 0; i < n; i++)
// //         {
// //             for (int j = 0; j < n; j++)
// //             {
// //                 cin>>a[i][j];
// //             }
// //         }

// //         // Floyd-Warshall 计算传递闭包
// //         for (int k = 0; k < n; k++)
// //         {
// //             for (int i = 0; i < n; i++)
// //             {
// //                 for (int j = 0; j < n; j++)
// //                 {
// //                     if (a[i][k] && a[k][j])
// //                     {
// //                         a[i][j] = 1;
// //                     }
// //                 }
// //             }
// //         }

// //         for (int i = 0; i < n; i++)
// //         {
// //             for (int j = 0; j < n; j++)
// //             {
// //                 cout<<a[i][j]<<' ';
// //             }
// //             cout<<endl;
// //         }
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

//         vector<bitset<100>> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 int x;
//                 cin>>x;

//                 if (x)
//                 {
//                     a[i].set(j);
//                 }
//             }
//         }

//         // bitset优化
//         for (int k = 0; k < n; k++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 if (a[i][k])
//                 {
//                     // 将 k 所能到达的所有节点也加入到 i 的可达集合中
//                     a[i] |= a[k];
//                 }
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cout<<a[i][j]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }