// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;
// const int INF = 1e9;

// int a[N];
// // 线段树数组
// int tree[4 * N];

// // 建树
// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         tree[idx] = a[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
// }

// // 单点更新：在 pos 处出现 v，更新最小值
// void update(int idx, int l, int r, int pos, int v)
// {
//     if (l == r)
//     {
//         tree[idx] = v;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (pos <= mid)
//     {
//         update(idx << 1, l, mid, pos, v);
//     }
//     else
//     {
//         update(idx << 1 | 1, mid + 1, r, pos, v);
//     }

//     tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
// }

// // 区间查询：最小值
// int query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx];
//     }

//     int mid = (l + r) >> 1;
//     int res = INF;
//     if (ql <= mid)
//     {
//         res = min(res, query(idx << 1, l, mid, ql, qr));
//     }
//     if (qr > mid)
//     {
//         res = min(res, query(idx << 1 | 1, mid + 1, r, ql, qr));
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
//         int n, m;
//         cin>>n>>m;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         build(1, 1, n);

//         while (m--)
//         {
//             int l, r;
//             cin>>l>>r;

//             cout<<query(1, 1, n, l, r)<<' ';
//         }
//     }

//     return 0;
// }