// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int ans = 0;

// // x:第一种糖果剩余数量
// // y：第二种糖果剩余数量
// // cnt：拿了糖果的小朋友数
// void dfs(int x, int y, int cnt)
// {
//     if (cnt == 7)
//     {
//         // 两种糖果都分完，则方案数加 1
//         if (x == 0 && y == 0)
//         {
//             ans++;
//         }
//         return;
//     }

//     // 每个小朋友分得的糖果总数
//     for (int t = 2; t <= 5; t++)
//     {
//         // 枚举第一种糖果数
//         for (int a = 0; a <= t; a++)
//         {
//             // 第二种糖果数
//             int b = t - a;
//             if (x - a >= 0 && y - b >= 0)
//             {
//                 dfs(x - a, y - b, cnt + 1);
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
//         dfs(9, 16, 0);

//         cout<<ans<<endl;
//     }

//     return 0;
// }