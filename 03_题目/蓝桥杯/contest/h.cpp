// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 998244353;

// int n, m;
// vector<ll> a, b;

// struct Node
// {
//     ll x, y, id;

//     bool operator<(const Node& n) const
//     {
//         ll nx = n.x, ny = n.y;
//         return nx * y < x * ny;
//     }
// };

// bool check(double x)
// {
//     ll C = 0;
//     for (int i = 0; i < n; i++)
//     {
//         double v = 1.0 * a[i] / b[i];
//         ll cur = (ll)ceil(x - v);
//         cur = max(0LL, cur);
//         C += cur;

//         if (C > m)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
        
//         cin>>n>>m;
//         a.resize(n);
//         b.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i]>>b[i];
//         }

//         int cnt = 100;
//         double l = 0, r = 2e14;
//         while (cnt--)
//         {
//             double mid = (l + r) / 2;
//             if (check(mid))
//             {
//                 l = mid;
//             }
//             else
//             {
//                 r = mid;
//             }
//         }

//         priority_queue<Node> pq;
//         for (int i = 0; i < n; i++)
//         {
//             double v = (double)a[i] / (double)b[i];
//             ll cur = (ll)ceil(l - v);
//             cur = max(0LL, cur);
//             a[i] += cur * b[i];
//             m -= cur;
//             pq.push({a[i], b[i], i});
//         }

//         while (m--)
//         {
//             auto [x, y, id] = pq.top();
//             pq.pop();

//             a[id] += y;
//             pq.push({a[id], y, id});
//         }

//         ll ans = 1;
//         for (int i = 0; i < n; i++)
//         {
//             a[i] %= mod;
//             ans = (ans * a[i]) % mod;
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }