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
//         int n;
//         while (cin>>n && n)
//         {
//             string s;
//             cin>>s;

//             // 用双端队列存储身体坐标，队首为尾，队尾为头
//             deque<pair<int, int>> body;
//             vector<vector<bool>> occ(51, vector<bool>(51, false));
//             // 初始化：水平从 (25,11) 到 (25,30)
//             for (int j = 11; j <= 30; j++)
//             {
//                 body.push_back({25, j});
//                 occ[25][j] = true;
//             }

//             int cnt = 0;
//             bool failed = false;
//             for (int i = 0; i < s.size(); i++)
//             {
//                 char c = s[i];
//                 cnt++;
//                 int dx = 0, dy = 0;

//                 if (c == 'N')
//                 {
//                     dx = -1;
//                 }
//                 else if (c == 'S')
//                 {
//                     dx = 1;
//                 }
//                 else if (c == 'W')
//                 {
//                     dy = -1;
//                 }
//                 else if (c == 'E')
//                 {
//                     dy = 1;
//                 }

//                 // 当前头坐标
//                 auto [hx, hy] = body.back();
//                 int nx = hx + dx;
//                 int ny = hy + dy;

//                 // 1. 检查是否越界
//                 if (nx < 1 || nx > 50 || ny < 1 || ny > 50) 
//                 {
//                     cout<<"The worm ran off the board on move "<<cnt<<"."<<endl;
//                     failed = true;
//                     break;
//                 }

//                 // 2. 移除尾部（先移走，这样新头如果正好是尾，就不算撞到）
//                 auto [tx, ty] = body.front();
//                 occ[tx][ty] = false;
//                 body.pop_front();

//                 // 3. 检查新头是否碰到自己（此时尾已移走）
//                 if (occ[nx][ny]) 
//                 {
//                     cout<<"The worm ran into itself on move "<<cnt<<"."<<endl;
//                     failed = true;
//                     break;
//                 }

//                 // 4. 加入新头
//                 body.push_back({nx, ny});
//                 occ[nx][ny] = true;
//             }

//             if (!failed) 
//             {
//                 cout<<"The worm successfully made all "<<cnt<<" moves."<<endl;
//             }
//         }
//     }

//     return 0;
// }