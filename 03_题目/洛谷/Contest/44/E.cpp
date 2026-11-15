// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// void dfs(int& x, int& y, int z, int c)
// {
//     if ((x + y) & 1)
//     {
//         x -= y % x;
//     }
//     else
//     {
//         y -= x % y;
//     }

//     if (x < c)
//     {
//         x += y / 2 + 1;
//     }
//     if (y < c)
//     {
//         y += x / 2 + 1;
//     }

//     c++;
//     if (c < z)
//     {
//         dfs(x, y, z, c);
//     }
//     else
//     {
//         return;
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
//         int xx, yy, z;
//         cin>>xx>>yy>>z;

//         int cnt = 0;
//         for (int i = 10; i <= 99; i++)
//         {
//             for (int j = 10; j <= 99; j++)
//             {
//                 int x = i;
//                 int y = j;
//                 dfs(x, y, z, 0);
//                 if (x == xx && y == yy)
//                 {
//                     cnt++;
//                 }
//             }
//         }

//         cout<<cnt<<endl;
//     }

//     return 0;
// }