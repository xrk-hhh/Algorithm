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
//         int a, b, x, y, m;
//         cin>>a>>b>>x>>y>>m;

//         int ans = 0;
//         for (int i = 0; i <= a; i++)
//         {
//             int k = m - i * x;

//             if (k < 0)
//             {
//                 continue;
//             }
            
//             if ((k / y) <= b)
//             {
//                 int cnt = i + k / y;
//                 ans = max(ans, cnt);
//             }
//             else
//             {
//                 ans = max(ans, i + b);
//             }
            
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }