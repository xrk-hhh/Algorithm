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

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         vector<ll> sum(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             sum[i] = sum[i - 1] + a[i];
//         }

//         int m;
//         cin>>m;

//         while (m--)
//         {
//             int l, r;
//             cin>>l>>r;

//             cout<<sum[r] - sum[ l - 1]<<endl;
//         }
//     }

//     return 0;
// }