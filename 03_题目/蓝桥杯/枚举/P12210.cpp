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
//         int b1, b2, b3;
//         cin>>b1>>b2>>b3;

//         int cnt1, cnt2;
//         cin>>cnt1>>cnt2;

//         int v1, v2;
//         cin>>v1>>v2;

//         // 保证物品一占用空间大
//         if (v1 < v2)
//         {
//             swap(v1, v2);
//             swap(cnt1, cnt2);
//         }

//         int ans = 0;
//         // 枚举 b1 背包中物品一的个数
//         for (int i1 = 0; i1 <= cnt1; i1++)
//         {
//             if (i1 * v1 > b1)
//             {
//                 break;
//             }
//             // b1 背包中物品二的个数
//             int i2 = min(cnt2, (b1 - i1 * v1) / v2);
//             // 枚举 b2 背包中物品一的个数
//             for (int j1 = 0; j1 <= cnt1 - i1; j1++)
//             {
//                 if (j1 * v1 > b2)
//                 {
//                     break;
//                 }
//                 // b2 背包中物品二的个数
//                 int j2 = min(cnt2 - i2, (b2 - j1 * v1) / v2);

//                 // b3背包无需枚举，优先放占用空间小的即可
//                 int k2 = min(cnt2 - i2 - j2, b3 / v2);
//                 int k1 = min(cnt1 - i1 - j1, (b3 - k2 * v2) / v1);

//                 ans = max(ans, i1 + i2 + j1 + j2 + k1 + k2);
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }