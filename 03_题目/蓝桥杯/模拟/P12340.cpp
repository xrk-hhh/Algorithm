// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const string s = "LANQIAO";
// const int mod = 7;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int h, w;
//         cin>>h>>w;

//         int ans = 0;
//         for (int i = 0; i < h; i++)
//         {
//             int cnt = i % mod;
//             for (int j = 0; j < w; j++)
//             {
//                 if (s[cnt % mod] == 'A')
//                 {
//                     ans++;
//                 }
//                 cnt++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }