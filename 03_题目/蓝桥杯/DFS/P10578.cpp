// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 记录每个状态到目标的距离
// unordered_map<string, int> dist;

// // 逆时针旋转以 (r, c) 为左上角的 2*2 区域
// string rotate(const string& s, int r, int c)
// {
//     string t = s;
//     int idx[4] = 
//     {
//         // 左上
//         r * 3 + c,
//         // 右上
//         r * 3 + c + 1,
//         // 右下
//         (r + 1) * 3 + c + 1,
//         // 左下
//         (r + 1) * 3 + c
//     };

//     // 逆时针旋转：
//     // 左上 <- 右上
//     t[idx[0]] = s[idx[1]];
//     // 右上 <- 右下
//     t[idx[1]] = s[idx[2]];
//     // 右下 <- 左下
//     t[idx[2]] = s[idx[3]];
//     // 左下 <- 左上
//     t[idx[3]] = s[idx[0]];

//     return t;
// }

// void bfs()
// {
//     // 目标状态（逆推）
//     string start = "123456789";
//     queue<string> q;
//     dist[start] = 0;
//     q.push(start);
//     while (!q.empty())
//     {
//         string u = q.front();
//         q.pop();

//         int d = dist[u];
//         // 枚举 4 个 可能的 2*2 区域
//         for (int r = 0; r < 2; r++)
//         {
//             for (int c = 0; c < 2; c++)
//             {
//                 string v = rotate(u, r, c);
//                 if (!dist.count(v))
//                 {
//                     dist[v] = d + 1;
//                     q.push(v);
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     // 预计算出所有可达状态的最短距离
//     bfs();

//     while (T--)
//     {
//         string s;
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 char ch;
//                 cin>>ch;
//                 s += ch;
//             }
//         }

//         cout<<dist[s]<<endl;
//     }

//     return 0;
// }