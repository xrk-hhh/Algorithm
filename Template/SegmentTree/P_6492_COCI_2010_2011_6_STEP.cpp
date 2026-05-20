// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 2e5 + 10;

// char s[N];

// // 线段树数组：区间长度，最长交替子串长度，最长交替前缀长度，最长交替后缀长度，左端点字符，右端点字符
// struct Node
// {
//     int len, best, pre, suf;
//     char lc, rc;
// } tree[4 * N];

// // 合并
// Node merge(Node a, Node b)
// {
//     if (a.len == 0)
//     {
//         return b;
//     }
//     if (b.len == 0)
//     {
//         return a;
//     }

//     Node res;
//     res.len = a.len + b.len;
//     res.lc = a.lc;
//     res.rc = b.rc;

//     // 前缀
//     res.pre = a.pre;
//     if (a.pre == a.len && a.rc != b.lc)
//     {
//         res.pre = a.len + b.pre;
//     }

//     // 后缀
//     res.suf = b.suf;
//     if (b.suf == b.len && a.rc != b.lc)
//     {
//         res.suf = a.suf + b.len;
//     }

//     // 最长
//     res.best = max(a.best, b.best);
//     if (a.rc != b.lc)
//     {
//         res.best = max(res.best, a.suf + b.pre);
//     }

//     return res;
// }

// // 建树
// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         tree[idx].len = 1;
//         tree[idx].lc = tree[idx].rc = s[l];
//         tree[idx].pre = tree[idx].suf = tree[idx].best = 1;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
// }

// // 单点修改：翻转字符
// void update(int idx, int l, int r, int p)
// {
//     if (l == r)
//     {
//         s[l] = (s[l] == 'L') ? 'R' : 'L';
//         tree[idx].lc = tree[idx].rc = s[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (p <= mid)
//     {
//         update(idx << 1, l, mid, p);
//     }
//     else
//     {
//         update(idx << 1 | 1, mid + 1, r, p);
//     }

//     tree[idx] = merge(tree[idx << 1], tree[idx << 1 | 1]);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, q;
//         cin>>n>>q;

//         for (int i = 1; i <= n; i++)
//         {
//             s[i] = 'L';
//         }

//         build(1, 1, n);

//         while (q--)
//         {
//             int x;
//             cin>>x;

//             update(1, 1, n, x);

//             // 输出根节点的最长交替子串长度（best），保证为全局
//             cout<<tree[1].best<<endl;
//         }
//     }

//     return 0;
// }