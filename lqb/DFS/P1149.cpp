// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int cost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
// const int MAXN = 2010;

// vector<int> num(MAXN, 0);

// // 预处理
// void pre()
// {
//     num[0] = 6;
//     // 计算出 1-2000 的数所需的火柴数
//     for (int i = 1; i < MAXN; i++)
//     {
//         int t = i;
//         while (t != 0)
//         {
//             num[i] += cost[t % 10];
//             t /= 10;
//         }
//     }
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

//         pre();

//         int ans = 0;
//         // 根据 n<=24，且需要 4 根火柴用作+和=
//         // 尝试(1111 + 0 = 1111，需要 22 + 4 = 26 根火柴)可推出
//         // A/B 最大不超过 1000
//         // 枚举 A 和 B
//         for (int i = 0; i <= 1000; i++)
//         {
//             for (int j = 0; j <= 1000; j++)
//             {
//                 if (num[i] + num[j] + num[i + j] + 4 == n)
//                 {
//                     ans++;
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }