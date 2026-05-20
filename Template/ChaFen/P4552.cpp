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
//         int n;
//         cin>>n;

//         vector<int> a(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         ll cnt1 = 0, cnt2 = 0;
//         for (int i = 2; i <= n; i++)
//         {
//             int b = a[i] - a[i - 1];
//             if (b > 0)
//             {
//                 cnt1 += b;
//             }
//             else if (b < 0)
//             {
//                 cnt2 += abs(b);
//             }
//         }

//         cout<<max(cnt1, cnt2)<<endl<<abs(cnt1 - cnt2) + 1<<endl;
//     }

//     return 0;
// }