// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 结构体包装时间
// struct times
// {
//     int y, m, d, h, mm, s;
// };

// // 各个月天数
// const int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// // 是否为闰年
// bool is_leap(int y)
// {
//     return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
// }

// // 将时间转换秒数
// ll to_seconds(const times& t)
// {
//     ll total = 0;
//     for (int y = 1970; y < t.y; y++)
//     {
//         total += is_leap(y) ? 366 : 365;
//     }
//     for (int m = 1; m < t.m; m++)
//     {
//         total += day[m - 1];
//         if (m == 2 && is_leap(t.y))
//         {
//             total += 1;
//         }
//     }
//     total += t.d - 1;
//     total = total * 24 * 3600 + t.h * 3600 + t.mm * 60 + t.s;

//     return total;
// }

// // 将秒数转换为标准时间表示
// void to_time(ll seconds, times& t)
// {
//     ll d = seconds / (24 * 3600);
//     seconds %= (24 * 3600);
//     t.h = seconds / 3600;
//     seconds %= 3600;
//     t.mm = seconds / 60;
//     t.s = seconds % 60;

//     t.y = 1970;
//     while (d >= (is_leap(t.y) ? 366 : 365))
//     {
//         d -= is_leap(t.y) ? 366 : 365;
//         t.y++;
//     }
//     t.m = 1;
//     while (1)
//     {
//         int dd = day[t.m - 1];
//         if (t.m == 2 && is_leap(t.y))
//         {
//             dd += 1;
//         }
//         if (d < dd)
//         {
//             break;
//         }
//         d -= dd;
//         t.m++;
//     }
//     t.d = d + 1;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     scanf("%d", &T);

//     while (T--)
//     {
//         times t;
//         int x;
//         // 使用 scanf 处理标准时间输入
//         scanf("%d-%d-%d %d:%d:%d %d", &t.y, &t.m, &t.d, &t.h, &t.mm, &t.s, &x);
        
//         ll seconds = to_seconds(t);
//         ll minuetes = seconds / 60;
//         ll alarm_m = (minuetes / x) * x;
//         ll alarm_s = alarm_m * 60;

//         times ans;
//         to_time(alarm_s, ans);

//         printf("%04d-%02d-%02d %02d:%02d:%02d\n", ans.y, ans.m, ans.d, ans.h, ans.mm, ans.s);
//     }

//     return 0;
// }