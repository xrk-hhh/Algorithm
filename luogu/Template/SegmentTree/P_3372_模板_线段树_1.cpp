// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// ll a[N];
// // tree：区间和
// // lazy：懒标记
// ll tree[4 * N], lazy[4 * N];

// // 建树
// void build(int idx, int l, int r)
// {
//     // 叶子节点
//     if (l == r)
//     {
//         tree[idx] = a[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     // 构建左右子树
//     build(idx * 2, l, mid);
//     build(idx * 2 + 1, mid + 1, r);
//     // 合并左右子树的和
//     tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
// }

// // 懒标记下传
// void push(int idx, int l, int r)
// {
//     if (lazy[idx] != 0)
//     {
//         int mid = (l + r) >> 1;
//         // 更新子节点区间和
//         tree[idx * 2] += lazy[idx] * (mid - l + 1);
//         tree[idx * 2 + 1] += lazy[idx] * (r - mid);
//         // 加到左右子节点的懒标记上
//         lazy[idx * 2] += lazy[idx];
//         lazy[idx * 2 + 1] += lazy[idx];
//         // 清除当前节点的懒标记
//         lazy[idx] = 0;
//     }
// }

// // 区间加（将区间[ql, qr]内的所有数加上 val）
// void update(int idx, int l, int r, int ql, int qr, ll val)
// {
//     // 当前节点完全被区间覆盖
//     if (ql <= l && r <= qr)
//     {
//         tree[idx] += val * (r - l + 1);
//         lazy[idx] += val;
//         return;
//     }

//     // 先下传懒标记
//     push(idx, l, r);
//     // 递归更新左右子树
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update(idx * 2, l, mid, ql, qr, val);
//     }
//     if (qr > mid)
//     {
//         update(idx * 2 + 1, mid + 1, r, ql, qr, val);
//     }

//     // 更新当前节点
//     tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
// }

// // 区间查询
// ll query(int idx, int l, int r, int ql, int qr)
// {
//     // 当前节点完全在查询区间内
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx];
//     }

//     // 先下传懒标记
//     push(idx, l, r);
//     int mid = (l + r) >> 1;

//     // 递归查询左右子树，累加结果
//     ll res = 0;
//     if (ql <= mid)
//     {
//         res += query(idx * 2, l, mid, ql, qr);
//     }
//     if (qr > mid)
//     {
//         res += query(idx * 2 + 1, mid + 1, r, ql, qr);
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
//             int op, x, y;
//             cin>>op>>x>>y;

//             if (op == 1)
//             {
//                 ll k;
//                 cin>>k;

//                 update(1, 1, n, x, y, k);
//             }
//             else
//             {
//                 cout<<query(1, 1, n, x, y)<<endl;
//             }
//         }
//     }

//     return 0;
// }