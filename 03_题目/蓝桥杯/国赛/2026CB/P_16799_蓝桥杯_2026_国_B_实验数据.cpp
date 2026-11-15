// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 3e5 + 10;
// const ll mod = 998244353;
// ll a[N];

// ll ksm(ll a, ll b)
// {
//     ll res = 1;
//     a %= mod;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res * a % mod;
//         }
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return res;
// }

// // 逆元
// ll inv(ll x)
// {
//     return ksm(x, mod - 2);
// }

// // 线段树数组：区间和，区间平方和
// struct Node
// {
//     ll sum, sum2;
// } tree[N << 2];

// // 合并左右子节点
// void pushup(int idx)
// {
//     tree[idx].sum = (tree[idx << 1].sum + tree[idx << 1 | 1].sum) % mod;
//     tree[idx].sum2 = (tree[idx << 1].sum2 + tree[idx << 1 | 1].sum2) % mod;
// }

// // 建树
// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         tree[idx].sum = a[l] % mod;
//         tree[idx].sum2 = (a[l] % mod) * (a[l] % mod) % mod;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     pushup(idx);
// }

// // 单点修改
// void update(int idx, int l, int r, int p, ll x)
// {
//     if (l == r)
//     {
//         tree[idx].sum = x % mod;
//         tree[idx].sum2 = (x % mod) * (x % mod) % mod;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (p <= mid)
//     {
//         update(idx << 1, l, mid, p, x);
//     }
//     else
//     {
//         update(idx << 1 | 1, mid + 1, r, p, x);
//     }

//     pushup(idx);
// }

// // 查询区间和和区间平方和
// pair<ll, ll> query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return {tree[idx].sum, tree[idx].sum2};
//     }

//     int mid = (l + r) >> 1;
//     ll sum = 0, sum2 = 0;
//     if (ql <= mid)
//     {
//         auto [s, s2] = query(idx << 1, l, mid, ql, qr);
//         sum = (sum + s) % mod;
//         sum2 = (sum2 + s2) % mod;
//     }
//     if (qr > mid)
//     {
//         auto [s, s2] = query(idx << 1 | 1, mid + 1, r, ql, qr);
//         sum = (sum + s) % mod;
//         sum2 = (sum2 + s2) % mod;
//     }
//     return {sum, sum2};
// }

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

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             a[i] %= mod;
//         }

//         build(1, 1, n);

//         while (m--)
//         {
//             int op;
//             cin>>op;

//             if (op == 1)
//             {
//                 int l, r;
//                 cin>>l>>r;

//                 // 方差公式：区间平方和  - 区间平均数的平方
//                 auto [s, s2] = query(1, 1, n, l, r);
//                 int len = r - l + 1;
//                 ll inv_len = inv(len);
//                 ll avg = s * inv_len % mod;
//                 ll var = (s2 - s * avg % mod + mod) % mod;

//                 cout<<avg<<' '<<var<<endl;
//             }
//             else
//             {
//                 int k, x;
//                 cin>>k>>x;

//                 x %= mod;
//                 update(1, 1, n, k, x);
//             }
//         }
//     }

//     return 0;
// }