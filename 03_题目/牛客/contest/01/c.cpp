// // #include <bits/stdc++.h>
// // using namespace std;

// // #define ll long long

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
// //     cout.tie(nullptr);

// //     int T;
// //     cin>>T;

// //     while (T--)
// //     {
// //         int n;
// //         cin>>n;

// //         vector<ll> a(n);
        
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin>>a[i];
// //         }

// //         if (n == 1 || n == 2)
// //         {
// //             ll sum0 = 0;
// //             for (int i = 0; i < n; i++)
// //             {
// //                 sum0 += a[i];
// //             }
// //             cout<<sum0<<'\n';
// //             continue;
// //         }

// //         vector<ll> pre(n), suf(n);
// //         pre[0] = a[0];
// //         for (int i = 1; i < n; i++)
// //         {
// //             pre[i] = max(pre[i - 1], a[i]);
// //         }

// //         suf[n - 1] = a[n - 1];
// //         for (int i = n - 2; i >= 0; i--)
// //         {
// //             suf[i] = max(suf[i + 1], a[i]);
// //         }

// //         ll sum1 = a[0] + a[n - 1];
// //         for (int i = 1; i < n - 1; i++)
// //         {
// //             ll tmp = max(pre[i - 1], suf[i + 1]);
// //             sum1 += max(tmp, a[i]);
// //         }

// //         cout<<sum1<<'\n';
// //     }

// //     return 0;
// // }


// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<int> a(n);
//         ll maxx = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             if (a[i] > maxx)
//             {
//                 maxx = a[i];
//             }
//         }
//         ll sum = maxx * (n - 2) + a[0] + a[n - 1];

//         cout<<sum<<endl;
//     }

//     return 0;
// }