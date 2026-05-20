// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, k;
// vector<int> h, w;

// bool check(int x)
// {
//     ll cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // 最多可以切成多少块
//         cnt += 1LL * (h[i] / x) * (w[i] / x);
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
//         cin>>n>>k;

//         h.resize(n);
//         w.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>h[i]>>w[i];
//         }

//         // 二分答案（求最大值）
//         int l = 1, r = 1e5;
//         while (l < r)
//         {
//             // 记得 +1 防止陷入循环（配合 l = mid）
//             int mid = (l + r + 1) >> 1;
//             if (check(mid))
//             {
//                 // mid 可以，则考虑[mid, r]
//                 l = mid;
//             }
//             else
//             {
//                 // mid 不行，则考虑[l, mid - 1]
//                 r = mid - 1;
//             }
//         }

//         cout<<r<<endl;
//     }

//     return 0;
// }