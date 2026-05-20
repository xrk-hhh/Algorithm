// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 998244353;
// const int N = 5e3 + 10;

// int a[N], f[N] = {1};

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         sort(a, a + n);

//         ll ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j <= a[i]; j++)
//             {
//                 ans = (ans + 1LL * f[j] * a[i] % mod) % mod;
//             }
//             for (int j = a[i] + 1; j <= N; j++)
//             {
//                 ans = (ans + 1LL * f[j] * (((j + a[i] + 1)) / 2) % mod) % mod;
//             }

//             for (int j = N; j >= a[i]; j--)
//             {
//                 f[j] = (f[j] + f[j - a[i]]) % mod;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }