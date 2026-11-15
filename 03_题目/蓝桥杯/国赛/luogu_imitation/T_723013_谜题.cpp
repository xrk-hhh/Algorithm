// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
        
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// const ll MOD = 223999;

// // 扩域 a + b sqrt(6) 模 MOD
// struct Num {
//     ll a, b; // a + b sqrt(6)
//     Num(ll a_ = 0, ll b_ = 0) : a((a_ % MOD + MOD) % MOD), b((b_ % MOD + MOD) % MOD) {}
//     Num operator*(const Num& o) const {
//         return Num(
//             (a * o.a + 6 * b * o.b) % MOD,
//             (a * o.b + b * o.a) % MOD
//         );
//     }
// };

// Num pow(Num base, ll exp) {
//     Num res(1, 0);
//     while (exp) {
//         if (exp & 1) res = res * base;
//         base = base * base;
//         exp >>= 1;
//     }
//     return res;
// }

// ll modinv(ll x) {
//     ll b = MOD - 2, res = 1;
//     while (b) {
//         if (b & 1) res = res * x % MOD;
//         x = x * x % MOD;
//         b >>= 1;
//     }
//     return res;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     ll N = 114514;
//     // 偶数 -> A_{N/2}
//     ll k = N / 2;  // 57257
    
//     // 初始 (1 + sqrt(6))
//     Num init(1, 1);
//     // 底数 (5 + 2 sqrt(6))
//     Num base(5, 2);
    
//     Num res = init * pow(base, k);
//     ll a = res.a;  // 这就是 x 分量
    
//     ll inv2 = modinv(2);
//     ll n = ( (a * a % MOD - 1 + MOD) % MOD ) * inv2 % MOD;
    
//     cout << n << '\n';

//     // 21225
//     return 0;
// }