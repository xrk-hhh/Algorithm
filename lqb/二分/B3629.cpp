// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n;

// bool check(int x)
// {
//     // 能得吃多少冰棍
//     ll cnt = x + x / 3;
//     // 剩下多少冰棍
//     x = x / 3 + x % 3;
//     while (x >= 3)
//     {
//         // 继续得吃
//         cnt += x / 3;
//         x = x / 3 + x % 3;
//     }
//     // 看看得吃的冰棍数是否超过 n
//     return cnt >= n;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;

//         int l = 1, r = n + 1;
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