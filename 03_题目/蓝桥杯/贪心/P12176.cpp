// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int MAXN = 1e6 + 10;

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

//         // 置换环问题

//         vector<int> a(n + 1), b(MAXN);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//             b[a[i]] = i;
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             // 如果该书不在对应位置上，则与对应位置上的进行交换
//             if (a[i] != i)
//             {
//                 b[a[i]] = b[i];
//                 swap(a[b[i]], a[i]);
//                 ans++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }