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

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
            
//         }

//         ll sum = 0;
//         for (int b = 0; b < 31; b++)
//         {
//             int cnt1 = 0;
//             for (int i = 0; i < n; i++)
//             {
//                 if ((a[i] >> b) & 1)
//                 {
//                     cnt1++;
//                 }
//             }
//             int cnt0 = n - cnt1;
//             if ((1LL * cnt0 * cnt1) & 1)
//             {
//                 sum |= (1 << b);
//             }
//         }

//         cout<<sum<<endl;
//     }

//     return 0;
// }