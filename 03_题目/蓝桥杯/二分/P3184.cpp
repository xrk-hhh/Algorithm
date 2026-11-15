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
//         int n, q;
//         cin>>n>>q;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         while (q--)
//         {
//             int x, y;
//             cin>>x>>y;

//             // 找出第一个 大于等于 x 的位置的索引
//             int l = lower_bound(a.begin(), a.end(), x) - a.begin();
//             // 找出第一个大于 y 的位置的索引
//             int r = upper_bound(a.begin(), a.end(), y) - a.begin();

//             cout<<r - l<<endl;
//         }
//     }

//     return 0;
// }