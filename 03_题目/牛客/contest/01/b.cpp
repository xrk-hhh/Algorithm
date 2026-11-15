// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int mod = 998244353;
// const int MAXN = 2e5 + 10;

// ll f[MAXN];

// void pre(int n, int p)
// {
//     f[0] = 1;
//     for (int i = 1; i < n; i++)
//     {
//         f[i] = f[i - 1] * i % p;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     pre(MAXN, mod);

//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         int cnt = 0;
//         int minn = 4e5;

//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;
//             if (x < minn)
//             {
//                 minn = x;
//             }
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (a[i] > minn)
//             {
//                 cnt++;
//             }
//         }

//         ll ans = f[cnt] * f[n - cnt] % mod;

//         cout<<ans % mod<<endl;
//     }

//     return 0;
// }