// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// vector<int> cur;
// vector<vector<int>> ans;

// void dfs(int idx, int sum)
// {
//     if (idx == 10)
//     {
//         if (sum == n)
//         {
//             ans.push_back(cur);
//         }
//         return;
//     }

//     for (int i = 1; i <= 3; i++)
//     {
//         cur.push_back(i);
//         dfs(idx + 1, sum + i);
//         cur.pop_back();
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
//         cin>>n;

//         if (n < 10 || n > 30)
//         {
//             cout<<0<<endl;
//         }
//         else
//         {
//             dfs(0, 0);
//             cout<<ans.size()<<endl;
//             for (int i = 0; i < ans.size(); i++)
//             {
//                 for (int j = 0; j < 10; j++)
//                 {
//                     cout<<ans[i][j]<<' ';
//                 }
//                 cout<<endl;
//             }
//         }
//     }

//     return 0;
// }