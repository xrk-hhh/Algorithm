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

//         vector<int> cnt(26, 0);
//         for (int i = 0; i < s.size(); i++)
//         {
//             cnt[s[i] - 'a']++;
//         }

//         int ans = 0;
//         for (int i = 0; i < 26; i++)
//         {
//             if (cnt[i] == 1)
//             {
//                 ans++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }