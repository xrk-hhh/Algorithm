// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, m;
// ll k;
// vector<int> a, b;

// bool check(ll x)
// {
//     ll cnt = 0;
//     // 双指针优化（a 和 b 均已排序，则答案具有单调性，考虑双指针）
//     for (int i = 0, j = m - 1; i < n; i++)
//     {
//         while (j >= 0 && a[i] + b[j] > x)
//         {
//             j--;
//         }
//         cnt += j + 1;
//         // 有 k 个小的
//         if (cnt >= k)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>m>>k;
//         a.resize(n);
//         b.resize(m);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin>>b[i];
//         }

//         sort(a.begin(), a.end());
//         sort(b.begin(), b.end());

//         // 左闭右开形式
//         ll l = a[0] + b[0], r = a[n - 1] + b[m - 1] + 1;
//         // 二分答案
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