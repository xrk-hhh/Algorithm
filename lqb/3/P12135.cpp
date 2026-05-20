// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string s1, s2;
//         cin>>s1>>s2;

//         int len = s1.size();

//         int cnt = 0;
//         int l = len, r = 0;
//         // 先找出第一次和最后一次出现 # 的位置
//         for (int i = 0; i < len; i++)
//         {
//             if (s1[i] == '#' || s2[i] == '#')
//             {
//                 l = min(l, i);
//                 r = max(r, i);
//             }
//         }

//         for (int i = l; i < r; i++)
//         {
//             // 第一种情况：
//             // # .
//             // .
//             // 此时需将第一行 # 后的 . 改为 #

//             if (s1[i] == '#' && s1[i + 1] == '.' && s2[i] == '.')
//             {
//                 s1[i + 1] = '#';
//                 cnt++;
//             }

//             // 第二种情况：
//             // .
//             // # .
//             // 此时需将第二行 # 后的 . 改为 #

//             if (s2[i] == '#' && s2[i + 1] == '.' && s1[i] == '.')
//             {
//                 s2[i + 1] = '#';
//                 cnt++;
//             }

//             // 第三种情况：
//             // # .
//             // # .
//             // 此时需将先出现下一个 # 的行的 # 后的 . 改为 #

//             if (s1[i] == '#' && s1[i + 1] == '.' && s2[i] == '#' && s2[i + 1] == '.')
//             {
//                 int p = i, q = i;
//                 for (int j = i + 1; j <= r; j++)
//                 {
//                     if (s1[j] == '#')
//                     {
//                         p = j;
//                         break;
//                     }

//                     if (s2[j] == '#')
//                     {
//                         q = j;
//                         break;
//                     }
//                 }

//                 if (p >= q)
//                 {
//                     s1[i + 1] = '#';
//                     cnt++;
//                 }
//                 else
//                 {
//                     s2[i + 1] = '#';
//                     cnt++;
//                 }
//             }
//         }
//         cout<<cnt<<endl;
//     }

//     return 0;
// }