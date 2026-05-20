// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// bool is_valid(string s)
// {
//     string rs = s;
//     reverse(rs.begin(), rs.end());
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] != rs[i])
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
//     cin>>T;
//     cin.ignore();

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         int ls = s.size();

//         // 判断是否回文
//         if (is_valid(s))
//         {
//             cout<<"Yes"<<endl;
//             continue;
//         }

//         // 后半部分（字符都是"lqb"其中的）
//         string t;
//         for (int i = ls - 1; i >= 0; i--)
//         {
//             if (s[i] == 'l' || s[i] == 'q' || s[i] == 'b')
//             {
//                 t += s[i];
//             }
//             else
//             {
//                 break;
//             }
//         }
//         int lt = t.size();

//         // 前半部分（字符都是"lqb"其中的）
//         string ts;
//         for (int i = 0; i < ls; i++)
//         {
//             if (s[i] == 'l' || s[i] == 'q' || s[i] == 'b')
//             {
//                 ts += s[i];
//             }
//             else
//             {
//                 break;
//             }
//         }
//         int lts = ts.size();

//         // 全是"lqb"
//         if (ls == lt && lt == lts)
//         {
//             cout<<"Yes"<<endl;
//             continue;
//         }

//         bool ok = true;
//         // 前半部分长度 <= 后半部分长度
//         if (lts <= lt)
//         {
//             // 判断[0, ls - lt + lts - 2]是否回文
//             for (int i = 0; i < ls - lt + lts - 1; i++)
//             {
//                 if (s[i] != s[ls - lt + lts - 1 - i])
//                 {
//                     cout<<"No"<<endl;
//                     ok = false;
//                     break;
//                 }
//             }
//             if (ok)
//             {
//                 cout<<"Yes"<<endl;
//             }
//         }
//         // 前半部分长度 > 后半部分长度
//         else
//         {
//             cout<<"No"<<endl;
//         }
//     }

//     return 0;
// }