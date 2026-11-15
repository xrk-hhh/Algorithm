// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 20;

// // 记忆化
// vector<vector<vector<ll>>> w;

// ll dfs(ll a, ll b, ll c)
// {
//     if (a <= 0 || b <= 0 || c <= 0)
//     {
//         return 1;
//     }

//     if (a > 20 || b > 20 || c > 20)
//     {
//         return dfs(20, 20, 20);
//     }

//     // 非初始值
//     if (w[a][b][c] != -1)
//     {
//         return w[a][b][c];
//     }

//     if (a < b && b < c)
//     {
//         w[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
//         return w[a][b][c];
//     }

//     w[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
//     return w[a][b][c];
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         ll a, b, c;
//         // 初始化
//         w.assign(MAXN + 1, vector<vector<ll>>(MAXN + 1, vector<ll>(MAXN + 1, -1)));
//         while (cin>>a>>b>>c && !(a == -1 && b == -1 && c == -1))
//         {
//             ll ans = dfs(a, b, c);
//             cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<endl;
//         }
//     }

//     return 0;
// }