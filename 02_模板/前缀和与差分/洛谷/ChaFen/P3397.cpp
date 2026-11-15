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
//         int n, m;
//         cin>>n>>m;

//         vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));

//         // 方法一：一维差分，将矩阵看成n行一维数组，处理修改复杂度为(O(nm))

//         // while (m--)
//         // {
//         //     int x1, y1, x2, y2;
//         //     cin>>x1>>y1>>x2>>y2;

//         //     for (int i = x1; i <= x2; i++)
//         //     {
//         //         a[i][y1]++;
//         //         a[i][y2 + 1]--;
//         //     }
//         // }

//         // for (int i = 1; i <= n; i++)
//         // {
//         //     for (int j = 1; j <= n; j++)
//         //     {
//         //         a[i][j] += a[i][j - 1];
//         //         cout<<a[i][j]<<' ';
//         //     }
//         //     cout<<endl;
//         // }

//         // 方法二：二维差分，类比二维前缀和，处理修改复杂度为(O(m))

//         while (m--)
//         {
//             int x1, y1, x2, y2;
//             cin>>x1>>y1>>x2>>y2;

//             a[x1][y1]++;
//             a[x1][y2 + 1]--;
//             a[x2 + 1][y1]--;
//             a[x2 + 1][y2 + 1]++;
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
//                 cout<<a[i][j]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }