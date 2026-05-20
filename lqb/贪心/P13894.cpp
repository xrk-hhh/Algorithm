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

//         int ans = 0;
//         for (int i = 1; i < s.size(); i++)
//         {
//             if (s[i] == s[i - 1] || s[i] == '?' || s[i - 1] == '?')
//             {
//                 ans++;
//                 // 注意：互不重叠
//                 i++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }