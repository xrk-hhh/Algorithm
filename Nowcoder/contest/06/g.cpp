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
//         int n, m, l;
//         cin>>n>>m>>l;

//         vector<int> x(n), y(m);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>x[i];
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin>>y[i];
//         }

//         vector<ll> pre(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             pre[i] = pre[i - 1] + x[i - 1];
//         }

//         auto check = [&](ll pos) -> bool
//         {
//             auto it = upper_bound(pre.begin() + 1, pre.end(), pos);

//             return ((it != pre.end()) && (*it < pos + l));
//         };

//         ll pos = 0;
//         if (check(pos))
//         {
//             cout<<"YES"<<endl;
//             return 0;
//         }

//         for (int i = 0; i < m; i++)
//         {
//             pos += y[i];
//             if (check(pos))
//             {
//                 cout<<"YES"<<endl;
//                 return 0;
//             }
//         }
        
//         cout<<"NO"<<endl;
//     }

//     return 0;
// }