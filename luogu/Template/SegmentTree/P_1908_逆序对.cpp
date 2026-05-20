// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 5e5 + 10;

// int a[N], b[N];
// // 线段树数组
// int tree[4 * N];

// // 单点更新：在位置 pos 增加 delta
// void update(int idx, int l, int r, int pos, int delta)
// {
//     if (l == r)
//     {
//         tree[idx] += delta;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (pos <= mid)
//     {
//         update(idx << 1, l, mid, pos, delta);
//     }
//     else
//     {
//         update(idx << 1 | 1, mid + 1, r, pos, delta);
//     }

//     tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
// }

// // 查询区间[ql, qr]逆序对个数
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

//         // 复制到数组 b
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             b[i] = a[i];
//         }

//         // 离散化
//         sort(b + 1, b + n + 1);
//         // 去重，得到不同值个数 m
//         int m = unique(b + 1, b + n + 1) - b - 1;

//         ll ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             // 找到当前值在离散化数组中的下标
//             int pos = lower_bound(b + 1, b + m + 1, a[i]) - b;
//             // 查询比当前值大的已出现元素个数（即区间 [pos + 1, m]）
//             if (pos < m)
//             {
//                 ans += query(1, 1, m, pos + 1, m);
//             }

//             // 将当前值插入线段树
//             update(1, 1, m, pos, 1);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }