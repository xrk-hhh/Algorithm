// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// const int MOD = 998244353;
// const int N = 7;

// int S[10];

// ll ksm(ll a, ll b) 
// {
//     ll res = 1;
//     a %= MOD;
//     while (b) 
//     {
//         if (b & 1) res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }

// void init() 
// {
//     S[0] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 4) | (1 << 5) | (1 << 6);
//     S[1] = (1 << 2) | (1 << 5);
//     S[2] = (1 << 0) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 6);
//     S[3] = (1 << 0) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
//     S[4] = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5);
//     S[5] = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 5) | (1 << 6);
//     S[6] = (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
//     S[7] = (1 << 0) | (1 << 2) | (1 << 5);
//     S[8] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
//     S[9] = (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 6);
// }

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     init();

//     ll inv100 = ksm(100, MOD - 2);

//     int T;
//     cin >> T;
//     while (T--) 
//     {
//         int C;
//         cin >> C;
//         vector<int> p(N);
//         for (int i = 0; i < N; i++) 
//         {
//             cin >> p[i];
//             p[i] = (ll)p[i] * inv100 % MOD;
//         }

//         vector<int> digit(10, 1);
//         for (int i = 0; i < 10; i++) 
//         {
//             for (int j = 0; j < N; j++) 
//             {
//                 if (S[i] >> j & 1) 
//                 {
//                     digit[i] = (ll)digit[i] * p[j] % MOD;
//                 } 
//                 else 
//                 {
//                     digit[i] = (ll)digit[i] * (1 + MOD - p[j]) % MOD;
//                 }
//             }
//         }

//         auto calc = [&](int x) -> int 
//         {
//             if (x == 0) 
//             {
//                 return (ll)digit[0] * digit[0] % MOD * digit[0] % MOD * digit[0] % MOD;
//             }
//             int ans = 1;
//             int len = 0;
//             int tmp = x;
//             while (tmp) 
//             {
//                 ans = (ll)ans * digit[tmp % 10] % MOD;
//                 tmp /= 10;
//                 len++;
//             }
//             for (int i = 0; i < 4 - len; i++) 
//             {
//                 ans = (ll)ans * digit[0] % MOD;
//             }
//             return ans;
//         };

//         ll ans = 0;
//         for (int A = 0; A <= C; A++)
//          {
//             int B = C - A;
//             if (B < 0 || B > 9999)
//             {
//                 continue;
//             }
//             ans = (ans + (ll)calc(A) * calc(B) % MOD) % MOD;
//         }

//         cout<<ans<<'\n';
//     }

//     return 0;
// }