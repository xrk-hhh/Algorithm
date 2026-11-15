// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n, sum;
// // 第 i 个数前的系数 C(n-1，i)
// vector<int> coeff;
// vector<int> ans;
// // 数字是否被使用
// vector<bool> used;

// // 计算剩余部分可能的最小和与最大和
// pair<int, int> bound(int pos, int cur)
// {
//     vector<int> rest_coeff(coeff.begin() + pos, coeff.end());
//     vector<int> rest_num;

//     for (int i = 1; i <= n; i++)
//     {
//         if (!used[i])
//         {
//             rest_num.push_back(i);
//         }
//     }

//     sort(rest_coeff.begin(), rest_coeff.end());
//     sort(rest_num.begin(), rest_num.end());

//     int minn = 0, maxx = 0;
//     int m = rest_coeff.size();
//     for (int i = 0; i < m; i++)
//     {
//         // 小系数乘大数字 → 最小和
//         minn += rest_coeff[i] * rest_num[m - 1 - i];
//         // 小系数乘小数字 → 最大和
//         maxx += rest_coeff[i] * rest_num[i];
//     }

//     return {cur + minn, cur + maxx};
// }

// bool dfs(int pos, int cur)
// {
//     if (pos == n)
//     {
//         return cur == sum;
//     }

//     auto [low, high] = bound(pos, cur);
//     // 剪枝
//     // 即：下界 > 目标 或 上界 < 目标
//     // 若剩余部分最小和加上当前和 > 目标
//     // 若剩余部分最大和加上当前和 < 目标
//     // 肯定不行
//     if (low > sum || high < sum)
//     {
//         return false;
//     }

//     // 按字典序尝试数字
//     for (int i = 1; i <= n; i++)
//     {
//         if (!used[i])
//         {
//             used[i] = true;
//             ans.push_back(i);

//             if (dfs(pos + 1, cur + coeff[pos] * i))
//             {
//                 return true;
//             }

//             ans.pop_back();
//             used[i] = false;
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
//         cin>>n>>sum;

//         coeff.resize(n);
//         // 计算组合数
//         vector<vector<int>> C(n, vector<int>(n, 0));
//         for (int i = 0; i < n; i++)
//         {
//             C[i][0] = C[i][i] = 1;
//             for (int j = 1; j < i; j++)
//             {
//                 // C(n, m) = C(n - 1, m - 1) + C(n - 1, m)
//                 C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
//             }
//         }

//         // 第 i 个数前的系数 C(n-1，i)
//         for (int i = 0; i < n; i++)
//         {
//             coeff[i] = C[n - 1][i];
//         }

//         used.assign(n + 1, false);

//         if (dfs(0, 0))
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 cout<<ans[i]<<' ';
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }