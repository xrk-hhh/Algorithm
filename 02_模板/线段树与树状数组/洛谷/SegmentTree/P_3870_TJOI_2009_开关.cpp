// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// // tree：区间内亮灯数量
// // lazy：区间是否取反
// int tree[4 * N], lazy[4 * N];

// // 建树
// void build(int idx, int l, int r)
// {
//     // 初始不亮
//     tree[idx] = 0;
//     lazy[idx] = 0;
//     if (l == r)
//     {
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx * 2, l, mid);
//     build(idx * 2 + 1, mid + 1, r);
// }

// // 懒标记下传
// void push(int idx, int l, int r)
// {
//     if (lazy[idx])
//     {
//         int mid = (l + r) >> 1;
//         //更新子节点区间和
//         tree[idx * 2] = (mid - l + 1) - tree[idx * 2];
//         tree[idx * 2 + 1] = (r - mid) - tree[idx * 2 + 1];
//         // 左右子树节点异或
//         lazy[idx * 2] ^= 1;
//         lazy[idx * 2 + 1] ^= 1;
//         lazy[idx] = 0;
//     }
// }

// // 区间更新
// void update(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         tree[idx] = (r - l + 1) - tree[idx];
//         lazy[idx] ^= 1;
//         return;
//     }

//     // 懒标记下传
//     push(idx, l, r);

//     // 
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update(idx * 2, l, mid, ql, qr);
//     }
//     if (qr > mid)
//     {
//         update(idx * 2 + 1, mid + 1, r, ql, qr);
//     }
//     tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
// }

// // 区间查询
// int query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx];
//     }

//     push(idx, l, r);

//     int mid = (l + r) >> 1;
//     int res = 0;
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

//         build(1, 1, n);

//         while (m--)
//         {
//             int c, a, b;
//             cin>>c>>a>>b;

//             if (c == 0)
//             {
//                 update(1, 1, n, a, b);
//             }
//             else
//             {
//                 cout<<query(1, 1, n, a, b)<<endl;
//             }
//         }
//     }

//     return 0;
// }