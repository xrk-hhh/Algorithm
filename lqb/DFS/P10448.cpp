// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n, m;
// vector<int> ans;

// // 组合型枚举

// void dfs(int pos)
// {
//     // 已选数量达到 m，输出答案
//     if (ans.size() == m)
//     {
//         for (int i = 0; i < m; i++)
//         {
//             cout<<ans[i]<<' ';
//         }
//         cout<<endl;
//         return;
//     }

//     // 每次递归选择下一位
//     for (int i = pos; i <= n; i++)
//     {
//         ans.push_back(i);
//         dfs(i + 1);
//         ans.pop_back();
//     }
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
//         dfs(1);
//     }

//     return 0;
// }