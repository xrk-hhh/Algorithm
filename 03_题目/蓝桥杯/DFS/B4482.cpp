// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// vector<vector<int>> a;
// bool ok = false;

// // 4*4 数独
// // 数据规模较小，若数据规模较大，如9*9，则可用位运算进行优化(P1784)

// // 检查在 (x, y)位置放 val 是否合法
// bool check(int x, int y, int val)
// {
//     // 检查行
//     for (int j = 0; j < 4; j++)
//     {
//         if (a[x][j] == val)
//         {
//             return false;
//         }
//     }

//     // 检查列
//     for (int i = 0; i < 4; i++)
//     {
//         if (a[i][y] == val)
//         {
//             return false;
//         }
//     }

//     // 检查所在 2*2 子网格
//     int sx = (x / 2) * 2, sy = (y / 2) * 2;
//     for (int i = sx; i < sx + 2; i++)
//     {
//         for (int j = sy; j < sy + 2; j++)
//         {
//             if (a[i][j] == val)
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// // DFS枚举当前要处理的格子编号
// void dfs(int pos)
// {
//     // 已经找到解
//     if (ok)
//     {
//         return;
//     }

//     // 所有格子处理完毕
//     if (pos == 16)
//     {
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 if (j != 0)
//                 {
//                     cout<<' ';
//                 }
//                 cout<<a[i][j];
//             }
//             if (i != 3)
//             {
//                 cout<<endl;
//             }
//         }
//         ok = true;
//         return;
//     }

//     int x = pos / 4;
//     int y = pos % 4;
//     // 如果该格已填数，处理下一个
//     if (a[x][y] != 0)
//     {
//         dfs(pos + 1);
//     }
//     else
//     {
//         for (int val = 1; val <= 4; val++)
//         {
//             if (check(x, y, val))
//             {
//                 a[x][y] = val;
//                 dfs(pos + 1);
//                 // 回溯
//                 a[x][y] = 0;
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         a.resize(4, vector<int>(4));
//         for (int i = 0; i < 4; i++)
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 cin>>a[i][j];
//             }
//         }

//         dfs(0);
//     }

//     return 0;
// }