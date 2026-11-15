// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// ll a[N];

// // 线段树：区间和，最大值
// struct Node
// {
//     ll sum, maxx;
// } tree[4 * N];

// void push_up(int idx)
// {
//     tree[idx].sum = tree[idx << 1].sum + tree[idx << 1 | 1].sum;
//     tree[idx].maxx = max(tree[idx << 1].maxx, tree[idx << 1 | 1].maxx);
// }

// // 建树
// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         tree[idx].sum = a[l];
//         tree[idx].maxx = a[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     push_up(idx);
// }

// // 区间开平方
// void update(int idx, int l, int r, int ql, int qr)
// {
//     // 当 x <= 1 时，开平方无意义
//     if (tree[idx].maxx <= 1)
//     {
//         return;
//     }

//     if (l == r)
//     {
//         ll val = sqrt(tree[idx].sum);
//         tree[idx].sum = tree[idx].maxx = val;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update(idx << 1, l, mid, ql, qr);
//     }
//     if (qr > mid)
//     {
//         update(idx << 1 | 1, mid + 1, r, ql, qr);
//     }

//     push_up(idx);
// }

// // 查询区间和
// ll query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx].sum;
//     }

//     int mid = (l + r) >> 1;
//     ll res = 0;
//     if (ql <= mid)
//     {
//         res += query(idx << 1, l, mid, ql, qr);
//     }
//     if (qr > mid)
//     {
//         res += query(idx << 1 | 1, mid + 1, r, ql, qr);
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
//         cin>>n;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         build(1, 1, n);

//         cin>>m;

//         while (m--)
//         {
//             int k, l, r;
//             cin>>k>>l>>r;

//             if (l > r)
//             {
//                 swap(l, r);
//             }

//             if (k == 0)
//             {
//                 update(1, 1, n, l, r);
//             }
//             else
//             {
//                 cout<<query(1, 1, n, l, r)<<endl;
//             }
//         }
//     }

//     return 0;
// }