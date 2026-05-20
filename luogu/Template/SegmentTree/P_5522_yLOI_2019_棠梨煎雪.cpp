// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int N = 1e5 + 10;

// string s[N];
// int mask0[N], mask1[N];

// struct Node
// {
//     int or0, or1;
// } tree[4 * N];

// void build(int idx, int l, int r)
// {
//     if (l == r)
//     {
//         tree[idx].or0 = mask0[l];
//         tree[idx].or1 = mask1[l];
//         return;
//     }

//     int mid = (l + r) >> 1;
//     build(idx << 1, l, mid);
//     build(idx << 1 | 1, mid + 1, r);

//     tree[idx].or0 = tree[idx << 1].or0 | tree[idx << 1 | 1].or0;
//     tree[idx].or1 = tree[idx << 1].or1 | tree[idx << 1 | 1].or1;
// }

// void update(int idx, int l, int r, int pos, int v0, int v1)
// {
//     if (l == r)
//     {
//         tree[idx].or0 = v0;
//         tree[idx].or1 = v1;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     if (pos <= mid)
//     {
//         update(idx << 1, l, mid, pos, v0, v1);
//     }
//     else
//     {
//         update(idx << 1 | 1, mid + 1, r, pos, v0, v1);
//     }

//     tree[idx].or0 = tree[idx << 1].or0 | tree[idx << 1 | 1].or0;
//     tree[idx].or1 = tree[idx << 1].or1 | tree[idx << 1 | 1].or1;
// }

// pair<int, int> query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql <= l && r <= qr)
//     {
//         return {tree[idx].or0, tree[idx].or1};
//     }

//     int mid = (l + r) >> 1;
//     int res0 = 0, res1 = 0;
//     if (ql <= mid)
//     {
//         auto [a, b] = query(idx << 1, l, mid, ql, qr);
//         res0 |= a;
//         res1 |= b;
//     }
//     if (qr > mid)
//     {
//         auto [a, b] = query(idx << 1 | 1, mid + 1, r, ql, qr);
//         res0 |= a;
//         res1 |= b;
//     }
//     return {res0, res1};
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, q;
//         cin>>n>>m>>q;

//         for (int i = 1; i <= m; i++)
//         {
//             cin>>s[i];

//             int m0 = 0, m1 = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 char c = s[i][j];
//                 if (c == '0')
//                 {
//                     m0 |= (1 << j);
//                 }
//                 else if (c == '1')
//                 {
//                     m1 |= (1 << j);
//                 }
//             }

//             mask0[i] = m0;
//             mask1[i] = m1;
//         }

//         build(1, 1, m);

//         ll xor_sum = 0;

//         while (q--)
//         {
//             int op;
//             cin>>op;

//             if (op == 0)
//             {
//                 int l, r;
//                 cin>>l>>r;

//                 auto [or0, or1] = query(1, 1, m, l, r);
//                 if (or0 & or1)
//                 {
//                     xor_sum ^= 0;
//                 }
//                 else
//                 {
//                     int free = n - __builtin_popcount(or0 | or1);
//                     int ans = 1 << free;
//                     xor_sum ^= ans;
//                 }
//             }
//             else
//             {
//                 int pos;
//                 string t;
//                 cin>>pos>>t;

//                 int m0 = 0, m1 = 0;
//                 for (int j = 0; j < n; j++)
//                 {
//                     char c = t[j];
//                     if (c == '0')
//                     {
//                         m0 |= (1 << j);
//                     }
//                     else if (c == '1')
//                     {
//                         m1 |= (1 << j);
//                     }
//                 }

//                 update(1, 1, m, pos, m0, m1);
//             }
//         }

//         cout<<xor_sum<<endl;
//     }

//     return 0;
// }