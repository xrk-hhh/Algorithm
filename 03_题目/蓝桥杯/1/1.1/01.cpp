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

//         sort(a.begin(), a.end());

//         ll x = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (i & 1)
//             {
//                 x -= a[i];
//             }
//             else
//             {
//                 x += a[i];
//             }
//         }

//         cout<<x<<endl;
//     }

//     return 0;
// }