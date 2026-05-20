// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const ll INF = 1e18;

// struct State
// {
//     ll dist;
//     int u, used;

//     bool operator>(const State& other) const
//     {
//         return dist > other.dist;
//     }
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, m, k;
//         cin>>n>>m>>k;

//         int s, t;
//         cin>>s>>t;

//         vector<vector<pair<int, int>>> g(n);
//         for (int i = 0; i < m; i++)
//         {
//             int u, v, w;
//             cin>>u>>v>>w;

//             g[u].push_back({v, w});
//             g[v].push_back({u, w});
//         }
        

//         // 分层图最短路问题
//         // 我们可以将“已使用的免费次数”作为另一维状态，
//         // 构造一个 (k + 1) 层的图，每层表示已经免费使用了多少条边


//         // 花费, 节点, 已用次数
//         priority_queue<State, vector<State>, greater<State>> pq;
//         // dist[u][i]表示：从起点到节点 u，恰好使用了 i 次免费机会的最小花费

//         // 不使用免费机会：花费增加 w，已用次数不变
//         // 即 dist[v][used] = min(dist[v][used], dist[u][used] + w)

//         // 使用一次免费机会（如果 used < k）：花费不变，已用次数加1
//         // 即 dist[v][used+1] = min(dist[v][used+1], dist[u][used])
//         vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));
//         dist[s][0] = 0;
//         pq.push({0, s, 0});
//         while (!pq.empty())
//         {
//             State cur = pq.top();
//             pq.pop();

//             if (cur.dist != dist[cur.u][cur.used])
//             {
//                 continue;
//             }

//             for (auto [v, w] : g[cur.u])
//             {
//                 if (dist[v][cur.used] > cur.dist + w)
//                 {
//                     dist[v][cur.used] = cur.dist + w;
//                     pq.push({dist[v][cur.used], v, cur.used});
//                 }

//                 if (cur.used < k && dist[v][cur.used + 1] > cur.dist)
//                 {
//                     dist[v][cur.used + 1] = cur.dist;
//                     pq.push({dist[v][cur.used + 1], v, cur.used + 1});
//                 }
//             }
//         }

//         ll ans = INF;
//         for (int i = 0; i <= k; i++)
//         {
//             ans = min(ans, dist[t][i]);
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }