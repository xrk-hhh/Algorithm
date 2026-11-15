// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// ll p, q, a1, a2, n, m;

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
//                         res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % m;
//                     }
//                 }
//             }
//         }

//         return res;
//     }
// };

// Mat base;

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
//         cin>>p>>q>>a1>>a2>>n>>m;

//         if (n == 1)
//         {
//             cout<<a1 % m<<endl;
//             return 0;
//         }
//         if (n == 2)
//         {
//             return a2 % m<<endl;
//             return 0;
//         }

//         // 转移矩阵
//         base.a[0][0] = p % m;
//         base.a[0][1] = q % m;
//         base.a[1][0] = 1;
//         base.a[1][1] = 0;

//         Mat res = ksm(base, n - 2);

//         // 结果
//         ll ans = (res.a[0][0] * a2 + res.a[0][1] * a1) % m;

//         cout<<ans<<endl;
//     }

//     return 0;
// }