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
//         // string s;
//         // cin>>s;

//         // if (s.size() == 1 && s[0] == '0')
//         // {
//         //     cout<<'0'<<endl;
//         //     return 0;
//         // }

//         // if (s[0] == '-')
//         // {
//         //     cout<<'-';
//         //     bool ok = false;
//         //     for (int i = s.size() - 1; i >= 1; i--)
//         //     {
//         //         if (s[i] != '0')
//         //         {
//         //             ok = true;
//         //         }

//         //         if (ok)
//         //         {
//         //             cout<<s[i];
//         //         }
//         //     }
//         // }
//         // else
//         // {
//         //     bool ok = false;
//         //     for (int i = s.size() - 1; i >= 0; i--)
//         //     {
//         //         if (s[i] != '0')
//         //         {
//         //             ok = true;
//         //         }

//         //         if (ok)
//         //         {
//         //             cout<<s[i];
//         //         }
//         //     }
//         // }
//         // cout<<endl;

//         int n;
//         cin>>n;

//         int sign = 1;
//         if (n < 0)
//         {
//             sign = -1;
//             n = -n;
//         }
//         int rev = 0;
//         while (n)
//         {
//             rev = rev * 10 + n % 10;
//             n /= 10;
//         }
//         cout<<sign * rev<<endl;
//     }

//     return 0;
// }