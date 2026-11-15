// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 3e4 + 10;

// int a[N], b[N];
// int tree[4 * N];

// // 单点更新
// void update(int idx, int l, int r, int p, int v)
// {
//     if (l == r)
//     {
//         tree[idx] += v;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (p <= mid)
//     {
//         update(idx << 1, l, mid, p, v);
//     }
//     else
//     {
//         update(idx << 1 | 1, mid + 1, r, p, v);
//     }

//     tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
// }

// // 区间查询
// int query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx];
//     }

//     int mid = (l + r) >> 1;
//     int res = 0;
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
//         int n;
//         cin>>n;

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             b[i] = a[i];
//         }

//         // 离散化
//         sort(b + 1, b + n + 1);
//         int m = unique(b + 1, b + n + 1) - b - 1;
//         for (int i = 1; i <= n; i++)
//         {
//             a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
//         }

//         vector<int> left(n + 1), right(n + 1);
//         // 从左到右，统计左边小于当前数的个数
//         for (int i = 1; i <= n; i++)
//         {
//             if (a[i] > 1)
//             {
//                 left[i] = query(1, 1, m, 1, a[i] - 1);
//             }
//             else
//             {
//                 left[i] = 0;
//             }

//             update(1, 1, m, a[i], 1);
//         }

//         // 重置线段树
//         memset(tree, 0, sizeof(tree));

//         // 从右到左，统计右边大于当前数的个数
//         for (int i = n; i >= 1; i--)
//         {
//             if (a[i] < m)
//             {
//                 right[i] = query(1, 1, m, a[i] + 1, m);
//             }
//             else
//             {
//                 right[i] = 0;
//             }

//             update(1, 1, m, a[i], 1);
//         }

//         ll ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             ans += 1LL * left[i] * right[i];
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }