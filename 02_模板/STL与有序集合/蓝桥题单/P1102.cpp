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
//         int n, c;
//         cin>>n>>c;

//         vector<int> a(n);
//         map<int, int> mp;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             mp[a[i]]++;
//         }

//         sort(a.begin(), a.end());

//         ll ans = 0;
//         for (int i = n - 1; i >= 0; i--)
//         {
//             if (a[i] < c)
//             {
//                 break;
//             }

//             // A-B数对
//             int b = a[i] - c;
//             if (mp.count(b))
//             {
//                 ans += mp[b];
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }