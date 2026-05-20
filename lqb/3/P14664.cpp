// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

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

//         if (n == 0)
//         {
//             cout<<0<<endl;
//             continue;
//         }

//         int high_bit = 31 - __builtin_clz(n);
//         int high = 1 << high_bit;
//         int r = n - high;

//         int c = 0;
//         for (int i = high_bit; i >= 0; i--)
//         {
//             if (!((n >> i) & 1))
//             {
//                 int cand = c + (1 << i);
//                 if (cand <= r)
//                 {
//                     c = cand;
//                 }
//             }
//         }
//         cout<<n + 1LL * 2 * c<<endl;
//     }

//     return 0;
// }