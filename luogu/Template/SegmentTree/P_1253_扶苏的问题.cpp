// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e6 + 10;
// const ll INF = 1e18;

// ll a[N];

// // 懒标记：最大值，增加值，重置值，是否重置
// struct Node
// {
//     ll maxx, add, assign;
//     bool has_assign;
// } tree[4 * N];

// // 建树
// void build (int idx, int l, int r)
// {
//     tree[idx].add = 0;
//     tree[idx].has_assign = false;
//     if (l == r)
//     {
//         tree[idx].maxx = a[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);
//     tree[idx].maxx = max(tree[idx << 1].maxx, tree[idx << 1 | 1].maxx);
// }

// // 懒标记下放
// void push(int idx, int l, int r)
// {
//     // 需要重置
//     if (tree[idx].has_assign)
//     {
//         ll val = tree[idx].assign;

//         // 左孩纸
//         tree[idx << 1].maxx = val;
//         tree[idx << 1].has_assign = true;
//         tree[idx << 1].assign = val;
//         tree[idx << 1].add = 0;
//         // 右孩纸
//         tree[idx << 1 | 1].maxx = val;
//         tree[idx << 1 | 1].has_assign = true;
//         tree[idx << 1 | 1].assign = val;
//         tree[idx << 1 | 1].add = 0;

//         // 清除当前节点
//         tree[idx].has_assign = false;
//         tree[idx].assign = 0;
//     }

//     // 需要增加
//     if (tree[idx].add)
//     {
//         ll add = tree[idx].add;

//         // 左孩纸是否需要重置
//         if (tree[idx << 1].has_assign)
//         {
//             tree[idx << 1].assign += add;
//             tree[idx << 1].maxx += add;
//         }
//         else
//         {
//             tree[idx << 1].add += add;
//             tree[idx << 1].maxx += add;
//         }

//         // 右孩纸是否需要重置
//         if (tree[idx << 1 | 1].has_assign)
//         {
//             tree[idx << 1 | 1].assign += add;
//             tree[idx << 1 | 1].maxx += add;
//         }
//         else
//         {
//             tree[idx << 1 | 1].add += add;
//             tree[idx << 1 | 1].maxx += add;
//         }

//         // 清除当前节点
//         tree[idx].add = 0;
//     }
// }

// // 区间重置
// void rgAssign(int idx ,int l, int r, int ql, int qr, ll x)
// {
//     // 区间覆盖
//     if (ql <= l && r <= qr)
//     {
//         tree[idx].maxx = x;
//         tree[idx].has_assign = true;
//         tree[idx].assign = x;
//         tree[idx].add = 0;
//         return;
//     }

//     // 下放懒标记
//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     // 左右子树区间重置
//     if (ql <= mid)
//     {
//         rgAssign(idx << 1, l, mid, ql, qr, x);
//     }
//     if (qr > mid)
//     {
//         rgAssign(idx << 1 | 1, mid + 1, r, ql, qr, x);
//     }
//     // 更新节点最大值
//     tree[idx].maxx = max(tree[idx << 1].maxx, tree[idx << 1 | 1].maxx);
// }

// // 区间增加
// void rgAdd(int idx ,int l, int r, int ql, int qr, ll x)
// {
//     // 区间覆盖
//     if (ql <= l && r <= qr)
//     {
//         // 是否需要重置
//         if (tree[idx].has_assign)
//         {
//             tree[idx].assign += x;
//             tree[idx].maxx += x;
//         }
//         else
//         {
//             tree[idx].add += x;
//             tree[idx].maxx += x;
//         }
//         return;
//     }

//     // 下放懒标记
//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     // 左右子树增加
//     if (ql <= mid)
//     {
//         rgAdd(idx << 1, l, mid, ql, qr, x);
//     }
//     if (qr > mid)
//     {
//         rgAdd(idx << 1 | 1, mid + 1, r, ql, qr, x);
//     }
//     // 更新节点最大值
//     tree[idx].maxx = max(tree[idx << 1].maxx, tree[idx << 1 | 1].maxx);
// }

// // 区间查询最大值
// ll query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx].maxx;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     ll res = -INF;
//     if (ql <= mid)
//     {
//         res = max(res, query(idx << 1, l, mid, ql, qr));
//     }
//     if (qr > mid)
//     {
//         res = max(res, query(idx << 1 | 1, mid + 1, r, ql, qr));
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
//         int n, q;
//         cin>>n>>q;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         build(1, 1, n);

//         while (q--)
//         {
//             int op, l, r;
//             cin>>op>>l>>r;

//             if (op == 1)
//             {
//                 ll x;
//                 cin>>x;

//                 rgAssign(1, 1, n, l, r, x);
//             }
//             else if (op == 2)
//             {
//                 ll x;
//                 cin>>x;

//                 rgAdd(1, 1, n, l, r, x);
//             }
//             else
//             {
//                 cout<<query(1, 1, n, l, r)<<endl;
//             }
//         }
//     }

//     return 0;
// }