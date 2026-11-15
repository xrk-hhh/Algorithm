// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin>>T;

//     while (T--)
//     {
//         int L, R;
//         cin>>L>>R;

//         auto highbit = [&](int x) -> int
//         {
//             for (int j = 32; j >= 0; j--)
//             {
//                 if (x >> j & 1)
//                 {
//                     return j;
//                 }
//             }
//             return -1;
//         };

//         int b1 = highbit(L), b2 = highbit(R);

//         if (b1 == -1)
//         {
//             cout<<R + 1<<endl;
//             continue;
//         }
//         else if (b1 == b2)
//         {
//             cout<<0<<endl;
//             continue;
//         }
//         else if (b2 > (b1 + 1))
//         {
//             cout<<R + 1<<endl;
//             continue;
//         }
//         else
//         {
//             int ans = R - (1LL << b2) + 1;
//             int l = 0;
//             for (int j = b1; j >= 0; j--)
//             {
//                 if ((L >> j & 1) == 0)
//                 {
//                     break;
//                 }
//                 else
//                 {
//                     l |= (1LL << j);
//                 }
//             }

//             if (l <= ans)
//             {
//                 ans = R + 1;
//             }

//             cout<<ans<<endl;
//         }
//     }

//     return 0;
// }