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

//         vector<pair<int, int>> ans;
//         for (int i = 1; i <= m; i++)
//         {
//             ans.push_back({i, i + 1});
//         }

//         n -= m + 1;
//         int idx = m + 2;
//         m--;
//         while (n > 0 && m > 0)
//         {
//             int cur = min(m, n - m + 1);

//             if (cur <= 0)
//             {
//                 n = -1;
//                 break;
//             }

//             ans.push_back({m - cur + 1, idx});
//             idx++;
//             for (int i = 0; i < cur - 1; i++)
//             {
//                 ans.push_back({idx - 1, idx});
//                 idx++;
//             }

//             n -= cur;
//             m--;
//         }

//         if (n != 0 || m != 0)
//         {
//             cout<<"NO"<<endl;
//         }
//         else
//         {
//             cout<<"YES"<<endl;
//             for (auto& [u, v] : ans)
//             {
//                 cout<<u<<' '<<v<<endl;
//             }
//         }
//     }

//     return 0;
// }