// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define i128 __int128

// // i128 输出函数
// void print(i128 x)
// {
//     if (x < 0)
//     {
//         putchar('-');
//         x = -x;
//     }
    
//     if (x > 9)
//     {
//         print(x / 10);
//     }
//     putchar(x % 10 + '0');
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         i128 ans = 0;

//         // 贡献法

//         // 按位独立处理
//         for (int k = 0 ; k < 20; k++)
//         {
//             // 利用前缀统计避免枚举所有数对
//             // cnt0：已经扫描过的数中，该位为 0 的个数。
//             // cnt1：已经扫描过的数中，该位为 1 的个数。
//             // sum0：已经扫描过的数中，该位为 0 的所有下标之和。
//             // sum1：已经扫描过的数中，该位为 1 的所有下标之和。
//             ll cnt0 = 0, cnt1 = 0, sum0 = 0, sum1 = 0;
//             i128 cur = 0;
//             for (int i = 1; i <= n; i++)
//             {
//                 // 当前位为 1
//                 if ((a[i] >> k) & 1)
//                 {
//                     cur += (i128)cnt0 * i - sum0;
//                     cnt1++;
//                     sum1 += i;;
//                 }
//                 // 当前位为 0
//                 else
//                 {
//                     cur += (i128)cnt1 * i - sum1;
//                     cnt0++;
//                     sum0 += i;
//                 }
//             }
//             ans += cur << k;
//         }

//         print(ans);
//         // 注意此处不能有换行，否则答案会出现在第二行
//         // cout<<endl;
//     }

//     return 0;
// }