// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// bool is_leap(int y)
// {
//     if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//     {
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int m, d1, n, d2, k;
//         cin>>m>>d1>>n>>d2>>k;

//         // 如果两人生日相同，则每年都满足
//         if (m == n && d1 == d2)
//         {
//             for (int y = 2025; y < 2025 + k; y++)
//             {
//                 cout<<y<<endl;
//             }
//             continue;
//         }

//         // 是否找到相同的
//         bool ok = false;
//         for (int y = 2025; y < 2025 + k; y++)
//         {
//             // 生日天数差
//             int dif = 0;
//             int dd1 = 0, dd2 = 0;
//             // 闰年
//             if (is_leap(y))
//             {
//                 for (int i = 1; i < m; i++)
//                 {
//                     dd1 += day[i - 1];
//                     if (i == 2)
//                     {
//                         dd1++;
//                     }
//                 }
//                 dd1 += d1;
//                 for (int i = 1; i < n; i++)
//                 {
//                     dd2 += day[i - 1];
//                     if (i == 2)
//                     {
//                         dd2++;
//                     }
//                 }
//                 dd2 += d2;
//             }
//             // 平年
//             else
//             {
//                 // 如果一个为 2月29日，则当成 2月28日
//                 if (m == 2 && d1 == 29)
//                 {
//                     dd1 = 31 + 28;
//                     for (int i = 1; i < n; i++)
//                     {
//                         dd2 += day[i - 1];
//                     }
//                     dd2 += d2;
//                 }
//                 else if (n == 2 && d2 == 29)
//                 {
//                     dd2 = 31 + 28;
//                     for (int i = 1; i < m; i++)
//                     {
//                         dd1 += day[i - 1];
//                     }
//                     dd1 += d1;
//                 }
//                 else
//                 {
//                     for (int i = 1; i < m; i++)
//                     {
//                         dd1 += day[i - 1];
//                     }
//                     dd1 += d1;
//                     for (int i = 1; i < n; i++)
//                     {
//                         dd2 += day[i - 1];
//                     }
//                     dd2 += d2;
//                 }
//             }
//             dif = abs(dd1 - dd2);
//             // 同一星期几
//             if (dif % 7 == 0)
//             {
//                 cout<<y<<endl;
//                 ok = true;
//             }
//         }
//         // 没找到
//         if (!ok)
//         {
//             cout<<"No Answer"<<endl;
//         }
//     }

//     return 0;
// }