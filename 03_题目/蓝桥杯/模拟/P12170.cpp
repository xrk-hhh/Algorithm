// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int sum = 0;
//         int ans = 1;

//         // 一起攻击
//         while (sum < 2025)
//         {
//             int t = 5;

//             if (ans & 1)
//             {
//                 t += 15;
//             }
//             else
//             {
//                 t += 2;
//             }

//             int r = ans % 3;
//             if (r == 1)
//             {
//                 t += 2;
//             }
//             else if (r == 2)
//             {
//                 t += 10;
//             }
//             else if (r == 0)
//             {
//                 t += 7;
//             }

//             sum += t;
//             ans++;
//         }

//         // // 只有攻击最高的攻击
//         // while (sum < 2025)
//         // {
//         //     int maxx = 5;

//         //     int t1;
//         //     if (ans & 1)
//         //     {
//         //         t1 = 15;
//         //     }
//         //     else
//         //     {
//         //         t1 = 2;
//         //     }
//         //     maxx = max(maxx, t1);

//         //     int t2;
//         //     int r = ans % 3;
//         //     if (r == 1)
//         //     {
//         //         t2 = 2;
//         //     }
//         //     else if (r == 2)
//         //     {
//         //         t2 = 10;
//         //     }
//         //     else if (r == 0)
//         //     {
//         //         t2 = 7;
//         //     }
//         //     maxx = max(maxx, t2);

//         //     sum += maxx;
//         //     ans++;
//         // }

//         cout<<ans - 1<<endl;
//     }

//     return 0;
// }