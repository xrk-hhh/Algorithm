// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, k;
// vector<int> a;

// bool check(int x)
// {
//     ll res = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (a[i] < x)
//         {
//             break;
//         }
//         else
//         {
//             res += a[i] / x;
//         }
//         if (res >= k)
//         {
//             return true;
//         }
//     }

//     return res >= k;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n>>k;
//         a.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>a[i];
//         }

//         sort(a.begin(), a.end());

//         int l = 0, r = a[n - 1] + 1;
//         // 二分答案（最大值）
//         while (l < r)
//         {
//             int mid = (l + r + 1) >> 1;
//             // 能切成 k 段
//             if (check(mid))
//             {
//                 // 看看增大要切的每段长度行不行
//                 l = mid;
//             }
//             // 不行
//             else
//             {
//                 // 减小切割长度
//                 r = mid - 1;
//             }
//         }

//         cout<<r<<endl;
//     }

//     return 0;
// }