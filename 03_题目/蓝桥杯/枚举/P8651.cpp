// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
//         int a, b, c;
//         scanf("%d/%d/%d", &a, &b, &c);

//         for (int y = 1960; y <= 2059; y++)
//         {
//             // 注意闰年
//             days[1] = (is_leap(y) ? 29 : 28);
//             for (int m = 1; m <= 12; m++)
//             {
//                 for (int d = 1; d <= days[m - 1]; d++)
//                 {
//                     // 满足日期格式
//                     if ((a == y % 100 && b == m && c == d) ||
//                         (a == m && b == d && c == y % 100) ||
//                         (a == d && b == m && c == y % 100))
//                     {
//                         printf("%d-%02d-%02d\n", y, m, d);
//                     }
//                 }
//             }
//         }
//     }

//     return 0;
// }