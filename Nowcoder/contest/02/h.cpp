// // #include <bits/stdc++.h>
// // using namespace std;

// // #define ll long long
// // #define endl '\n'

// // const int mod = 1e9 + 7;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);


// //     int T;
// //     cin>>T;

// //     while (T--)
// //     {
// //         int n;
// //         cin>>n;

// //         vector<int> a(n);
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin>>a[i];
// //         }

// //         unordered_map<ll, ll> mp;

// //         ll t = 0;

// //         for (int i = 0; i < n; i++)
// //         {
// //             ll num = a[i];
// //             ll pos = i + 1;

// //             ll cnt = pos - mp[num];

// //             ll len = n - pos + 1;
// //             ll sum = len * (len + 1) / 2;

// //             t += cnt * sum;

// //             mp[num] = pos;
// //         }

// //         cout<<t<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'

// const int mod = 1e9 + 7;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         unordered_map<int, int> last_pos;
        
//         ll ans = 0;
//         ll S = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin>>x;

//             int prev;

//             if (last_pos.count(x))
//             {
//                 prev = last_pos[x];
//             }
//             else
//             {
//                 prev = -1;
//             }

//             S += (i - prev);

//             ans += S * (n - i);

//             last_pos[x] = i;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }