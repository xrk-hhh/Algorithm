// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define MAXN 200010
// #define ll long long
// #define INF 0x3f3f3f3f3f3f3f3fLL

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
        
//     }

//     return 0;
// }

// const int mod = 1e9 + 7;

// ll gcd(ll a, ll b)
// {
//     while (b)
//     {
//         ll tmp = b;
//         b = a % b;
//         a = tmp;
//     }
//     return a;
// }

// ll lcm(ll a, ll b)
// {
//     return a / gcd(a, b) * b;
// }

// bool is_prime(ll n)
// {
//     if (n == 1)
//     {
//         return false;
//     }
//     if (n == 2)
//     {
//         return true;
//     }
//     if (!(n & 1))
//     {
//         return false;
//     }
//     ll x = sqrt(n);
//     for (ll i = 3; i <= x; i += 2)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }


// // 整数二分（查找第一个 >= target 的位置）
// int lower_bound(int arr[], int n, int target) 
// {
//     int l = 0, r = n - 1;
//     while (l <= r) 
//     {
//         int mid = l + (r - l) / 2; // 避免溢出
//         if (arr[mid] >= target) 
//         {
//             r = mid - 1;
//         } 
//         else 
//         {
//             l = mid + 1;
//         }
//     }
//     return l; // 若返回n则表示无满足条件的数
// }

// // 浮点数二分（精度控制）
// double binary_search_double(double l, double r, double eps, int x) 
// {
//     // 示例：查找x的平方根
//     while (r - l > eps) 
//     {
//         double mid = (l + r) / 2;
//         if (mid * mid > x) 
//         { // 根据问题调整条件
//             r = mid;
//         } 
//         else 
//         {
//             l = mid;
//         }
//     }
//     return l;
// }

// vector<ll> fact, inv_fact;

// ll ksm(ll a, ll b)
// {
//     ll res = 1 % mod;
//     a = a % mod;
//     while (b)
//     {
//         if (b & 1)
//         {
//             res = res * a % mod;
//         }
//         b >>= 1;
//         a = a * a % mod; 
//     }
//     return res;
// }

// void precompute()
// {
//     fact.resize(MAXN + 10);
//     inv_fact.resize(MAXN + 10);
//     fact[0] = 1;
//     for (int i = 1; i <= MAXN; i++)
//     {
//         fact[i] = fact[i - 1] * i % mod;
//     }

//     inv_fact[MAXN] = ksm(fact[MAXN], mod - 2);
//     for (int i = MAXN; i >= 1; i--)
//     {
//         inv_fact[i - 1] = inv_fact[i] * i % mod;
//     }
// }

// ll C(int n, int k)
// {
//     if (k < 0 || k > n)
//     {
//         return 0;
//     }

//     return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
// }