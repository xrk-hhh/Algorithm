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
//         int x1, y1, x2, y2;
//         cin>>x1>>y1>>x2>>y2;

//         ll tmp1 = y1 - y2;
//         ll tmp2 = 1LL * x1 * y2 - 1LL * x2 * y1;

//         if (tmp1 != 0)
//         {
//             double x = (4.0 - tmp2) / tmp1;

//             cout<<fixed<<setprecision(10)<<x<<endl; 
//         }
//         else
//         {
//             if (abs(tmp2) == 4)
//             {
//                 cout<<fixed<<setprecision(10)<<0.0<<endl;
//             }
//             else
//             {
//                 cout<<"no answer"<<endl;
//             }
//         }
//     }

//     return 0;
// }