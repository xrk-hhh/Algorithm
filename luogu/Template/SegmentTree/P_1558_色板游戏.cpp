// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// int a[N];
// // col：区间颜色掩码
// int col[4 * N], lazy[4 * N];

// // 建树
// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         col[idx] = 1;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     col[idx] = col[idx << 1] | col[idx << 1 | 1];
// }

// // 懒标记下传
// void push(int idx)
// {
//     if (lazy[idx] != -1)
//     {
//         int c = lazy[idx];
//         col[idx << 1] = 1 << (c - 1);
//         col[idx << 1 | 1] = 1 << (c - 1);
//         lazy[idx << 1] = lazy[idx << 1 | 1] = c;
//         lazy[idx] = -1;
//     }
// }

// // 区间赋值（覆盖）
// void update(int idx, int l, int r, int ql, int qr, int c)
// {
//     if (ql <= l && r <= qr)
//     {
//         col[idx] = 1 << (c - 1);
//         lazy[idx] = c;
//         return;
//     }

//     push(idx);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update(idx << 1, l, mid, ql, qr, c);
//     }
//     if (qr > mid)
//     {
//         update(idx << 1 | 1, mid + 1, r, ql, qr, c);
//     }

//     col[idx] = col[idx << 1] | col[idx << 1 | 1];
// }

// // 区间查询
// int query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return col[idx];
//     }

//     push(idx);
//     int mid = (l + r) >> 1;
//     int res = 0;
//     if (ql <= mid)
//     {
//         res |= query(idx << 1, l, mid, ql, qr);
//     }
//     if (qr > mid)
//     {
//         res |= query(idx << 1 | 1, mid + 1, r, ql, qr);
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
//         int n, t, m;
//         cin>>n>>t>>m;

//         build(1, 1, n);
//         memset(lazy, -1, sizeof(lazy));

//         while (m--)
//         {
//             char op;
//             int l, r;
//             cin>>op>>l>>r;

//             if (l > r)
//             {
//                 swap(l, r);
//             }

//             if (op == 'C')
//             {
//                 int c;
//                 cin>>c;

//                 update(1, 1, n, l, r, c);
//             }
//             else
//             {
//                 int mask = query(1, 1, n, l, r);

//                 // 统计二进制中 1 的个数
//                 cout<<__builtin_popcount(mask)<<endl;
//             }
//         }
//     }

//     return 0;
// }