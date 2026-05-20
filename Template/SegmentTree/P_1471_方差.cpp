// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// double a[N];
// // 线段树数组：区间和，区间平方和，区间增加值
// struct Node
// {
//     double sum, sum2;
//     double lazy;
// } tree[4 * N];

// // 建树
// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         tree[idx].sum = a[l];
//         tree[idx].sum2 = a[l] * a[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     tree[idx].sum = tree[idx << 1].sum + tree[idx << 1 | 1].sum;
//     tree[idx].sum2 = tree[idx << 1].sum2 + tree[idx << 1 | 1].sum2;
// }

// // 区间更新：加 d
// void apply(int idx, int l, int r, double d)
// {
//     int len = r - l + 1;
//     tree[idx].sum2 += 2 * d * tree[idx].sum + d * d * len;
//     tree[idx].sum += d * len;
//     tree[idx].lazy += d;
// }

// // 懒标记下放
// void push(int idx, int l, int r)
// {
//     if (tree[idx].lazy)
//     {
//         int mid = (l + r) >> 1;
//         apply(idx << 1, l, mid, tree[idx].lazy);
//         apply(idx << 1 | 1, mid + 1, r, tree[idx].lazy);
//         tree[idx].lazy = 0;
//     }
// }

// // 区间增加
// void update(int idx, int l, int r, int ql, int qr, double d)
// {
//     if (ql <= l && r <= qr)
//     {
//         apply(idx, l, r, d);
//         return;
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     if (ql <= mid)
//     {
//         update(idx << 1, l, mid, ql, qr, d);
//     }
//     if (qr > mid)
//     {
//         update(idx << 1 | 1, mid + 1, r, ql, qr, d);
//     }

//     tree[idx].sum = tree[idx << 1].sum + tree[idx << 1 | 1].sum;
//     tree[idx].sum2 = tree[idx << 1].sum2 + tree[idx << 1 | 1].sum2;
// }

// // 查询区间和和区间平方和
// pair<double, double> query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return {tree[idx].sum, tree[idx].sum2};
//     }

//     push(idx, l, r);
//     int mid = (l + r) >> 1;
//     double sum = 0, sum2 = 0;
//     if (ql <= mid)
//     {
//         auto [s, s2] = query(idx << 1, l, mid, ql, qr);
//         sum += s;
//         sum2 += s2;
//     }
//     if (qr > mid)
//     {
//         auto [s, s2] = query(idx << 1 | 1, mid + 1, r, ql, qr);
//         sum += s;
//         sum2 += s2;
//     }
//     return {sum, sum2};
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

//             if (op == 1)
//             {
//                 double d;
//                 cin>>d;

//                 update(1, 1, n, l, r, d);
//             }
//             else if (op == 2)
//             {
//                 auto [s, _] = query(1, 1, n, l, r);
//                 double avg = s / (r - l + 1);

//                 cout<<fixed<<setprecision(4)<<avg<<endl;
//             }
//             else
//             {
//                 // 方差公式：区间平方和 / 区间长度 - 区间平均数的平方
//                 auto [s, s2] = query(1, 1, n, l, r);
//                 int len = r - l + 1;
//                 double avg = s / len;
//                 double var = s2 / len - avg * avg;

//                 cout<<fixed<<setprecision(4)<<var<<endl;
//             }
//         }
//     }

//     return 0;
// }