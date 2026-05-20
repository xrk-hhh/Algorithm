// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// ll a[N];

// // 懒标记：当前区间整体加一个等差数列，首项为 k，公差为 d
// struct Node
// {
//     ll k, d;
// } seg[4 * N];

// // 懒标记下传
// void push(int idx, int l, int r)
// {
//     if (seg[idx].k == 0 && seg[idx].d == 0)
//     {
//         return;
//     }

//     int mid = (l + r) >> 1;
//     // 左子区间
//     seg[idx * 2].k += seg[idx].k;
//     seg[idx * 2].d += seg[idx].d;
//     // 右子区间：首项需要根据偏移计算
//     ll rk = seg[idx].k + (mid + 1 - l) * seg[idx].d;
//     seg[idx * 2 + 1].k += rk;
//     seg[idx * 2 + 1].d += seg[idx].d;
//     // 清空当前节点懒标记
//     seg[idx].k = seg[idx].d = 0;
// }

// // 区间更新：区间 [ql, qr] 加上首项为 k，公差为 d 的等差数列
// void update(int idx, int l, int r, int ql, int qr, ll k, ll d)
// {
//     if (ql <= l && r <= qr)
//     {
//         // 当前区间整体加上等差数列，首项为 k + (l - ql) * d
//         ll start = k + (l - ql) * d;
//         seg[idx].k += start;
//         seg[idx].d += d;
//         return;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update(idx * 2, l, mid, ql, qr, k, d);
//     }
//     if (qr > mid)
//     {
//         update(idx * 2 + 1, mid + 1, r, ql, qr, k, d);
//     }
// }

// // 单点查询位置 p 的值
// ll query(int idx, int l, int r, int p)
// {
//     if (l == r)
//     {
//         return a[p] + seg[idx].k;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     if (p <= mid)
//     {
//         return query(idx * 2, l, mid, p);
//     }
//     else
//     {
//         return query(idx * 2 + 1, mid + 1, r, p);
//     }
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

//         while (m--)
//         {
//             int op;
//             cin>>op;

//             if (op == 1)
//             {
//                 int l, r, k, d;
//                 cin>>l>>r>>k>>d;

//                 update(1, 1, n, l, r, k, d);
//             }
//             else
//             {
//                 int p;
//                 cin>>p;

//                 cout<<query(1, 1, n, p)<<endl;
//             }
//         }
//     }

//     return 0;
// }