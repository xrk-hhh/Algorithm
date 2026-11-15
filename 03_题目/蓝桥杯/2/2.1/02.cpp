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
//         cin>>n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<ll> lsum(n), rsum(n);
//         lsum[0] = a[0], rsum[n - 1] = a[n - 1];
//         for (int i = 1; i < n; i++)
//         {
//             lsum[i] = max(1LL * a[i], lsum[i - 1] + a[i]);
//         }
//         for (int i = n - 2; i >= 0; i--)
//         {
//             rsum[i] = max(1LL * a[i], rsum[i + 1] + a[i]);
//         }

//         for (int i = 0; i < n; i++)
//         {
//             ll ans = lsum[i] + rsum[i] - a[i];
//             cout<<ans<<' ';
//         }
//         cout<<endl;
//     }

//     return 0;
// }