// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 各个月天数
// int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// // 是否为闰年
// bool is_leap(int y)
// {
//     return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         // 初始日期
//         int yy = n / 10000;
//         int mm = n % 10000 / 100;
//         int dd = n % 100;

//         // 下一个 回文日期 和 ABABBABA型日期
//         int ans1 = 0, ans2 = 0;
//         // 是否找到答案
//         bool ok1 = false, ok2 = false;

//         // 先枚举当月
//         int d1 = days[mm - 1];
//         // 闰年而且是二月，则天数+1
//         if (is_leap(yy) && mm == 2)
//         {
//             d1++;
//         }
//         for (int d = dd + 1; d <= d1; d++)
//         {
//             int t = yy * 10000 + mm * 100 + d;
//             string s = to_string(t);
//             bool ok = true;
//             // 是否为回文日期
//             for (int i = 0; i < 4; i++)
//             {
//                 if (s[i] != s[7 - i])
//                 {
//                     ok = false;
//                     break;
//                 }
//             }
//             if (ok)
//             {
//                 ans1 = t;
//                 ok1 = true;
//                 break;
//             }
//         }
//         for (int d = dd + 1; d <= d1; d++)
//         {
//             int t = yy * 10000 + mm * 100 + d;
//             string s = to_string(t);
//             // 是否为 ABABBABA型日期
//             if (s[0] == s[2] && s[0] != s[1] && s[1] == s[3] && s[3] == s[4] && s[2] == s[5] && s[3] != s[5] && s[4] == s[6] && s[5] == s[7])
//             {
//                 ans2 = t;
//                 ok2 = true;
//                 break;
//             }
//         }

//         // 都已经找到了
//         if (ok1 && ok2)
//         {
//             cout<<ans1<<endl<<ans2<<endl;
//             return 0;
//         }

//         // 还没找到回文日期
//         if (!ok1)
//         {
//             // 枚举当年
//             for (int m = mm + 1; m <= 12; m++)
//             {
//                 int d2 = days[m - 1];
//                 if (is_leap(yy) && m == 2)
//                 {
//                     d2++;
//                 }
//                 for (int d = 1; d <= d2; d++)
//                 {
//                     int t = yy * 10000 + m * 100 + d;
//                     string s = to_string(t);
//                     bool ok = true;
//                     for (int i = 0; i < 4; i++)
//                     {
//                         if (s[i] != s[7 - i])
//                         {
//                             ok = false;
//                             break;
//                         }
//                     }
//                     if (ok)
//                     {
//                         ans1 = t;
//                         ok1 = true;
//                         break;
//                     }
//                 }
//                 if (ok1)
//                 {
//                     break;
//                 }
//             }
//         }
        
//         // 还没找到 ABABBABA型日期
//         if (!ok2)
//         {
//             // 枚举当年
//             for (int m = mm + 1; m <= 12; m++)
//             {
//                 int d2 = days[m - 1];
//                 if (is_leap(yy) && m == 2)
//                 {
//                     d2++;
//                 }
//                 for (int d = 1; d <= d2; d++)
//                 {
//                     int t = yy * 10000 + m * 100 + d;
//                     string s = to_string(t);
//                     if (s[0] == s[2] && s[0] != s[1] && s[1] == s[3] && s[3] == s[4] && s[2] == s[5] && s[3] != s[5] && s[4] == s[6] && s[5] == s[7])
//                     {
//                         ans2 = t;
//                         ok2 = true;
//                         break;
//                     }
//                 }
//                 if (ok2)
//                 {
//                     break;
//                 }
//             }
//         }
        
//         // 都已经找到了
//         if (ok1 && ok2)
//         {
//             cout<<ans1<<endl<<ans2<<endl;
//             return 0;
//         }

//         // 还没找到回文日期
//         if (!ok1)
//         {
//             // 枚举之后各年各月各日
//             for (int y = yy + 1; y <= 100000; y++)
//             {
//                 for (int m = 1; m <= 12; m++)
//                 {
//                     int d3 = days[m - 1];
//                     if (is_leap(y) && m == 2)
//                     {
//                         d3++;
//                     }
//                     for (int d = 1; d <= d3; d++)
//                     {
//                         int t = y * 10000 + m * 100 + d;
//                         string s = to_string(t);
//                         bool ok = true;
//                         for (int i = 0; i < 4; i++)
//                         {
//                             if (s[i] != s[7 - i])
//                             {
//                                 ok = false;
//                                 break;
//                             }
//                         }
//                         if (ok)
//                         {
//                             ans1 = t;
//                             ok1 = true;
//                             break;
//                         }
//                     }
//                     if (ok1)
//                     {
//                         break;
//                     }
//                 }
//                 if (ok1)
//                 {
//                     break;
//                 }
//             }
//         }
        
//         // 还没找到 ABABBABA型日期
//         if (!ok2)
//         {
//             // 枚举之后各年各月各日
//             for (int y = yy + 1; y <= 100000; y++)
//             {
//                 for (int m = 1; m <= 12; m++)
//                 {
//                     int d3 = days[m - 1];
//                     if (is_leap(y) && m == 2)
//                     {
//                         d3++;
//                     }
//                     for (int d = 1; d <= d3; d++)
//                     {
//                         int t = y * 10000 + m * 100 + d;
//                         string s = to_string(t);
//                         if (s[0] == s[2] && s[0] != s[1] && s[1] == s[3] && s[3] == s[4] && s[2] == s[5] && s[3] != s[5] && s[4] == s[6] && s[5] == s[7])
//                         {
//                             ans2 = t;
//                             ok2 = true;
//                             break;
//                         }
//                     }
//                     if (ok2)
//                     {
//                         break;
//                     }
//                 }
//                 if (ok2)
//                 {
//                     break;
//                 }
//             }
//         }
        

//         cout<<ans1<<endl<<ans2<<endl;
//     }

//     return 0;
// }