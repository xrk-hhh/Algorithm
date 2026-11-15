// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// vector<vector<int>> arr;
// int ans = 0;

// void dfs(int r, int c)
// {
//     // 处理完所有行
//     if (r == 5)
//     {
//         // 最终输出结果为 1，方案数加 1
//         if (arr[4][0] == 1)
//         {
//             ans++;
//         }
//         return;
//     }

//     // 处理完该行
//     if (r + c == 5)
//     {
//         dfs(r + 1, 0);
//         return;
//     }

//     // 已经处理过
//     if (arr[r][c] != -1)
//     {
//         dfs(r, c + 1);
//         return;
//     }

//     // 尝试 &
//     arr[r][c] = arr[r - 1][c] & arr[r - 1][c + 1];
//     dfs(r, c + 1);

//     // 尝试 |
//     arr[r][c] = arr[r - 1][c] | arr[r - 1][c + 1];
//     dfs(r, c + 1);

//     // 尝试 ^
//     arr[r][c] = arr[r - 1][c] ^ arr[r - 1][c + 1];
//     dfs(r, c + 1);
//     arr[r][c] = -1;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         // 初始化
//         arr.assign(5, vector<int>(5, -1));
//         arr[0] = {1, 0, 1, 0, 1};

//         dfs(1, 0);

//         cout<<ans<<endl;
//     }

//     return 0;
// }