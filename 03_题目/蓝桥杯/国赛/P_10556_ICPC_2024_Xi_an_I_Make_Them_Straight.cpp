// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXV = 1e6 + 10;

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

//         vector<int> a(n + 1), b(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }
//         ll sum = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>b[i];
//             sum += b[i];
//         }

//         // 最大的所有保留的 b值
//         ll maxx = 0;
//         // 修改过的桶下标
//         vector<int> modified;
//         // ai对应的所有 b值
//         vector<ll> cnt(MAXV, 0);
//         // 枚举斜率
//         // k = 0
//         for (int i = 1; i <= n; i++)
//         {
//             cnt[a[i]] += b[i];
//             modified.push_back(a[i]);
//         }
//         for (int v : modified)
//         {
//             maxx = max(maxx, cnt[v]);
//             cnt[v] = 0;
//         }
//         modified.clear();

//         // k = 1-MAXV
//         for (int k = 1; k <= MAXV; k++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 ll t = 1LL * (i - 1) * k;
//                 // 超了
//                 if (t > MAXV)
//                 {
//                     break;
//                 }

//                 // 需要的 a1值
//                 ll a1 = a[i] - t;
//                 // 不在范围内
//                 if (a1 < 0 || a1 > MAXV)
//                 {
//                     continue;
//                 }

//                 cnt[a1] += b[i];
//                 modified.push_back(a1);
//             }

//             for (int v : modified)
//             {
//                 maxx = max(maxx, cnt[v]);
//                 cnt[v] = 0;
//             }
//             modified.clear();
//         }

//         // 需要修改的 b值之和 = 所有 b值之和 - 不需要修改的 b值之和
//         cout<<sum - maxx<<endl;
//     }

//     return 0;
// }