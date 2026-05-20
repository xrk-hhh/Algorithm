// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// vector<int> ans;
// vector<bool> col, d1, d2;
// vector<vector<int>> solutions;
// int cnt = 0;

// void dfs(int row)
// {
//     if (row == n)
//     {
//         solutions.push_back(ans);
//         cnt++;
//         return;
//     }

//     for (int c = 1; c <= n; c++)
//     {
//         if (!col[c] && !d1[row + c] && !d2[row - c + n])
//         {
//             col[c] = d1[row + c] = d2[row - c + n] = true;
//             ans.push_back(c);
//             dfs(row + 1);
//             ans.pop_back();
//             col[c] = d1[row + c] = d2[row - c + n] = false;
//         }
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
//         col.resize(n + 1, false);
//         d1.resize(2 * n + 1, false);
//         d2.resize(2 * n + 1, false);
//         dfs(0);

//         for (int i = 0; i < min(3, (int)solutions.size()); i++)
//         {
//             for (int j = 0; j < solutions[i].size(); j++)
//             {
//                 cout<<solutions[i][j]<<' ';
//             }
//             cout<<endl;
//         }

//         cout<<cnt<<endl;
//     }

//     return 0;
// }