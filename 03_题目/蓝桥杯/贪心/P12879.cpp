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
//         int a, b, c;
//         cin>>a>>b>>c;

//         // a 或 c 不是第二长的，即 b 是第二长的
//         if ((a > b && b > c) || (c > b && b > a))
//         {
//             cout<<0<<endl;
//             return 0;
//         }

//         // 否则，让其中至少两个相等
//         int ans = 1e5 + 1;
//         ans = min(ans, abs(a - b));
//         ans = min(ans, abs(a - c));
//         ans = min(ans, abs(b - c));

//         cout<<ans<<endl;
//     }

//     return 0;
// }