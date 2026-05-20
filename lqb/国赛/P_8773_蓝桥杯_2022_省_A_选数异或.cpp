// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;
// const int V = 1 << 20;

// // lp[i]：i 左边最近的等于 a[i] ^ x的位置
// // last[i]：a[i] 最后出现的位置
// int a[N], lp[N], last[V];
// // 线段树维护区间最大值
// int tree[N << 2];

// // 建树
// void build(int u, int l, int r)
// {
//     if (l == r)
//     {
//         tree[u] = lp[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(u << 1, l, mid);
//     build(u << 1 | 1, mid + 1, r);

//     tree[u] = max(tree[u << 1], tree[u << 1 | 1]);
// }

// // 区间查询最大值
// int query(int u, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[u];
//     }

//     int mid = (l + r) >> 1;
//     int res = 0;
//     if (ql <= mid)
//     {
//         res = max(res, query(u << 1, l, mid, ql, qr));
//     }
//     if (qr > mid)
//     {
//         res = max(res, query(u << 1 | 1, mid + 1, r, ql, qr));
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
//         int n, m, x;
//         cin>>n>>m>>x;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             int b = a[i] ^ x;
//             if (b < V && last[b])
//             {
//                 lp[i] = last[b];
//             }
//             else
//             {
//                 lp[i] = 0;
//             }

//             last[a[i]] = i;
//         }

//         build(1, 1, n);

//         while (m--)
//         {
//             int l, r;
//             cin>>l>>r;

//             int maxx = query(1, 1, n, l, r);
//             if (maxx >= l)
//             {
//                 cout<<"yes"<<endl;
//             }
//             else
//             {
//                 cout<<"no"<<endl;
//             }
//         }
//     }

//     return 0;
// }