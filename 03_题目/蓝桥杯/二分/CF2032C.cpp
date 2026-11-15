// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         vector<ll> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         int ans = n - 1;
//         for (int i = 0; i < n - 1; i++)
//         {
//             // 找到第一个大于等于 a[i] + a[i + 1]的数的下标
//             int pos = lower_bound(a.begin(), a.end(), a[i] + a[i + 1]) - a.begin();

//             // 则保留 i ~ pos - 1 部分，即保留 keep = pos - 1 - i + 1 = pos - i
//             // 因此，修改的次数为 n - keep = n - pos + i
//             ans = min(ans, n - pos + i);
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }