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
//         int a, b, c;
//         cin>>a>>b>>c;

//         // 特判 c 为 0 时，即只有一个元素
//         if (!c)
//         {
//             if (a != 0 && b != 0)
//             {
//                 cout<<-1<<endl;
//             }
//             else
//             {
//                 for (int i = 0; i < a; i++)
//                 {
//                     cout<<'L';
//                 }
//                 for (int i = 0; i < b; i++)
//                 {
//                     cout<<'Q';
//                 }
//             }
//             return 0;
//         }

//         // 需要多少个 'L' 和 'Q'
//         // 第一种情况：LQLQLQ...
//         // 第二种情况：QLQLQL...
//         int Lneed = c / 2 + 1, Qneed = (c + 1) / 2;
//         // 能构造第一种
//         if (a >= Lneed && b >= Qneed)
//         {
//             // 将多余的'L'放在最前面
//             for (int i = 0; i < a - Lneed; i++)
//             {
//                 cout<<'L';
//             }
//             for (int i = 0; i < Lneed + Qneed - 1; i++)
//             {
//                 if (i & 1)
//                 {
//                     cout<<'Q';
//                 }
//                 else
//                 {
//                     cout<<'L';
//                 }
//             }

//             // 若最后一个是 'L'，则将多余的'Q'加在最后一个'Q'后面
//             if ((Lneed + Qneed) & 1)
//             {
//                 for (int i = 0; i < b - Qneed; i++)
//                 {
//                     cout<<'Q';
//                 }
//                 cout<<'L';
//             }
//             // 否则将多余的'Q'放在最后面
//             else
//             {
//                 cout<<'L';
//                 for (int i = 0; i < b - Qneed; i++)
//                 {
//                     cout<<'Q';
//                 }
//             }
//         }
//         // 无法构造出第一种情况
//         else
//         {
//             // 第二种情况
//             swap(Lneed, Qneed);
//             // 无法构造出第二种情况
//             if (a < Lneed || b < Qneed)
//             {
//                 cout<<-1<<endl;
//                 return 0;
//             }

//             // 显然无多余的'L'，若有则必能构造第一种情况
//             // 如贡献子段为 QLQ，若有多余的'L'，则能构造出 LQl
//             for (int i = 0; i < Lneed + Qneed; i++)
//             {
//                 if (i & 1)
//                 {
//                     cout<<'L';
//                 }
//                 else
//                 {
//                     cout<<'Q';
//                 }
//             }
//             // 显然最后一个肯定是'Q'，若有则必能构造第一种情况
//             // 如贡献子段为 QLQL，若有多余的'L'，则能构造出 LQLQ
//             for (int i = 0; i < b - Qneed; i++)
//             {
//                 cout<<'Q';
//             }
//         }
//     }

//     return 0;
// }