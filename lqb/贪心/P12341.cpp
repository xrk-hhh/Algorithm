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

//         int l = 0, r = s.size() - 1;
//         int del = 0;
//         while (l < r)
//         {
//             // while (s[l] != 'A' && l < r)
//             // {
//             //     l++;
//             // }
//             // while (s[r] != 'B' && l < r)
//             // {
//             //     r--;
//             // }
//             // if (l >= r)
//             // {
//             //     break;
//             // }
//             // l++;
//             // r--;
//             // del += 2;

//             if (s[l] == 'A' && s[r] == 'B')
//             {
//                 l++;
//                 r--;
//                 del += 2;
//             }
//             else if (s[l] == 'A' && s[r] != 'B')
//             {
//                 r--;
//             }
//             else if (s[l] != 'A' && s[r] == 'B')
//             {
//                 l++;
//             }
//             else
//             {
//                 l++;
//                 r--;
//             }
//         }

//         cout<<s.size() - del<<endl;
//     }

//     return 0;
// }