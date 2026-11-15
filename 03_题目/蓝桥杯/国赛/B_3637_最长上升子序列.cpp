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

//         vector<int> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         // b[i] = 长度为 i+1 的 LIS 的最小末尾
//         vector<int> b;
//         for (auto& x : a)
//         {
//             // 找第一个 >= x 的位置（严格递增，所以不能有相等）
//             auto it = lower_bound(b.begin(), b.end(), x);
//             if (it == b.end())
//             {
//                 // 比所有末尾都大，扩展长度
//                 b.push_back(x);
//             }
//             else
//             {
//                 // 替换成更小的值，使末尾更小
//                 *it = x;
//             }
//         }

//         cout<<b.size()<<endl;
//     }

//     return 0;
// }