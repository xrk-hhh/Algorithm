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

//         map<int, int> mp;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;
//             mp[x]++;
//         }

//         vector<ll> a;
//         for (auto it : mp)
//         {
//             ll t = 1LL * it.first * it.second;
//             a.push_back(t);
//         }

//         sort(a.begin(), a.end());

//         int m = a.size();
//         int idx = m - 1;
//         while (k--)
//         {
//             a[idx] = 0;
//             idx--;
//             if (idx < 0)
//             {
//                 break;
//             }
//         }

//         ll ans = 0;
//         for (int i = 0; i < m; i++)
//         {
//             ans += a[i];
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }