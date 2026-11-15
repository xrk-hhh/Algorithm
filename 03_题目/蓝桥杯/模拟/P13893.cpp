// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // // 结构体表示 时间
// // struct times
// // {
// //     int y, m, d, h, mm, s;
// // };

// // vector<times> a;

// // // 时间先后判断函数
// // bool cmp(times a, times b)
// // {
// //     if (a.y != b.y)
// //     {
// //         return a.y < b.y;
// //     }
// //     if (a.m != b.m)
// //     {
// //         return a.m < b.m;
// //     }
// //     if (a.d != b.d)
// //     {
// //         return a.d < b.d;
// //     }
// //     if (a.h != b.h)
// //     {
// //         return a.h < b.h;
// //     }
// //     if (a.mm != b.mm)
// //     {
// //         return a.mm < b.mm;
// //     }
// //     return a.s < b.s;
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         a.resize(520);
// //         for (int i = 0; i < 520; i++)
// //         {
// //             // 使用 scanf 输入数据
// //             scanf("%d-%d-%d  %d:%d:%d\r\n", &a[i].y, &a[i].m, &a[i].d, &a[i].h, &a[i].mm, &a[i].s);
// //         }

// //         // 对时间数据进行排序
// //         sort(a.begin(), a.end(), cmp);

// //         int ans = 0;
// //         for (int i = 0; i < 520; i += 2)
// //         {
// //             ans += a[i + 1].h * 3600 + a[i + 1].mm * 60 + a[i + 1].s - a[i].h * 3600 - a[i].mm * 60 - a[i].s;
// //         }

// //         printf("%d\n", ans);
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// #define endl '\n'

// struct times 
// {
//     int y, m, d, h, mm, s;
// };

// bool cmp(const times& a, const times& b) 
// {
//     if (a.y != b.y) return a.y < b.y;
//     if (a.m != b.m) return a.m < b.m;
//     if (a.d != b.d) return a.d < b.d;
//     if (a.h != b.h) return a.h < b.h;
//     if (a.mm != b.mm) return a.mm < b.mm;
//     return a.s < b.s;
// }

// // 将时间转换为从当年 1月1日0时 开始的秒数
// int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// ll to_seconds(const times& t) 
// {
//     ll total = 0;
//     for (int i = 1; i < t.m; i++) 
//     {
//         total += days_in_month[i- 1] * 24 * 3600;
//     }
//     total += (t.d - 1) * 24 * 3600;
//     total += t.h * 3600 + t.mm * 60 + t.s;
//     return total;
// }

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--) 
//     {
//         vector<times> a(520);
//         for (int i = 0; i < 520; i++) 
//         {
//             scanf("%d-%d-%d %d:%d:%d", &a[i].y, &a[i].m, &a[i].d, &a[i].h, &a[i].mm, &a[i].s);
//         }
//         sort(a.begin(), a.end(), cmp);
//         ll ans = 0;
//         for (int i = 0; i < 520; i += 2) 
//         {
//             ans += to_seconds(a[i+1]) - to_seconds(a[i]);
//         }
//         printf("%lld\n", ans);
//     }
//     return 0;
// }