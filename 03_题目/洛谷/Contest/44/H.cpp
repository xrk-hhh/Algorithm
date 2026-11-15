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
//         int n, m, d;
//         cin>>n>>m>>d;

//         vector<vector<int>> a(n + 1, vector<int>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         int ans = -1;
//         // 枚举子矩阵
//         // 左上角为(i1，j1)，右上角为(i2，j2)
//         for (int i1 = 1; i1 <= n; i1++)
//         {
//             for (int i2 = i1; i2 <= n; i2++)
//             {
//                 for (int j1 = 1; j1 <= m; j1++)
//                 {
//                     for (int j2 = j1; j2 <= m; j2++)
//                     {
//                         // n*m 最大为 400，即最多有 400 种颜色
//                         vector<bool> color(400, false);
//                         // 遍历子矩阵，看看有什么颜色（什么颜色存在）
//                         for (int i = i1; i <= i2; i++)
//                         {
//                             for (int j = j1; j <= j2; j++)
//                             {
//                                 color[a[i][j]] = true;
//                             }
//                         }

//                         int cnt = 0;
//                         // 计算子矩阵中颜色种数
//                         for (int c = 1; c <= 400; c++)
//                         {
//                             if (color[c])
//                             {
//                                 cnt++;
//                             }
//                         }

//                         // 满足颜色种数为 d
//                         if (cnt == d)
//                         {
//                             int S = (i2 - i1 + 1) * (j2 - j1 + 1);
//                             ans = max(ans, S);
//                         }
//                     }
//                 }
//             }
//         }

//         if (ans == -1)
//         {
//             cout<<"Hrk"<<endl;
//         }
//         else
//         {
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }