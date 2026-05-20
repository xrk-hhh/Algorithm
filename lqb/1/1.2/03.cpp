// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         ll S;
//         cin>>n>>S;

//         map<int, ll> mp;
//         int maxc = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int p, c;
//             cin>>p>>c;
//             mp[c] += p;
//             maxc = max(maxc, c);
//         }

//         for (int i = maxc; i >= 1; i--)
//         {
//             mp[i] += mp[i + 1];
//         }

//         ll ans = 0;
//         for (int i = 1; i <= maxc; i++)
//         {
//             ans += min(mp[i], S);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }