// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, m;
// vector<int> a;

// bool check(int x)
// {
//     int maxx = 0;
//     int cnt = 0;
//     // 最长的一段的长度为 x
//     for (int i = 0; i < n; i++)
//     {
//         // 若该段长度 > x
//         if (a[i] > x)
//         {
//             // 每切一刀，段数 +1，而最少段数 t 满足 L/t <= x
//             // 则有 t >= L/x，即有 t = ceil(L/x)
//             // 则至少需要切 ceil(L/x) - 1次
//             int t = (a[i] + x - 1) / x;
//             cnt += t - 1;
//             // 需要切的次数大于 m，则无法满足
//             if (cnt > m)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
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
//         int maxx = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             maxx = max(maxx, a[i]);
//         }

//         // 二分答案：最小化最大值
//         int l = 1, r = maxx + 1;
//         while (l < r)
//         {
//             int mid = (l + r) >> 1;
//             if (check(mid))
//             {
//                 r = mid;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         cout<<r<<endl;
//     }

//     return 0;
// }