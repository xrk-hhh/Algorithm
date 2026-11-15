// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         vector<vector<int>> g(n);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v;
//             cin>>u>>v;

//             u--;
//             v--;

//             g[u].push_back(v);
//             g[v].push_back(u);
//         }

//         int w;
//         cin>>w;

//         vector<string> s(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>s[i];
//         }

//         int tot = n * w;
//         vector<vector<int>> adj(tot);
//         vector<int> indeg(tot, 0);
//         for (int u = 0; u < n; u++)
//         {
//             for (int d = 0; d < w; d++)
//             {
//                 if (s[u][d] != 'o')
//                 {
//                     continue;
//                 }

//                 int cur = u * w + d;
//                 int nd = (d + 1) % w;
//                 if (s[u][nd] == 'o')
//                 {
//                     int nxt = u * w + nd;
//                     adj[cur].push_back(nxt);
//                     indeg[nxt]++;
//                 }

//                 for (int v : g[u])
//                 {
//                     if (s[v][nd] == 'o')
//                     {
//                         int nxt = v * w + nd;
//                         adj[cur].push_back(nxt);
//                         indeg[nxt]++;
//                     }
//                 }
//             }
//         }

//         queue<int> q;
//         for (int i = 0; i < tot; i++)
//         {
//             int u = i / w;
//             int d = i % w;
//             if (s[u][d] == 'o' && !indeg[i])
//             {
//                 q.push(i);
//             }
//         }

//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             for (int v :adj[u])
//             {
//                 if (--indeg[v] == 0)
//                 {
//                     q.push(v);
//                 }
//             }
//         }

//         bool ok = false;
//         for (int i = 0; i < tot; i++)
//         {
//             int u = i / w;
//             int d = i % w;
//             if (s[u][d] == 'o' && indeg[i])
//             {
//                 ok = true;
//                 break;
//             }
//         }


//         if (ok)
//         {
//             cout<<"Yes"<<endl;
//         }
//         else
//         {
//             cout<<"No"<<endl;
//         }
//     }

//     return 0;
// }