// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// const int MAXN = 2048;

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

//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }

//         vector<bool> pre(MAXN, false);
//         pre[0] = true;

//         for (int i = 0; i < n; i++)
//         {
//             vector<bool> cur(MAXN, false);
//             for (int j = 0; j < MAXN; j++)
//             {
//                 if (pre[j])
//                 {
//                     int op1 = max(0, j - a[i]);
//                     cur[op1] = true;

//                     int op2 = j ^ b[i];
//                     cur[op2] = true;
//                 }
//             }

//             pre = move(cur);
//         }

//         int ans = 0;
//         for (int i = 2047; i >= 0; i--)
//         {
//             if (pre[i])
//             {
//                 ans = i;
//                 break;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }