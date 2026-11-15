// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// int n, q, m;
// ll a[N];

// // 懒标记：区间和，乘法，加法
// struct Node
// {
//     ll sum, mul, add;
// } tree[4 * N];

// // 建树
// void build(int idx, int l, int r)
// {
//     tree[idx].mul = 1;
//     tree[idx].add = 0;
//     if (l == r)
//     {
//         tree[idx].sum = a[l] % m;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     tree[idx].sum = (tree[idx << 1].sum + tree[idx << 1 | 1].sum) % m;
// }

// // 乘法规则
// void applyMul(int idx, ll val)
// {
//     tree[idx].sum = tree[idx].sum * val % m;
//     tree[idx].mul = tree[idx].mul * val % m;
//     tree[idx].add = tree[idx].add * val % m;
// }

// // 加法规则
// void applyAdd(int idx, ll val, int len)
// {
//     tree[idx].sum = (tree[idx].sum + val * len) % m;
//     tree[idx].add = (tree[idx].add + val) % m;
// }

// // 懒标记下放（先乘后加）
// void push(int idx, int l, int r)
// {
//     int mid = (l + r) >> 1;
//     if (tree[idx].mul != 1)
//     {
//         applyMul(idx << 1, tree[idx].mul);
//         applyMul(idx << 1 | 1, tree[idx].mul);
//         tree[idx].mul = 1;
//     }
//     if (tree[idx].add != 0)
//     {
//         applyAdd(idx << 1, tree[idx].add, mid - l + 1);
//         applyAdd(idx << 1 | 1, tree[idx].add, r - mid);
//         tree[idx].add = 0;
//     }
// }

// // 区间乘法
// void rgMul(int idx ,int l, int r, int ql, int qr, ll val)
// {
//     if (ql <= l && r <= qr)
//     {
//         applyMul(idx, val);
//         return;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         rgMul(idx << 1, l, mid, ql, qr, val);
//     }
//     if (qr > mid)
//     {
//         rgMul(idx << 1 | 1, mid + 1, r, ql, qr, val);
//     }

//     tree[idx].sum = (tree[idx << 1].sum + tree[idx << 1 | 1].sum) % m;
// }

// // 区间加法
// void rgAdd(int idx, int l, int r, int ql, int qr, ll val)
// {
//     if (ql <= l && r <= qr)
//     {
//         applyAdd(idx, val, r - l + 1);
//         return;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         rgAdd(idx << 1, l, mid, ql, qr, val);
//     }
//     if (qr > mid)
//     {
//         rgAdd(idx << 1 | 1, mid + 1, r, ql, qr, val);
//     }

//     tree[idx].sum = (tree[idx << 1].sum + tree[idx << 1 | 1].sum) % m;
// }

// // 查询区间和
// ll query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx].sum;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     ll res = 0;
//     if (ql <= mid)
//     {
//         res = (res + query(idx << 1, l, mid, ql, qr)) % m;
//     }
//     if (qr > mid)
//     {
//         res = (res + query(idx << 1 | 1, mid + 1, r, ql, qr)) % m;
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
//         cin>>n>>q>>m;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         build(1, 1, n);

//         while (q--)
//         {
//             int op, x, y;
//             cin>>op>>x>>y;

//             if (op == 1)
//             {
//                 ll k;
//                 cin>>k;

//                 rgMul(1, 1, n, x, y, k);
//             }
//             else if (op == 2)
//             {
//                 ll k;
//                 cin>>k;

//                 rgAdd(1, 1, n, x, y, k);
//             }
//             else
//             {
//                 cout<<query(1, 1, n, x, y)<<endl;
//             }
//         }
//     }

//     return 0;
// }