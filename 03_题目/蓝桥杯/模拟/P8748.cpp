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
//         ll st;
//         scanf("%lld", &st);

//         st /= 1000;

//         // 小时在[0, 23]之间
//         int hh = st / 3600 % 24;
//         // 分钟在[0, 59]之间
//         int mm = st % 3600 / 60;
//         // 秒在[0, 59]之间
//         int ss = st % 3600 % 60;

//         printf("%02d:%02d:%02d\n", hh, mm, ss);
//     }

//     return 0;
// }