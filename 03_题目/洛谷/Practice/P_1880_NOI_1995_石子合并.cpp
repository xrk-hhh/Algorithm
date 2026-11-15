// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int INF = 0x3f3f3f3f;

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

//         // 环形转直线
//         vector<int> a(2 * n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             a[i + n] = a[i];
//         }

//         vector<int> sum(2 * n + 1, 0);
//         for (int i = 1; i <= 2 * n; i++)
//         {
//             sum[i] = sum[i - 1] + a[i];
//         }

//         // 最小分数
//         vector<vector<int>> dp0(2 * n + 1, vector<int>(2 * n + 1, 0));
//         // 最大分数
//         vector<vector<int>> dp1(2 * n + 1, vector<int>(2 * n + 1, 0));
//         // 枚举区间长度
//         for (int len = 2; len <= 2 * n; len++)
//         {
//             for (int i = 1; i + len - 1 <= 2 * n; i++)
//             {
//                 int j = i + len - 1;
//                 dp0[i][j] = INF;

//                 int tot = sum[j] - sum[i - 1];
//                 // 枚举最后一次合并分界点
//                 for (int k = i; k < j; k++)
//                 {
//                     dp0[i][j] = min(dp0[i][j], dp0[i][k] + dp0[k + 1][j] + tot);
//                     dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + tot);
//                 }
//             }
//         }

//         int minn = INF, maxx = 0;
//         // 遍历所有起点
//         for (int i = 1; i <= n; i++)
//         {
//             minn = min(minn, dp0[i][i + n - 1]);
//             maxx = max(maxx, dp1[i][i + n - 1]);
//         }

//         cout<<minn<<endl<<maxx<<endl;
//     }

//     return 0;
// }