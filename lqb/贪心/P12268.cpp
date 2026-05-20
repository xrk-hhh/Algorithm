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
//         int n, m;
//         cin>>n>>m;

//         int maxx = 0, minn = n + 1;
//         for (int i = 0; i < m; i++)
//         {
//             int p;
//             cin>>p;

//             maxx = max(maxx, p);
//             minn = min(minn, p);
//         }

//         // 最大号码为 max(abs(i - p[j]))
//         // 注意到：只与 p 的最大值maxx 和 最小值minn有关

//         for (int i = 1; i <= n; i++)
//         {
//             int ans = max(abs(maxx - i), abs(i - minn));

//             cout<<ans<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }