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
//         int n, q;
//         cin>>n>>q;

//         // 下方牌
//         vector<int> down(n + 1, 0);
//         while (q--)
//         {
//             int c, p;
//             cin>>c>>p;

//             down[c] = p;
//         }

//         vector<bool> vis(n + 1, false);
//         vector<int> ans(n + 1, 0);
//         // 遍历所有牌
//         for (int i = 1; i <= n; i++)
//         {
//             if (vis[i])
//             {
//                 continue;
//             }

//             int cur = i;
//             int cnt = 1;
//             vis[cur] = true;
//             // 从 i 开始往下走直到底部，统计链长
//             while (down[cur])
//             {
//                 cur = down[cur];
//                 cnt++;
//                 vis[cur] = true;
//             }

//             // cur 是底部牌
//             ans[cur] = cnt;
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             cout<<ans[i]<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }