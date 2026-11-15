// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

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

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         while (m--)
//         {
//             int q;
//             cin>>q;

//             int l = 0, r = n + 1;
//             while (l + 1 < r)
//             {
//                 int mid = (l + r) >> 1;

//                 if (a[mid] >= q)
//                 {
//                     r = mid;
//                 }
//                 else
//                 {
//                     l = mid;
//                 }
//             }

//             if (a[r] == q)
//             {
//                 cout<<r<<' ';
//             }
//             else
//             {
//                 cout<<-1<<' ';
//             }
//         }
//     }

//     return 0;
// }