// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int n, k;
// string s;

// bool check(int L)
// {
//     // 操作次数
//     int cnt = 0;
//     for (int i = 0; i < n;)
//     {
//         // 遇到亮的就操作
//         if (s[i] == '1')
//         {
//             cnt++;
//             i += L;
//         }
//         // 没遇到就继续右移
//         else
//         {
//             i++;
//         }
//     }
//     // 看看操作次数是否不超过 k 次
//     return cnt <= k;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         cin>>n>>k;
//         cin>>s;

//         // 二分答案（最小值）
//         int l = 1, r = n + 1;
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