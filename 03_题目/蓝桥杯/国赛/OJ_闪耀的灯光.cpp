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
//         int n, m, c;
//         cin>>n>>m>>c;

//         vector<vector<int>> a(n + 1, vector<int>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
//             }
//         }

//         int t;
//         cin>>t;

//         while (t--)
//         {
//             int x1, y1, x2, y2, k;
//             cin>>x1>>y1>>x2>>y2>>k;

//             // 最多减 c 次,再减就变成减 0 了
//             // 那么,也就是等价于减 k % (c+1) 次
//             int sub = k % (c + 1);

//             ll ans = pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] + pre[x1 - 1][y1 - 1] - sub * (x2 - x1 + 1) * (y2 - y1 + 1);

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }