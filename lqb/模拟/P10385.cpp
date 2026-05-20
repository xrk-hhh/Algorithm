// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int pen[] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int ans = 0;
//         for (int y = 2000; y <= 2023; y++)
//         {
//             for (int m = 1; m <= 12; m++)
//             {
//                 int td;
//                 switch (m)
//                 {
//                     case 1:
//                     case 3:
//                     case 5:
//                     case 7:
//                     case 8:
//                     case 10:
//                     case 12:
//                         td = 31;
//                         break;
//                     case 2:
//                         if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//                         {
//                             td = 29;
//                         }
//                         else
//                         {
//                             td = 28;
//                         }
//                         break;
//                     case 4:
//                     case 6:
//                     case 9:
//                     case 11:
//                         td = 30;
//                         break;
//                 }
//                 for (int d = 1; d <= td; d++)
//                 {
//                     int cnt = 0;
//                     int t = y * 10000 + m * 100 + d;
//                     while (t)
//                     {
//                         cnt += pen[t % 10];
//                         t /= 10;
//                     }

//                     if (cnt > 50)
//                     {
//                         ans++;
//                     }
//                 }
//             }
//         }

//         for (int m = 1; m <= 4; m++)
//         {
//             int td;
//             if (m == 1 || m == 3)
//             {
//                 td = 31;
//             }
//             else if (m == 2)
//             {
//                 td = 29;
//             }
//             else if (m == 4)
//             {
//                 td = 13;
//             }

//             for (int d = 1; d <= td; d++)
//             {
//                 int cnt = 0;
//                 int t = 2024 * 10000 + m * 100 + d;
//                 while (t)
//                 {
//                     cnt += pen[t % 10];
//                     t /= 10;
//                 }

//                 if (cnt > 50)
//                 {
//                     ans++;
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }