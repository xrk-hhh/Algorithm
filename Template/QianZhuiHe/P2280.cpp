// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 5010;
// const int N = 5001;

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

//         vector<vector<int>> s(MAXN, vector<int>(MAXN, 0));

//         for (int i = 0; i < n; i++)
//         {
//             int x, y, v;
//             cin>>x>>y>>v;

//             x++, y++;
//             s[x][y] += v;
//         }

//         // 方法一：容斥原理求二维前缀和，复杂度为(O(2^k * n^k))

//         // for (int i = 1; i <= N; i++)
//         // {
//         //     for (int j = 1; j <= N; j++)
//         //     {
//         //         s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
//         //     }
//         // }


//         // 方法二：先求一维，再求二维（先算第i行前j列，然后再算前i行），复杂度为(O(k * n^k))

//         for (int i = 1; i <= N; i++)
//         {
//             for (int j = 1; j <= N; j++)
//             {
//                 s[i][j] += s[i][j - 1];
//             }
//         }

//         for (int j = 1; j <= N; j++)
//         {
//             for (int i = 1; i <= N; i++)
//             {
//                 s[i][j] += s[i - 1][j];
//             }
//         }

//         // 求高维前缀和时，方法二更好

//         int res = 0;
//         for (int i = m; i <= N; i++)
//         {
//             for (int j = m; j <= N; j++)
//             {
//                 res = max(res, s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m]);
//             }
//         }

//         cout<<res<<endl;
//     }

//     return 0;
// }