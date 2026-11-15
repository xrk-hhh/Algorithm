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

//         vector<int> cnt(10, 0);
//         vector<pair<int, int>> t;
//         int tar = n / 10;
//         for (int i = 0; i < n; i++)
//         {
//             int a, b;
//             cin>>a>>b;

//             t.push_back({a, b});
//             cnt[a]++;
//         }

//         // 按数字、代价排序
//         sort(t.begin(), t.end());

//         ll ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             auto [a, b] = t[i];
//             // 如果出现次数比目标多，即可改变
//             // 就选代价小的
//             if (cnt[a] > tar)
//             {
//                 ans += b;
//                 cnt[a]--;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }