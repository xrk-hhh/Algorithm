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
//         int n;
//         cin>>n;

//         // 要求满足 i < j，a[i] + a[j] > b[i] + b[j]
//         // 即，a[i] - b[i] + a[j] - b[j] > 0
//         vector<int> c(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>c[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             int b;
//             cin>>b;

//             c[i] -= b;
//         }

//         // 升序
//         sort(c.begin(), c.end());

//         ll ans = 0;
//         // 双指针
//         int l = 0, r = n - 1;
//         while (l < r)
//         {
//             if (c[l] + c[r] > 0)
//             {
//                 // 贡献(l, r]
//                 ans += r - l;
//                 r--;
//             }
//             else
//             {
//                 l++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }