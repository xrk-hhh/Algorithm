// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 2000;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int t, k;
//         cin>>t>>k;

//         // 预处理所有组合数模 k
//         vector<vector<int>> C(N + 1, vector<int>(N + 1, 0));
//         for (int i = 0; i <= N; i++)
//         {
//             C[i][0] = C[i][i] = 1 % k;
//             for (int j = 1; j < i; j++)
//             {
//                 C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
//             }
//         }

//         // 二维前缀和：满足条件的个数
//         vector<vector<int>> pre(N + 1, vector<int>(N + 1, 0));
//         for (int i = 0; i <= N; i++)
//         {
//             // 该行满足条件个数
//             vector<int> row(N + 1, 0);
//             for (int j = 0; j <= N; j++)
//             {
//                 if (j <= i && C[i][j] == 0)
//                 {
//                     row[j] = 1;
//                 }
//                 if (j > 0)
//                 {
//                     row[j] += row[j - 1];
//                 }
//             }

//             for (int j = 0; j <= N; j++)
//             {
//                 // 上一行
//                 int up = (i > 0 ? pre[i - 1][j] : 0);

//                 // pre[i][j] = pre[i - 1][j] + row[i][min(i, j)]
//                 pre[i][j] = up + row[min(i, j)];
//             }
//         }

//         while (t--)
//         {
//             int n, m;
//             cin>>n>>m;

//             cout<<pre[n][m]<<endl;
//         }
//     }

//     return 0;
// }