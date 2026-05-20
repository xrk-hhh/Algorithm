// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int N, A, B;
//         cin>>N>>A>>B;

//         vector<int> K(N + 1);
//         for (int i = 1; i <= N; i++)
//         {
//             cin>>K[i];
//         }

//         vector<int> dist(N + 1, -1);
//         queue<int> q;
//         dist[A] = 0;
//         q.push(A);

//         while (!q.empty())
//         {
//             int u = q.front();
//             q.pop();

//             int up = u + K[u];
//             if (up <= N && dist[up] == -1)
//             {
//                 dist[up] = dist[u] + 1;
//                 q.push(up);
//             }

//             int down = u - K[u];
//             if (down >= 1 && dist[down] == -1)
//             {
//                 dist[down] = dist[u] + 1;
//                 q.push(down);
//             }
//         }

//         cout<<dist[B]<<endl;
//     }

//     return 0;
// }