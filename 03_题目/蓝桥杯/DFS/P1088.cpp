// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// // 排列问题

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

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         while (m--)
//         {
//             next_permutation(a.begin(), a.end());
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (i != 0)
//             {
//                 cout<<' ';
//             }
//             cout<<a[i];
//         }
//     }

//     return 0;
// }