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
//         int ans = 0;
//         // 枚举目标面值
//         for (int i = 1; i <= 4046; i++)
//         {
//             int sum = 0;
//             // 第一枚硬币上限
//             int k = min(2024, i);
//             // 枚举第一枚硬币
//             for (int j = 1; j < k; j++)
//             {
//                 // 不存在这样的第二枚硬币
//                 if (i - j > 2023)
//                 {
//                     continue;
//                 }
//                 int t;
//                 if (i - j == j)
//                 {
//                     t = j >> 1;
//                 }
//                 else
//                 {
//                     t = min(j, i - j);
//                 }

//                 sum += t;
//             }

//             // 重复计数要除以2
//             sum >>= 1;

//             // 加上本来就有的
//             if (i <= 2023)
//             {
//                 sum += i;
//             }
//             ans = max(ans, sum);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }