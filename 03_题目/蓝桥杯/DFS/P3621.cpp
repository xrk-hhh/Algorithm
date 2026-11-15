// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n, k;
// vector<int> ans;

// void dfs(int pos)
// {
//     if (pos == n + 1)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             cout<<ans[i]<<' ';
//         }
//         cout<<endl;
//         return;
//     }
//     for (int i = 1; i <= k; i++)
//     {
//         ans.push_back(i);
//         dfs(pos + 1);
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
//         cin>>n>>k;
//         dfs(1);
//     }

//     return 0;
// }