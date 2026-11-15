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
//         string s;
//         cin>>s;

//         map<char, int> cnt;
//         char maxx = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             cnt[s[i]]++;
//             maxx = max(maxx, s[i]);
//         }

//         cout<<string(cnt[maxx], maxx)<<endl;
//     }

//     return 0;
// }