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

//         while (n--)
//         {
//             string s;
//             cin>>s;

//             int len = s.size();

//             // 除 o 外小写字母个数、除 O 外大写字母个数、除 0 外数字个数
//             int cnta = 0, cntA = 0, cnt1 = 0;
//             int cnto = 0, cntO = 0, cnt0 = 0;
//             for (int i = 0; i < len; i++)
//             {
//                 if (s[i] != 'o' && s[i] != 'O' && s[i] != '0')
//                 {
//                     if (islower(s[i]))
//                     {
//                         cnta++;
//                     }
//                     else if (isupper(s[i]))
//                     {
//                         cntA++;
//                     }
//                     else if (isdigit(s[i]))
//                     {
//                         cnt1++;
//                     }
//                 }
//                 else
//                 {
//                     if (s[i] == 'o')
//                     {
//                         cnto++;
//                     }
//                     else if (s[i] == 'O')
//                     {
//                         cntO++;
//                     }
//                     else if (s[i] == '0')
//                     {
//                         cnt0++;
//                     }
//                 }
//             }
            
//             // 需要转换的字符数量
//             int need = (cnta == 0) + (cntA == 0) + (cnt1 == 0);
//             // 优先特殊情况：本类型可替换数量限制（求出多余的字符）
//             if (cnta == 0 && cnto)
//             {
//                 cnto--;
//                 need--;
//             }
//             if (cntA == 0 && cntO)
//             {
//                 cntO--;
//                 need--;
//             }
//             if (cnt1 == 0 && cnt0)
//             {
//                 cnt0--;
//                 need--;
//             }

//             // 是否有足够可替换的字符（多余的）
//             cout<<(need <= cnto + cntO + cnt0 ? need : -1)<<endl;
//         }
//     }

//     return 0;
// }