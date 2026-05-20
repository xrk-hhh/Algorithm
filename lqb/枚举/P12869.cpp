// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int gcd(int a, int b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         ll ans = 0;
//         // 枚举 满足 (a + b) % 2025 == 0 的 sum
//         for (int sum = 2025; sum <= 2e6; sum += 2025)
//         {
//             for (int a = 1; a <= 1e6; a++)
//             {
//                 int b = sum - a;
//                 // 大概 45s
//                 if (__gcd(a, b) == 1 && b > a && b <= 1e6)
//                 {
//                     ans++;
//                 }
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }