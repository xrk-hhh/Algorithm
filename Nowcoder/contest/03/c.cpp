// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int cnt(string s, int p)
// {
//     int cnt0 = 0, cnt1 = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         char c;
//         if (i & 1)
//         {
//             if (p == 0)
//             {
//                 c = '1';
//             }
//             else
//             {
//                 c = '0';
//             }
//         }
//         else
//         {
//             if (p == 1)
//             {
//                 c = '1';
//             }
//             else
//             {
//                 c = '0';
//             }
//         }
//         if (s[i] != c)
//         {
//             if (s[i] == '0')
//             {
//                 if (cnt1 > 0)
//                 {
//                     cnt1--;
//                     cnt0++;
//                 }
//                 else
//                 {
//                     cnt0++;
//                 }
//             }
//             else
//             {
//                 if (cnt0 > 0)
//                 {
//                     cnt0--;
//                     cnt1++;
//                 }
//                 else
//                 {
//                     cnt1++;
//                 }
//             }
//         }
//     }
//     return cnt0 + cnt1;
// }

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

//         string s;
//         cin>>s;

//         int ans = min(cnt(s, 0), cnt(s, 1));

//         cout<<ans<<endl;
//     }

//     return 0;
// }