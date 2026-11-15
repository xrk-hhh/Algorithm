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

//         vector<ll> a(n), b(n), d(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//             d[i] = b[i] - a[i];
//         }
//         ll cnt0 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (d[i] == 0)
//             {
//                 cnt0++;
//             }
//         }

//         unordered_map<ll, ll> val;
//         priority_queue<pair<ll, ll>> pq;
//         ll dd = 0, best = 0; 
//         for (int i = 0; i < n; i++)
//         {
//             if (d[i] == 0)
//             {
//                 dd++;
//             }
//             else
//             {
//                 ll v = d[i];
//                 ll cur = val.count(v) ? val[v] : dd;

//                 if (cur - dd < 0)
//                 {
//                     cur = dd;
//                 }
//                 cur++;
//                 val[v] = cur;
//                 pq.push({cur - dd, v});
//             }

//             while (!pq.empty())
//             {
//                 auto [score, v] = pq.top();
//                 if (val.count(v) && val[v] - dd == score)
//                 {
//                     break;
//                 }
//                 pq.pop();
//             }

//             if (!pq.empty())
//             {
//                 best = max(best, pq.top().first);
//             }
//         }

//         cout<<cnt0 + best<<endl;
//     }

//     return 0;
// }