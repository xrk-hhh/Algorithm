// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define i128 __int128_t

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int m, n;
//         ll z;
//         cin>>m>>n>>z;

//         ll s = m + n;
//         int flag = 0;
        
//         ll cnt = (z + s - 1) / s;

//         i128 tmp = (i128)((cnt - 1) * s);

//         if (tmp + m >= z)
//         {
//             flag = 0;
//         }
//         else
//         {
//             flag = 1;
//         }

//         cout<<flag;
//     }

//     return 0;
// }