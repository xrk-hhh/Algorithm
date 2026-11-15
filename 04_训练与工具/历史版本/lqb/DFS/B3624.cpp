// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n, l, r;
// vector<int> w;
// vector<int> lsum, rsum;

// // // 折半搜索：将原数组分成两半，分别枚举所有子集和，然后合并统计。

// // void dfs(int idx, int end, int sum, vector<int>& sums)
// // {
// //     if (idx == end)
// //     {
// //         sums.push_back(sum);
// //         return;
// //     }

// //     dfs(idx + 1, end, sum, sums);

// //     dfs(idx + 1, end, sum + w[idx], sums);
// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>l>>r;
//         w.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>w[i];
//         }

//         int mid = (n >> 1);

//         for (int mask = 0; mask < (1 << mid); mask++)
//         {
//             int sum = 0;
//             for (int i = 0; i < mid; i++)
//             {
//                 if ((mask >> i) & 1)
//                 {
//                     sum += w[i];
//                 }
//             }
//             lsum.push_back(sum);
//         }
//         for (int mask = 0; mask < (1 << (n - mid)); mask++)
//         {
//             int sum = 0;
//             for (int i = 0; i < (n - mid); i++)
//             {
//                 if ((mask >> i) & 1)
//                 {
//                     sum += w[mid + i];
//                 }
//             }
//             rsum.push_back(sum);
//         }

//         // // 枚举左半部分的所有子集，计算每个子集的和
//         // dfs(0, mid, 0, lsum);
//         // // 枚举右半部分的所有子集，计算每个子集的和
//         // dfs(mid, n, 0, rsum);

//         // 对右半部分排序
//         sort(rsum.begin(), rsum.end());

//         ll ans = 0;
//         // 遍历左半部分中的每个和
//         // 统计右半部分中有多少个 y 满足 (x+y)∈[l, r] 
//         // 即 y∈[l-x, r-x]
//         for (int x : lsum)
//         {
//             int low = l - x;
//             int high = r - x;

//             // 二分查找得到区间个数
//             auto itl = lower_bound(rsum.begin(), rsum.end(), low);
//             auto itr = upper_bound(rsum.begin(), rsum.end(), high);

//             ans += (itr - itl);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }