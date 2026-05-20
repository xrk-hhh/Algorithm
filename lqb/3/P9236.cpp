// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// // int xor_0_to_n(int n)
// // {
// //     switch (n % 4)
// //     {
// //         case 0:
// //             return n;
// //         case 1:
// //             return 1;;
// //         case 2:
// //             return n + 1;
// //         case 3:
// //             return 0;
// //     }
// // }

// // int xor_l_to_r(int l, int r)
// // {
// //     if (l == 0)
// //     {
// //         return xor_0_to_n(r);
// //     }

// //     return xor_0_to_n(r) ^ xor_0_to_n(l - 1);
// // }

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

//         // 前缀异或和
//         vector<int> pre(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             pre[i] = pre[i - 1] ^ a[i];
//         }

//         ll ans = 0;
//         // 按位考虑贡献
//         // pre[i] 和 pre[j] 在该位上要么相同，要么不同
//         // 只有不同时，pre[i] xor pre[j] 才为 1，从而对该位贡献 2^k
//         // 而所有这样的对 (i, j) 中，一个为 0 另一个为 1 的数量就是 cnt0 * cnt1。所以该位的总贡献就是 cnt0 * cnt1 * 2^k。
//         for (int k = 0; k < 31; k++)
//         {
//             int cnt1 = 0;
//             for (int i = 0; i <= n; i++)
//             {
//                 if ((pre[i] >> k) & 1)
//                 {
//                     cnt1++;
//                 }
//             }
//             int cnt0 = n + 1 - cnt1;
//             ans += 1LL * cnt0 * cnt1 *  (1LL << k);
//         }
        
//         cout<<ans<<endl;
//     }

//     return 0;
// }