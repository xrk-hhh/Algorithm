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
//         int w, m, n;
//         cin>>w>>m>>n;

//         // 行
//         int hm = (m + w - 1) / w;
//         int hn = (n + w - 1) / w;
//         // 列
//         int cm, cn;
//         // 奇数行
//         if (hm & 1)
//         {
//             if (m % w == 0)
//             {
//                 cm = w;
//             }
//             else
//             {
//                 cm = m % w;
//             }
//         }
//         // 偶数行
//         else
//         {
//             if (m % w == 0)
//             {
//                 cm = 1;
//             }
//             else
//             {
//                 cm = w - m % w + 1;
//             }
//         }
//         if (hn & 1)
//         {
//             if (n % w == 0)
//             {
//                 cn = w;
//             }
//             else
//             {
//                 cn = n % w;
//             }
//         }
//         else
//         {
//             if (n % w == 0)
//             {
//                 cn = 1;
//             }
//             else
//             {
//                 cn = w - n % w + 1;
//             }
//         }

//         // 行差 + 列差
//         cout<<abs(hm - hn) + abs(cm - cn)<<endl;
//     }

//     return 0;
// }