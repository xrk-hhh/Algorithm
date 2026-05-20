// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define ull unsigned long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n, m, q;
//         cin>>n>>m>>q;

//         vector<vector<ull>> sum(n + 1, vector<ull>(m + 1, 0));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 ull x;
//                 cin>>x;

//                 sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
//             }
//         }


//         ull ans = 0;

//         while (q--)
//         {
//             int u, v, x, y;
//             cin>>u>>v>>x>>y;

//             ull res = sum[x][y] - sum[u - 1][y] - sum[x][v - 1] + sum[u - 1][v - 1];

//             ans ^= res;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }