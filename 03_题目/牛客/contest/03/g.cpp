// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n, m;
//         cin>>n>>m;

//         vector<int> a(n);
//         vector<int> b(m);

//         ll sum1 = 0, sum2 = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             sum1 += a[i];
//         }

//         for (int i  = 0; i < m; i++)
//         {
//             cin>>b[i];
//             sum2 += b[i];
//         }

//         if (sum1 == sum2)
//         {
//             cout<<1<<endl;
//             continue;
//         }

//         sort(a.begin(), a.end());
//         sort(b.begin(), b.end());

//         if (sum1 > sum2)
//         {
//             ll dif = sum1 - sum2;
//             int cnt = 0;
//             for (int i = n - 1; dif > 0; i--)
//             {
//                 dif -= a[i];
//                 cnt++;
//             }
//             cout<<cnt<<endl;
//         }
//         else
//         {
//             ll dif = sum2 - sum1;
//             int cnt = 0;
//             for (int i = m - 1; dif > 0; i--)
//             {
//                 dif -= b[i];
//                 cnt++;
//             }
//             cout<<cnt<<endl;
//         }
//     }

//     return 0;
// }