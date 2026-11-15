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

//         ll cur = a[0], ans = a[0];
//         for (int i = 1; i < n; i++)
//         {
//             cur = max(1LL * a[i], cur + a[i]);
//             ans = max(ans, cur);
//         }
        
//         cout<<ans<<endl;
//     }

//     return 0;
// }