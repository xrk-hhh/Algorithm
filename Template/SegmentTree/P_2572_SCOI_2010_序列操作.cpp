// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// int a[N];

// struct Node
// {
//     int len;
//     int sum1;
//     int l1, r1, max1;
//     int sum0;
//     int l0, r0, max0;
//     int lazy;
// } tree[4 * N];

// void push_up(int idx)
// {
//     Node& L = tree[idx << 1];
//     Node& R = tree[idx << 1 | 1];
//     Node& cur = tree[idx];

//     cur.len = L.len + R.len;

//     cur.sum1 = L.sum1 + R.sum1;
//     cur.l1 = L.l1;
//     if (L.l1 == L.len)
//     {
//         cur.l1 += R.l1;
//     }
//     cur.r1 = R.r1;
//     if (R.r1 == R.len)
//     {
//         cur.r1 += L.r1;
//     }
//     cur.max1 = max({L.max1, R.max1, L.r1 + R.l1});

//     cur.sum0 = L.sum0 + R.sum0;
//     cur.l0 = L.l0;
//     if (L.l0 == L.len)
//     {
//         cur.l0 += R.l0;
//     }
//     cur.r0 = R.r0;
//     if (R.r0 == R.len)
//     {
//         cur.r0 += L.r0;
//     }
//     cur.max0 = max({L.max0, R.max0, L.r0 + R.l0});
// }

// void apply_set(int idx, int v)
// {
//     Node& cur = tree[idx];
//     if (v == 0)
//     {
//         cur.sum0 = cur.len;
//         cur.l0 = cur.r0 = cur.max0 = cur.len;
//         cur.sum1 = 0;
//         cur.l1 = cur.r1 = cur.max1 = 0;
//         cur.lazy = 2;
//     }
//     else
//     {
//         cur.sum1 = cur.len;
//         cur.l1 = cur.r1 = cur.max1 = cur.len;
//         cur.sum0 = 0;
//         cur.l0 = cur.r0 = cur.max0 = 0;
//         cur.lazy = 1;
//     }
// }

// void apply_rev(int idx)
// {
//     Node& cur = tree[idx];
//     swap(cur.sum0, cur.sum1);
//     swap(cur.l0, cur.l1);
//     swap(cur.r0, cur.r1);
//     swap(cur.max0, cur.max1);

//     if (cur.lazy == 1)
//     {
//         cur.lazy = 2;
//     }
//     else if (cur.lazy == 2)
//     {
//         cur.lazy = 1;
//     }
//     else if (cur.lazy == 3)
//     {
//         cur.lazy = 0;
//     }
//     else if (cur.lazy == 0)
//     {
//         cur.lazy = 3;
//     }
// }

// void push_down(int idx)
// {
//     if (tree[idx].lazy == 0)
//     {
//         return;
//     }

//     int lc = idx << 1, rc = idx << 1 | 1;
//     if (tree[idx].lazy == 1)
//     {
//         apply_set(lc, 1);
//         apply_set(rc, 1);
//     }
//     else if (tree[idx].lazy == 2)
//     {
//         apply_set(lc, 0);
//         apply_set(rc, 0);
//     }
//     else if (tree[idx].lazy == 3)
//     {
//         apply_rev(lc);
//         apply_rev(rc);
//     }
//     tree[idx].lazy = 0;
// }

// void build(int idx, int l, int r)
// {
//     tree[idx].len = r - l + 1;
//     tree[idx].lazy = 0;
//     if (l == r)
//     {
//         int v = a[l];
//         if (v == 1)
//         {
//             tree[idx].sum1 = 1;
//             tree[idx].l1 = tree[idx].r1 = tree[idx].max1 = 1;
//             tree[idx].sum0 = 0;
//             tree[idx].l0 = tree[idx].r0 = tree[idx].max0 = 0;
//         }
//         else
//         {
//             tree[idx].sum0 = 1;
//             tree[idx].l0 = tree[idx].r0 = tree[idx].max0 = 1;
//             tree[idx].sum1 = 0;
//             tree[idx].l1 = tree[idx].r1 = tree[idx].max1 = 0;
//         }
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);
//     push_up(idx);
// }

// void update_set(int idx, int l, int r, int ql, int qr, int v)
// {
//     if (ql <= l && r <= qr)
//     {
//         apply_set(idx, v);
//         return;
//     }

//     push_down(idx);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update_set(idx << 1, l, mid, ql, qr, v);
//     }
//     if (qr > mid)
//     {
//         update_set(idx << 1 | 1, mid + 1, r, ql, qr, v);
//     }

//     push_up(idx);
// }

// void update_rev(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         apply_rev(idx);
//         return;
//     }

//     push_down(idx);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update_rev(idx << 1, l, mid, ql, qr);
//     }
//     if (qr > mid)
//     {
//         update_rev(idx << 1 | 1, mid + 1, r, ql, qr);
//     }

//     push_up(idx);
// }

// Node query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx];
//     }

//     push_down(idx);
//     int mid = (l + r) >> 1;
//     if (qr <= mid)
//     {
//         return query(idx << 1, l, mid, ql, qr);
//     }
//     if (ql > mid)
//     {
//         return query(idx << 1 | 1, mid + 1, r, ql, qr);
//     }

//     Node left = query(idx << 1, l, mid, ql, qr);
//     Node right = query(idx << 1 | 1, mid + 1, r, ql, qr);

//     Node res;
//     res.len = left.len + right.len;
//     res.sum1 = left.sum1 + right.sum1;
//     res.l1 = left.l1;
//     if (left.l1 == left.len)
//     {
//         res.l1 += right.l1;
//     }
//     res.r1 = right.r1;
//     if (right.r1 == right.len)
//     {
//         res.r1 += left.r1;
//     }
//     res.max1 = max({left.max1, right.max1, left.r1 + right.l1});

//     res.sum0 = left.sum0 + right.sum0;
//     res.l0 = left.l0;
//     if (left.l0 == left.len)
//     {
//         res.l0 += right.l0;
//     }
//     res.r0 = right.r0;
//     if (right.r0 == right.len)
//     {
//         res.r0 += left.r0;
//     }
//     res.max0 = max({left.max0, right.max0, left.r0 + right.l0});

//     res.lazy = 0;
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
//             int op, l, r;
//             cin>>op>>l>>r;

//             l++;
//             r++;

//             if (op == 0)
//             {
//                 update_set(1, 1, n, l, r, 0);
//             }
//             else if (op == 1)
//             {
//                 update_set(1, 1, n, l, r, 1);
//             }
//             else if (op == 2)
//             {
//                 update_rev(1, 1, n, l, r);
//             }
//             else if (op == 3)
//             {
//                 Node res = query(1, 1, n, l, r);

//                 cout<<res.sum1<<endl;
//             }
//             else
//             {
//                 Node res = query(1, 1, n, l, r);

//                 cout<<res.max1<<endl;
//             }
//         }
//     }

//     return 0;
// }