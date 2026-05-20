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
//         int n;
//         cin>>n;

//         while (n--)
//         {
//             string s;
//             cin>>s;

//             string ans;
//             ans += s[0] - 'a' + 'A';

//             for (int i = 0; i < s.size(); i++)
//             {
//                 if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )&& i + 1 < s.size())
//                 {
//                     ans += s[i + 1] - 'a' + 'A';
//                 }
//             }

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }