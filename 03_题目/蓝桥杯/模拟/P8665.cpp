// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     scanf("%d", &T);

//     while (T--)
//     {
//         int n = 2;
//         int t = 0;
//         while(n--)
//         {
//             int h1, m1, s1;
//             int h2, m2, s2;
//             int d = 0;
//             // 遇到需严格匹配格式的输入和输出时，可使用 scanf 和 printf
//             scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);

//             scanf(" (+%d)", &d);

//             t += (h2 * 3600 + m2 * 60 + s2 + d * 24 * 3600) - (h1 * 3600 + m1 * 60 + s1);
//         }

//         // 飞行时间 = （去程差 + 回程差）/ 2
//         t /= 2;

//         int hh = t / 3600;
//         int mm = t % 3600 / 60;
//         int ss = t % 3600 % 60;

//         printf("%02d:%02d:%02d\n", hh, mm, ss);
//     }

//     return 0;
// }