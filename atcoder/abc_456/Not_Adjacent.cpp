// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 998244353;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         int n = s.size();
//         vector<int> pos(n, n);
//         int last = n;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (i + 1 < n && s[i] == s[i + 1])
//             {
//                 last = i + 1;
//             }
//             pos[i] = last;
//         }

//         ll ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             ans = (ans + pos[i] - i) % mod;
//         }

//         cout<<ans % mod<<endl;
//     }

//     return 0;
// }