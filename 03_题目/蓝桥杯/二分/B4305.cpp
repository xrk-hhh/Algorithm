// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, k;
// vector<int> a;

// bool check(int x)
// {
//     // 当前已用的组数
//     int cnt = 1;
//     // 当前组的和
//     int cur = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // 单个物品超过 x，不满足
//         if (a[i] > x)
//         {
//             return false;
//         }

//         // 加在当前组后依旧满足题意，则加入
//         if (cur + a[i] <= x)
//         {
//             cur += a[i];
//         }
//         // 否则，开一组新的
//         else
//         {
//             cnt++;
//             cur = a[i];
//         }
//     }
//     // 看看有多少组
//     return cnt <= k;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;
//         a.resize(n);
//         int maxx = 0, sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             sum += a[i];
//             maxx = max(maxx, a[i]);
//         }
//         cin>>k;

//         // 最小为单个最大和，最大为所有数之和
//         int l = maxx, r = sum;
//         // 二分答案
//         while (l < r)
//         {
//             int mid = (l + r) >> 1;
//             // mid 可行，减小上界
//             if (check(mid))
//             {
//                 r = mid;
//             }
//             // mid 不行，增大上界
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         // 要求最小的满足题意的
//         cout<<l<<endl;
//     }

//     return 0;
// }