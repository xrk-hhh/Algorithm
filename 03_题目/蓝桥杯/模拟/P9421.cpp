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
//         int n;
//         cin>>n;

//         map<int, int> cnt;
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin>>a;
//             cnt[a]++;
//         }

//         // sum1：出现次数小于 2 的个数
//         // sum2：出现次数大于 2 的个数
//         int sum1 = 0, sum2 = 0;
//         for (auto it = cnt.begin(); it != cnt.end(); it++)
//         {
//             if (it->second < 2)
//             {
//                 sum1++;
//             }
//             else if (it->second > 2)
//             {
//                 sum2 += it->second - 2;
//             }
//         }

//         // 如果 sum1 <= sum2，那么出现次数大于 2 的数足够分配给 出现次数为 1 的数
//         // 只需修改所有出现次数大于 2 的数，直至其出现次数为 2
//         // 如：1, 2, 2, 2, 3, 3, 3, 3
//         // 只需修改为：1, 1, 2, 2, 3, 3, 4, 4
//         // 共 sum2 次
//         // 如果 sum1 > sum2，则还需修改(sum1 - sum2)个出现次数为 1 的数，每两个为一组，要修改(sum1 - sum2) / 2 个
//         cout<<sum2 + max(sum1 - sum2, 0) / 2<<endl;
//     }

//     return 0;
// }