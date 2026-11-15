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

//         vector<int> l(m + 1), r(m + 1);
//         // 差分
//         vector<int> d(n + 2, 0);
//         for (int i = 1; i <= m; i++)
//         {
//             cin>>l[i]>>r[i];
//             d[l[i]]++;
//             d[r[i] + 1]--;
//         }

//         // 每个位置最终被覆盖的次数
//         vector<int> C(n + 1, 0);
//         // m 次操作后数组中 0 的个数
//         int cnt0 = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             C[i] = C[i - 1] + d[i];
//             if (C[i] == 0)
//             {
//                 cnt0++;
//             }
//         }

//         // 只有 1 次操作覆盖的数量的前缀和
//         vector<int> pre1(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             pre1[i] = pre1[i - 1] + (C[i] == 1);
//         }

//         for (int i = 1; i <= m; i++)
//         {
//             // 区间[l, r]中只有 1 次覆盖的数量
//             int cnt1 = pre1[r[i]] - pre1[l[i] - 1];

//             cout<<cnt0 + cnt1<<endl;
//         }
//     }

//     return 0;
// }