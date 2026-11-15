// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n, d;
//         cin>>n>>d;

//         vector<ll> v(n, 0);
//         vector<int> a(n + 1);
//         for (int i = 1; i < n; i++)
//         {
//             cin>>v[i];
//             // 变成前缀和，v[i] 表示从站点1到站点i+1的距离
//             v[i] += v[i - 1];
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }
//         vector<int> minn(n + 1);
//         minn[1] = a[1];
//         for (int i = 2; i <= n; i++)
//         {
//             minn[i] = min(minn[i - 1], a[i]);
//         }
        
//         // 当前油量能行驶的总距离（从起点开始累计）
//         ll cur = 0;
//         ll ans = 0;
//         for (int i = 1; i < n; i++)
//         {
//             // 剩余油量足够到达下一个站点
//             if (cur > v[i])
//             {
//                 continue;
//             }
//             // 需要买的油量（向上取整）
//             ll k = ceil((v[i] - cur) * 1.0  / d * 1.0);
//             // 用当前已知的最便宜油价购买
//             ans += k * minn[i];
//             // 更新总油量能跑的距离
//             cur += k * d;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }