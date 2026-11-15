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
//         string s;
//         cin>>s;

//         int a = (s[0] - '0') * 10 + s[1] - '0';
//         int b = (s[2] - '0') * 10 + s[3] - '0';

//         if (a == 0 || a > 12)
//         {
//             if (b >= 1 && b <= 12)
//             {
//                 cout<<"YYMM"<<endl;
//             }
//             else
//             {
//                 cout<<"NA"<<endl;
//             }
//         }
//         else if (a >= 1 && a <= 12)
//         {
//             if (b >= 1 && b <= 12)
//             {
//                 cout<<"AMBIGUOUS"<<endl;
//             }
//             else
//             {
//                 cout<<"MMYY"<<endl;
//             }
//         }
//     }

//     return 0;
// }