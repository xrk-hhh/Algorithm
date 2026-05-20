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
//         int cnt14 = 0, cnt15 = 0, cnt16 = 0;
//         int cnt24 = 0, cnt25 = 0, cnt26 = 0;
//         int cnt34 = 0, cnt35 = 0, cnt36 = 0;
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 6; j++)
//             {
//                 int a;
//                 cin>>a;

//                 if (i == 0)
//                 {
//                     if (a == 4)
//                     {
//                         cnt14++;
//                     }
//                     else if (a == 5)
//                     {
//                         cnt15++;
//                     }
//                     else if (a == 6)
//                     {
//                         cnt16++;
//                     }
//                 }
//                 else if (i == 1)
//                 {
//                     if (a == 4)
//                     {
//                         cnt24++;
//                     }
//                     else if (a == 5)
//                     {
//                         cnt25++;
//                     }
//                     else if (a == 6)
//                     {
//                         cnt26++;
//                     }
//                 }
//                 else
//                 {
//                     if (a == 4)
//                     {
//                         cnt34++;
//                     }
//                     else if (a == 5)
//                     {
//                         cnt35++;
//                     }
//                     else if (a == 6)
//                     {
//                         cnt36++;
//                     }
//                 }
//             }
//         }

//         double ans = 1.0 * (cnt14 * cnt25 * cnt36 + cnt14 * cnt26 * cnt35 + cnt15 * cnt24 * cnt36 + cnt15 * cnt26 * cnt34 + cnt16 * cnt25 * cnt34 + cnt16 * cnt24 * cnt35) / 216;

//         cout<<fixed<<setprecision(10)<<ans<<endl;
//     }

//     return 0;
// }