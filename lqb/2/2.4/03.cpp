// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// vector<int> t, d, l;
// vector<bool> vis;
// bool check;

// void dfs(int cur, int cnt)
// {
//     if (cnt == n)
//     {
//         check = true;
//         return;
//     }

//     for (int i = 0;  i < n; i++)
//     {
//         if (!vis[i])
//         {
//             int start = max(cur, t[i]);
//             if (start <= t[i] + d[i])
//             {
//                 vis[i] = true;
//                 dfs(start + l[i], cnt + 1);
//                 if (check)
//                 {
//                     return;
//                 }
//                 vis[i] = false;
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
        
//         cin>>n;

//         t.resize(n);
//         d.resize(n);
//         l.resize(n);
//         vis.resize(n);

//         for (int i = 0; i < n; i++)
//         {
//             cin>>t[i]>>d[i]>>l[i];
//         }

//         check = false;
//         vis.assign(n, false);

//         dfs(0, 0);

//         if (check)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }

//     return 0;
// }