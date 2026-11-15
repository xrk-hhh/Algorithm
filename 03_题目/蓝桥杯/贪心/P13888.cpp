// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         string t, s;
//         cin>>t>>s;

//         int n = s.size();

//         if (s == t)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         int ans = 0;
//         bool ok = true;
//         for (int i = 1; i < n - 1; i++)
//         {
//             if (s[i] != t[i])
//             {
//                 if (s[i] != s[i - 1] && s[i - 1] == s[i + 1])
//                 {
//                     s[i] = t[i];
//                     ans++;
//                 }
//                 else
//                 {
//                     ok = false;
//                     break;
//                 }
//             }
//         }

//         if (!ok)
//         {
//             cout<<-1<<endl;
//             continue;
//         }

//         if (ans == 0)
//         {
//             cout<<-1<<endl;
//         }
//         else
//         {
//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }