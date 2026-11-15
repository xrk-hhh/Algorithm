// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, m;
// vector<int> a;

// bool check(int x)
// {
//     ll res = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (a[i] > x)
//         {
//             res += a[i] - x;
//             if (res >= m)
//             {
//                 return true;
//             }
//         }
//     }

//     return res >= m;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {   
//         cin>>n>>m;
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
//             // 能得到至少 m
//             if (check(mid))
//             {
//                 // 切割高度上调看看行不行
//                 l = mid;
//             }
//             // 不能得到 m
//             else
//             {
//                 // 下调切割高度
//                 r = mid - 1;
//             }
//         }

//         cout<<r<<endl;
//     }

//     return 0;
// }