// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         string s;
//         cin>>s;

//         vector<int> pre(n + 2, 0), suf(n + 2, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             pre[i] = pre[i - 1] + (s[i - 1] == 'L');
//         }
//         for (int i = n; i >= 1; i--)
//         {
//             suf[i] = suf[i + 1] + (s[i - 1] == 'Q');
//         }

//         ll base = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i - 1] == 'Q')
//             {
//                 base += pre[i - 1];
//             }
//         }

//         vector<int> pos;
//         for (int i = 1; i <= n; i++)
//         {
//             if (s[i - 1] == '?')
//             {
//                 pos.push_back(i);
//             }
//         }

//         int m = pos.size();
//         vector<ll> l(m), r(m);
//         for (int i = 0; i < m; i++)
//         {
//             int p = pos[i];
//             l[i] = pre[p - 1];
//             r[i] = suf[p + 1];
//         }

//         vector<ll> pr(m + 1, 0);
//         for (int i = 1; i <= m; i++)
//         {
//             pr[i] = pr[i - 1] + r[i - 1];
//         }
//         vector<ll> sl(m + 2, 0);
//         for (int i = m; i >= 1; i--)
//         {
//             sl[i] = sl[i + 1] + l[i - 1];
//         }

//         ll ans = base;
//         for (int k = 0; k <= m; k++)
//         {
//             ll cur = base + pr[k] + sl[k + 1] + 1LL * k * (m - k);

//             ans = max(ans, cur);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }