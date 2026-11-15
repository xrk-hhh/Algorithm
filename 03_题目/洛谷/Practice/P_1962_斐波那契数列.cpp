// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e9 + 7;

// // 2×2 矩阵结构体
// struct Mat
// {
//     ll a[2][2];
//     Mat()
//     {
//         memset(a, 0, sizeof(a));
//     }

//     // 矩阵乘法
//     Mat operator*(const Mat& other) const
//     {
//         Mat res;
//         for (int i = 0; i < 2; i++)
//         {
//             for (int k = 0; k < 2; k++)
//             {
//                 if (a[i][k])
//                 {
//                     for (int j = 0; j < 2; j++)
//                     {
//                         res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % mod;
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };

// // 矩阵快速幂
// Mat ksm(Mat a, ll b)
// {
//     Mat res;
//     // 单位矩阵
//     res.a[0][0] = res.a[1][1] = 1;

//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res * a;
//         }
//         a = a * a;
//         b >>= 1;
//     }

//     return res;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         ll n;
//         cin>>n;

//         if (n == 1 || n == 2)
//         {
//             cout<<1<<endl;
//             return 0;
//         }

//         // Fn = Fn-1 + Fn-2
//         // Fn-1 = Fn-1
//         // 即有  [ Fn ] = [1, 1]  *  [Fn-1]
//         //      [Fn-1]   [1, 0]     [Fn-2]

//         // 转移矩阵 M = [1, 1]
//         //             [1, 0]

//         // 则   [ Fn ] = M^(n-2)  *  [F1] = M^(n-2) * [1]
//         //     [Fn-1]               [F2]             [1]

//         // 转移矩阵
//         Mat base;
//         base.a[0][0] = 1;
//         base.a[0][1] = 1;
//         base.a[1][0] = 1;
//         base.a[1][1] = 0;

//         Mat res = ksm(base, n - 2);

//         // 结果 = res * [1, 1]^T
//         ll ans = (res.a[0][0] + res.a[0][1]) % mod;

//         cout<<ans<<endl;
//     }

//     return 0;
// }