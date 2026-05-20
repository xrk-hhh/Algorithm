// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long
// #define i128 __int128_t

// i128 gcd(i128 a, i128 b, i128& x, i128& y)
// {
//     if (b == 0)
//     {
//         x = 1;
//         y = 0;
//         return a;
//     }

//     i128 d = gcd(b, a % b, y, x);
//     y -= a / b * x;
//     return d;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         ll x, a, s;
//         cin>>x>>a>>s;

//         i128 xx = x, aa = a, ss = s;
//         i128 u, v;
        
//         i128 d = gcd(aa, ss, u, v);

//         if (xx % d != 0)
//         {
//             cout<<"No"<<endl;
//             continue;
//         }

//         i128 ap = aa / d;
//         i128 sp = ss / d;
//         i128 xp = xx / d;

//         u = (u % sp + sp) % sp;
//         v = (d - aa * u) / ss;

//         i128 c10 = u * xp;
//         i128 c20 = v * xp;

//         i128 A = sp;
//         i128 B = ap;

//         i128 l, r;
//         l = (-c20 + B - 1) / B;
//         r = c10 / A;

//         if (l > r)
//         {
//             cout<<"No"<<endl;
//             continue;
//         }

//         i128 best_k = l;
//         i128 best_val = LLONG_MAX;

//         vector<i128> cand_k = {l, r};
//         i128 k0 = (c10 - c20) / (A + B);
//         for (int dt = -2; dt <= 2; dt++)
//         {
//             i128 k = k0 + dt;
//             if (k >= l && k <= r)
//             {
//                 cand_k.push_back(k);
//             }
//         }

//         for (i128 k : cand_k)
//         {
//             i128 c1 = c10 - A * k;
//             i128 c2 = c20 + B * k;
//             if (c1 < 0 || c2 < 0)
//             {
//                 continue;
//             }
//             if (aa * c1 + ss * c2 != xx)
//             {
//                 continue;
//             } 
//             i128 cur_val = max(c1, c2);
//             if (cur_val < best_val)
//             {
//                 best_val = cur_val;
//                 best_k = k;
//             }
//         }

//         i128 c1 = c10 - A * best_k;
//         i128 c2 = c20 + B * best_k;
//         if (c1 <0 || c2 < 0)
//         {
//             cout<<"No"<<endl;
//             continue;
//         }

//         cout<<"Yes"<<endl;
//         cout<<(ll)c1<<' '<<(ll)c2<<endl;
//     }

//     return 0;
// }