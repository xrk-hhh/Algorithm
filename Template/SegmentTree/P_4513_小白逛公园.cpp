// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 5e5 + 10;

// int a[N];

// // 懒标记：区间和，最大子段和，最大前缀和，最大后缀和
// struct Node
// {
//     int sum, maxx, pre, suf;
// } tree[4 * N];

// // 合并两个节点
// Node merge(Node l, Node r)
// {
//     Node res;
//     res.sum = l.sum + r.sum;
//     res.pre = max(l.pre, l.sum + r.pre);
//     res.suf = max(r.suf, l.suf + r.sum);
//     res.maxx = max({l.maxx, r.maxx, l.suf + r.pre});
//     return res;
// }

// // 懒标记下放
// void push(int idx)
// {
//     tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
// }

// // 建树
// void build(int idx, int l, int r)
// {
//     // 叶子初始化
//     if (l == r)
//     {
//         tree[idx] = {a[l], a[l], a[l], a[l]};
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);
//     push(idx);
// }

// // 单点修改
// void update(int idx ,int l, int r, int p, int v)
// {
//     if (l == r)
//     {
//         tree[idx] = {v, v, v, v};
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

//     push(idx);
// }

// // 查询区间最大子段和
// Node query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return tree[idx];
//     }

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

//     return merge(left, right);
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
//             int k;
//             cin>>k;

//             if (k == 1)
//             {
//                 int a, b;
//                 cin>>a>>b;

//                 if (a > b)
//                 {
//                     swap(a, b);
//                 }

//                 Node res = query(1, 1, n, a, b);
//                 cout<<res.maxx<<endl;
//             }
//             else
//             {
//                 int p, s;
//                 cin>>p>>s;
                
//                 update(1, 1, n, p, s);
//             }
//         }
//     }

//     return 0;
// }