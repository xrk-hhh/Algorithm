// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXN = 1e6 + 10;
// int nxt[MAXN], cur[MAXN], tmp[MAXN];
// ll p[MAXN];

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, k;
//         ll m;
//         cin>>n>>k>>m;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>p[i];
//         }

//         // 双指针求 nxt[i]：距离它第 k 近的石头作为下一跳目标
//         int l = 1, r = k + 1;
//         for (int i = 1; i <= n; i++)
//         {
//             // 若右边下一个石头更近，窗口右移
//             while (r < n && p[r + 1] - p[i] < p[i] - p[l])
//             {
//                 l++;
//                 r++;
//             }

//             // 判断第 k 近是左端还是右端（距离相等选左端）
//             if (p[i] - p[l] >= p[r] - p[i])
//             {
//                 nxt[i] = l;
//             }
//             else
//             {
//                 nxt[i] = r;
//             }
//         }

//         // 初始 cur[i] = i
//         iota(cur + 1, cur + n + 1, 1);

//         // 二进制迭代跳跃 m 次（类比快速幂）
//         while (m)
//         {
//             // 相当于 b & 1
//             if (m & 1)
//             {
//                 // 累积结果：cur[i] = nxt[cur[i]] 相当于 res = res * a
//                 for (int i = 1; i <= n; i++)
//                 {
//                     tmp[i] = nxt[cur[i]];
//                 }

//                 copy(tmp + 1, tmp + n + 1, cur + 1);
//             }

//             // 步数自乘：nxt[i] = nxt[nxt[i]] 相当于 a = a * a
//             for (int i = 1; i <= n; i++)
//             {
//                 tmp[i] = nxt[nxt[i]];
//             }

//             copy(tmp + 1, tmp + n + 1, nxt + 1);

//             // 相当于 b >>= 1
//             m >>= 1;
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout<<cur[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }