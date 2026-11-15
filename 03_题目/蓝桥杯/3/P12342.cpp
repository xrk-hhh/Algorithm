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
//         // 经典 “田忌赛马”

//         int n;
//         cin>>n;

//         vector<int> a(n), b(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }
//         sort(a.begin(), a.end());
//         for (int i = 0; i < n; i++)
//         {
//             cin>>b[i];
//         }
//         sort(b.begin(), b.end());

//         int i = 0, j = 0;
//         int cnt = 0;
//         while (i < n && j < n)
//         {
//             if (b[j] < a[i])
//             {
//                 cnt++;
//                 i++;
//                 j++;
//             }
//             else
//             {
//                 i++;
//             }
//         }

//         cout<<n - cnt<<endl;
//     }

//     return 0;
// }