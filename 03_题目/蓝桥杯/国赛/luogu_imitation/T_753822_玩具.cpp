// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // const int mod = 998244353;
// // const int N = 26, tarN = 5;
// // const string s = "abcdefghijklmnopqrstuvwxyz";
// // const string tar = "aeiou";
// // const int tarx = 341799, tary = 5;

// // ll ans = 0;
// // vector<vector<char>> g; 

// // void dfs(int x, int y, ll cnt)
// // {
// //     if (x == tarx && y == tary)
// //     {
// //         ans = max(ans, cnt);
// //         return;
// //     }

// //     for (int i = 0; i < N; i++)
// //     {
// //         bool ok = false;
// //         for (int j = 0; j < tarN; j++)
// //         {
// //             if (g[x][y] == tar[j])
// //             {
// //                 ok = true;
// //                 break;
// //             }
// //         }

// //         ll ncnt;
// //         if (ok)
// //         {
// //             ncnt = cnt * (N - tarN) % mod;
// //         }
// //         else
// //         {
// //             ncnt = cnt * N % mod;
// //         }
        
// //         if (y < tary)
// //         {
// //             if (x < tarx && (y & 1))
// //             {
// //                 g[x + 1][y] = s[i];
// //                 dfs(x + 1, y, ncnt);
// //             }
// //             else if (x == tarx && (y & 1))
// //             {
// //                 g[x][y + 1] = s[i];
// //                 dfs(x, y + 1, ncnt);
// //             }
// //             else if (x == tarx && (!(y & 1)))
// //             {
// //                 g[1][y] = s[i];
// //                 dfs(1, y, ncnt);
// //             }
// //             else if (x == 1 && (!(y & 1)))
// //             {
// //                 g[1][y + 1] = s[i];
// //                 dfs(x, y + 1, ncnt);
// //             }
// //         }
// //         else
// //         {
// //             g[x + 1][y] = s[i];
// //             dfs(x + 1, y, ncnt);
// //         }
// //     }
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         g.resize(tarx + 1, vector<char>(tary + 1));

// //         dfs(1, 1, 1);

// //         cout<<ans<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int MOD = 998244353;
// const int R = 341799;                // 行数
// const int L = R - 1;                 // 垂直链边数

// // 2x2 矩阵乘法
// struct Mat {
//     ll a[2][2];
//     Mat() { memset(a, 0, sizeof(a)); }
//     Mat operator*(const Mat& o) const {
//         Mat res;
//         for (int i = 0; i < 2; ++i)
//             for (int k = 0; k < 2; ++k)
//                 for (int j = 0; j < 2; ++j)
//                     res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
//         return res;
//     }
// };

// Mat mat_pow(Mat a, int p) {
//     Mat res;
//     res.a[0][0] = res.a[1][1] = 1;
//     while (p) {
//         if (p & 1) res = res * a;
//         a = a * a;
//         p >>= 1;
//     }
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 权重：0 辅音(21), 1 元音(5)
//     ll w[2] = {21, 5};

//     // 垂直链转移矩阵 A[s][t] = 0 if s=t=1 else w[t]
//     Mat A;
//     for (int s = 0; s < 2; ++s)
//         for (int t = 0; t < 2; ++t)
//             A.a[s][t] = (s == 1 && t == 1) ? 0 : w[t];

//     // A 的 L 次幂
//     Mat M = mat_pow(A, L);

//     // 生成长度为5的合法状态（没有相邻的1）
//     vector<int> valid;
//     for (int mask = 0; mask < 32; ++mask) {
//         bool ok = true;
//         for (int i = 0; i < 4; ++i) {
//             if (((mask >> i) & 1) && ((mask >> (i + 1)) & 1)) {
//                 ok = false; break;
//             }
//         }
//         if (ok) valid.push_back(mask);
//     }

//     ll ans = 0;
//     for (int S : valid) {
//         int S1 = (S >> 0) & 1, S2 = (S >> 1) & 1, S3 = (S >> 2) & 1,
//             S4 = (S >> 3) & 1, S5 = (S >> 4) & 1;
//         ll top_w = w[S1] * w[S2] % MOD * w[S3] % MOD * w[S4] % MOD * w[S5] % MOD;

//         for (int T : valid) {
//             int T1 = (T >> 0) & 1, T2 = (T >> 1) & 1, T3 = (T >> 2) & 1,
//                 T4 = (T >> 3) & 1, T5 = (T >> 4) & 1;

//             ll vert = M.a[S1][T1] * M.a[S3][T3] % MOD * M.a[S5][T5] % MOD;
//             ll bottom_extra = w[T2] * w[T4] % MOD;   // 列2,4的底部权重（列1,3,5已在M中）

//             ll add = top_w * vert % MOD * bottom_extra % MOD;
//             ans = (ans + add) % MOD;
//         }
//     }

//     cout << ans << '\n';
//     return 0;
// }