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

//         vector<pair<int, int>> a;
//         for (int i = 1; i <= n; i++)
//         {
//             int p;
//             cin>>p;
//             a.push_back({p, i});
//         }

//         sort(a.begin(), a.end());

//         // 对于每个 i，我们有两种选择：
//         //      1. 让它对撞相等的数，让资源自生自灭，约等于差值减少一倍资源。
//         //      2. 让最小数 1 去当敢死队冲锋，差值减少两倍资源。

//         ll ans = 0;
//         // 最坏情况
//         ll sum = 1LL * n * (n + 1) >> 1;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             sum -= a[i].second;
//             // 是否用相等的数对撞
//             ans = max(ans, sum - a[i].second);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }