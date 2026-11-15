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
//         int n, k;
//         cin>>n>>k;

//         vector<int> a(n);
//         ll sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//             sum += a[i];
//         }

//         ll ans = a[0];
//         ll cur = a[0];
//         // 求最大子段和
//         for (int i = 1; i < n; i++)
//         {
//             cur = max(cur + a[i], 1LL * a[i]);
//             ans = max(ans, cur);
//         }

//         // 总和 + 最大子段和 * (k - 1)
//         cout<<sum + ans * (k - 1)<<endl;
//     }

//     return 0;
// }