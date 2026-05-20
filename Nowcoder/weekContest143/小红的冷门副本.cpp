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
//         int n, m, x;
//         cin>>n>>m>>x;

//         map<int, int> cnt;
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin>>a;

//             cnt[a]++;
//         }

//         int ans = 0;
//         for (auto& [a, t] : cnt)
//         {
//             if (t <= x)
//             {
//                 ans++;
//             }
//         }
//         ans += m - cnt.size();

//         cout<<ans<<endl;
//     }

//     return 0;
// }