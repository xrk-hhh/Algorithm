// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, m;
// ll sum;
// int maxx;
// vector<int> a;

// bool check(ll x)
// {
//     // 当前段的和
//     ll cur = 0;
//     // 段数（至少一段）
//     int cnt = 1;
//     for (int i = 0; i < n; i++)
//     {
//         // 单元素就超过 x 了，肯定不行
//         if (a[i] > x)
//         {
//             return false;
//         }

//         // 当前段还能再加
//         if (cur + a[i] <= x)
//         {
//             cur += a[i];
//         }
//         // 不能再加了，就要新开一段
//         else
//         {
//             cur = a[i];
//             cnt++;
//         }
//     }

//     // 看看段数是否 小于等于 m
//     return cnt <= m;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>m;
//         a.resize(n);
//         sum = 0;
//         maxx = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             sum += a[i];
//             maxx = max(maxx, a[i]);
//         }

//         ll l = maxx, r = sum + 1;
//         // 二分答案（最小值）
//         while (l < r)
//         {
//             ll mid = (l + r) >> 1;
//             if (check(mid))
//             {
//                 r = mid;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         cout<<l<<endl;
//     }

//     return 0;
// }