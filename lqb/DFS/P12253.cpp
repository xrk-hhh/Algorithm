// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// vector<vector<int>> ans;
// // 各方向上能看到的宝塔数
// vector<int> north = {2, 2, 1, 3, 3};
// vector<int> south = {1, 4, 2, 2, 3};
// vector<int> west = {2, 2, 3, 2, 1};
// vector<int> east = {3, 3, 1, 2, 4};
// // 是否找到正解
// bool found = false;

// // 判断该行/列，是否有元素重复
// bool check(int r, int c)
// {
//     set<int> st_r;
//     for (int i = 0; i <= r; i++)
//     {
//         if (st_r.count(ans[i][c]))
//         {
//             return false;
//         }
//         st_r.insert(ans[i][c]);
//     }

//     set<int> st_c;
//     for (int j = 0; j <= c; j++)
//     {
//         if (st_c.count(ans[r][j]))
//         {
//             return false;
//         }
//         st_c.insert(ans[r][j]);
//     }

//     return true;
// }

// void dfs(int r, int c)
// {
//     // 找到正解
//     if (found)
//     {
//         return;
//     }

//     // 所有行都处理完毕
//     if (r == 5)
//     {
//         // 计算 北和南 方向上的宝塔数是否满足需求
//         for (int j = 0; j < 5; j++)
//         {
//             int cnt_n = 0, cnt_s = 0;
//             int max_n = 0, max_s = 0;
//             for (int i = 0; i < 5; i++)
//             {
//                 if (ans[i][j] > max_n)
//                 {
//                     cnt_n++;
//                     max_n = ans[i][j];
//                 }
//             }
//             if (cnt_n != north[j])
//             {
//                 return;
//             }
//             for (int i = 4; i >= 0; i--)
//             {
//                 if (ans[i][j] > max_s)
//                 {
//                     cnt_s++;
//                     max_s = ans[i][j];
//                 }
//             }
//             if (cnt_s != south[j])
//             {
//                 return;
//             }
//         }
//         // 输出答案
//         for (int i = 0; i < 5; i++)
//         {
//             for (int j = 0; j < 5; j++)
//             {
//                 cout<<ans[i][j];
//             }
//         }
//         cout<<endl;
//         found = true;
//         return;
//     }

//     // 当前行处理完毕
//     if (c == 5)
//     {
//         // 计算 西和东 方向上的宝塔数是否满足需求
//         int cnt_w = 0, cnt_e = 0;
//         int max_w = 0, max_e = 0;
//         for (int j = 0; j < 5; j++)
//         {
//             if (ans[r][j] > max_w)
//             {
//                 cnt_w++;
//                 max_w = ans[r][j];
//             }
//         }
//         if (cnt_w != west[r])
//         {
//             return;
//         }
//         for (int j = 4; j >= 0; j--)
//         {
//             if (ans[r][j] > max_e)
//             {
//                 cnt_e++;
//                 max_e = ans[r][j];
//             }
//         }
//         if (cnt_e != east[r])
//         {
//             return;
//         }

//         dfs(r + 1, 0);
//         return;
//     }

//     // 已经处理过
//     if (ans[r][c] != -1)
//     {
//         dfs(r, c + 1);
//         return;
//     }

//     // 尝试 1-5
//     for (int i = 1; i <= 5; i++)
//     {
//         ans[r][c] = i;
//         if (check(r, c))
//         {
//             dfs(r, c + 1);
//         }
//     }
//     // 回溯
//     ans[r][c] = -1;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         // 初始为 -1
//         ans.assign(5, vector<int>(5, -1));

//         dfs(0, 0);
//     }

//     return 0;
// }