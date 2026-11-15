// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, m;
// vector<int> a;

// bool check(int x)
// {
//     // 每个孩纸都分得最大数量
//     int tot = 0;
//     for (int i = 0; i < m; i++)
//     {
//         tot += (a[i] + x - 1) / x;
//     }
//     // 看看每个都分得最大数量的情况下，是否超过总人数
//     // 如果超过了，说明每个分得的最大数量还可以再增大
//     return tot <= n;
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
//         a.resize(m);
//         int maxx = 0;
//         for (int i = 0; i < m; i++)
//         {
//             cin>>a[i];
//             maxx = max(maxx, a[i]);
//         }

//         int l = 1, r = maxx + 1;
//         // 二分答案（最小值）
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

//         cout<<l<<endl;
//     }

//     return 0;
// }