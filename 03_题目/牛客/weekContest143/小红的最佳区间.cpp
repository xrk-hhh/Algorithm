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
//         int n, k;
//         cin>>n>>k;

//         vector<pair<int, int>> p(2 * n);

//         for (int i = 0; i < n; i++)
//         {
//             int l, r;
//             cin>>l>>r;

//             p.push_back({l - k, 1});
//             p.push_back({r + 1, -1});
//         }

//         sort(p.begin(), p.end());

//         int ans = 0;
//         int cur = 0;
//         for (auto& [pos, d] : p)
//         {
//             cur += d;
//             ans = max(ans, cur);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }