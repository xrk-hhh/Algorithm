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
//         vector<vector<int>> g(n + 1);
//         for (int i = 0; i < m; i++)
//         {
//             int x, y;
//             cin>>x>>y;

//             g[x].push_back(y);
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             sort(g[i].begin(), g[i].end());
//         }

//         vector<bool> vis1(n + 1, false);
//         stack<int> st;
//         st.push(1);
//         vis1[1] = true;
//         vector<int> ans1;
//         while (!st.empty())
//         {
//             int u = st.top();
//             st.pop();

//             ans1.push_back(u);

//             for (int i = (int)g[u].size() - 1; i >= 0; i--)
//             {
//                 int v = g[u][i];
//                 if (!vis1[v])
//                 {
//                     vis1[v] = true;
//                     st.push(v);
//                 }
//             }
//         }

//         vector<bool> vis2(n + 1, false);
//         queue<int> q;
//         q.push(1);
//         vis2[1] = true;
//         vector<int> ans2;
//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             ans2.push_back(u);

//             for (int v : g[u])
//             {
//                 if (!vis2[v])
//                 {
//                     vis2[v] = true;
//                     q.push(v);
//                 }
//             }
//         }

//         for (int i = 0; i < ans1.size(); i++)
//         {
//             cout<<ans1[i]<<' ';
//         }
//         cout<<endl;

//         for (int i = 0; i < ans2.size(); i++)
//         {
//             cout<<ans2[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }