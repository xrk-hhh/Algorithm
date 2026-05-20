// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, m;
// vector<int> a;

// bool check(int x)
// {
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // 需要添加的检查点个数
//         cnt += (a[i + 1] - a[i] + x - 1) / x - 1;

//         // 看看添加个数是否超过的总量
//         if (cnt > m)
//         {
//             return false;
//         }
//     }

//     return true;
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

//         // 注意到，一次爆发技能相当于一个可添加的检查点

//         m++;
//         a.resize(n + 1);
//         a[0] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             cin>>a[i];
//         }

//         int l = 1, r = a[n];
//         // 二分答案（最小值）
//         while (l < r)
//         {
//             int mid = (l + r) >> 1;
//             if (check(mid))
//             {
//                 r = mid;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         cout<<l<<endl;
//     }

//     return 0;
// }