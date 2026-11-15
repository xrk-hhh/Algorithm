// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

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

//         vector<vector<char>> g(n + 1, vector<char>(m + 1));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {
//                 cin>>g[i][j];
//             }
//         }

//         // 1索引，两端哨兵（各列从第 1 行到第 i 行 'F'个数）
//         vector<int> h(m + 2, 0);
//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             // 更新高度
//             for (int j = 1; j <= m; j++)
//             {
//                 if (g[i][j] == 'F')
//                 {
//                     h[j]++;
//                 }
//                 else
//                 {
//                     h[j] = 0;
//                 }
//             }

//             // 单调栈求最大全‘F’矩形面积
//             stack<int> st;
//             vector<int> l(m + 2, 0), r(m + 2, 0);
//             // 左边第一个小于 h[j] 的位置
//             for (int j = 1; j <= m; j++)
//             {
//                 while (!st.empty() && h[st.top()] >= h[j])
//                 {
//                     st.pop();
//                 }

//                 l[j] = st.empty() ? 0 : st.top();
//                 st.push(j);
//             }
            
//             while (!st.empty())
//             {
//                 st.pop();
//             }

//             // 右边第一个小于 h[j] 的位置
//             for (int j = m; j >= 1; j--)
//             {
//                 while (!st.empty() && h[st.top()] >= h[j])
//                 {
//                     st.pop();
//                 }

//                 r[j] = st.empty() ? m + 1 : st.top();
//                 st.push(j);
//             }
            
//             // 更新最大面积
//             for (int j = 1; j <= m; j++)
//             {
//                 int width = r[j] - l[j] - 1;
//                 ans = max(ans, width * h[j]);
//             }
//         }

//         cout<<3 * ans<<endl;
//     }

//     return 0;
// }