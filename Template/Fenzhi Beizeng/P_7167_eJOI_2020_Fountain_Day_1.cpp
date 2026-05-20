// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 2^17 = 131072 > 1e5
// const int LOG = 18;

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

//         vector<int> d(n + 1), c(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>d[i]>>c[i];
//         }

//         // 单调栈求 nxt[i]：向下第一个直径更大的圆盘
//         vector<int> nxt(n + 1, 0);
//         stack<int> st;
//         for (int i = n; i >= 1; i--)
//         {
//             while (!st.empty() && d[st.top()] <= d[i])
//             {
//                 st.pop();
//             }

//             nxt[i] = st.empty() ? 0 : st.top();

//             st.push(i);
//         }

//         // 倍增表
//         // fa[u][k]：从 u 向上跳 2^k 步到达的祖先
//         // sum[u][k]：从 u 开始连续 2^k 个圆盘（包括 u）的容量之和
//         vector<vector<int>> fa(n + 1, vector<int>(LOG, 0));
//         vector<vector<ll>> sum(n + 1, vector<ll>(LOG, 0));
//         for (int i = 1; i <= n; i++)
//         {
//             fa[i][0] = nxt[i];
//             sum[i][0] = c[i];
//         }

//         for (int k = 1; k < LOG; k++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 int f = fa[i][k - 1];
//                 fa[i][k] = fa[f][k - 1];
//                 sum[i][k] = sum[i][k - 1] + sum[f][k - 1];
//             }
//         }

//         while (q--)
//         {
//             int r;
//             ll v;
//             cin>>r>>v;

//             int u = r;
//             for (int k = LOG - 1; k >= 0; k--)
//             {
//                 if(fa[u][k] != 0 && sum[u][k] < v)
//                 {
//                     v -= sum[u][k];
//                     u = fa[u][k];
//                 }
//             }

//             // 如果最后一个圆盘容量不够，且下方无更大圆盘 → 流入水池
//             if (u != 0 && v > c[u])
//             {
//                 u = 0;
//             }

//             cout<<u<<endl;
//         }
//     }

//     return 0;
// }