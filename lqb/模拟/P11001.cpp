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

//         vector<vector<int>> a(n, vector<int>(m));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 // 枚举行
//                 for (int k = 1; i + k < n; k++)
//                 {
//                     // 右下
//                     if (j + k < m && a[i][j] == a[i + k][j + k])
//                     {
//                         ans++;
//                     }
//                     // 左下
//                     if (j - k >= 0 && a[i][j] == a[i + k][j - k])
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }

//         // 答案需要 * 2
//         // 注意：(1, 2) - (2, 1) 和 (2, 1) - (1, 2)是 2 对
//         // 故需考虑左上、左下、右上、右下
//         // 而从上往下枚举时，只需考虑下方的，最后再乘 2 即可
//         cout<<ans * 2<<endl;
//     }

//     return 0;
// }