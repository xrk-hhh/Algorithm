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
//         int n, m;
//         cin>>n>>m;

//         vector<int> pre(n + 1, 0);
//         for (int i = 1; i <= n; i++)
//         {
//             int x;
//             cin>>x;
//             pre[i] = pre[i - 1] ^ x;
//         }

//         while (m--)
//         {
//             int l, r;
//             cin>>l>>r;

//             cout<<(pre[r] ^ pre[l - 1])<<endl;
//         }
//     }

//     return 0;
// }