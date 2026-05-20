// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// bool is_special(char c)
// {
//     string special = "~!@#$%^&*()_";
//     // find 是 std::string 的成员函数，返回子串或字符第一次出现的位置（索引），
//     // 如果找不到则返回 std::string::npos（一个特殊常量，通常等于 -1）
//     return special.find(c) != string::npos;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;
//     // 忽略输入流中的一个或多个字符。
//     cin.ignore();

//     while (T--)
//     {
//         string s;
//         // 从输入流中读取一整行（包括空格）并存入字符串 s
//         // 它遇到换行符停止，并将换行符从流中移除，但不存入 s。
//         getline(cin, s);

//         int len = s.size();
//         // 判断输入字符是否合法
//         bool valid = true;

//         int cnta = 0, cntA = 0;
//         int cnt1 = 0;
//         int cnt_ = 0;
//         set<char> st;
//         for (int i = 0; i < len; i++)
//         {
//             char c = s[i];
//             if (c >= 'A' && c <= 'Z')
//             {
//                 cntA++;
//             }
//             else if (c >= 'a' && c <= 'z')
//             {
//                 cnta++;
//             }
//             else if (c >= '0' && c <= '9')
//             {
//                 cnt1++;
//             }
//             else if (is_special(c))
//             {
//                 cnt_++;
//                 st.insert(c);
//             }
//             else
//             {
//                 valid = false;
//                 break;
//             }
//         }

//         if (!valid || len < 6)
//         {
//             cout<<"0"<<endl;
//             continue;
//         }

//         int type = st.size();

//         if (len >= 12 && ( (cntA && cnta && cnt1 && cnt_) || (cnt_ && ( (cntA && cnta) || (cntA && cnt1) || (cnta && cnt1) ) && type >= 3) )) 
//         {
//             cout<<"3"<<endl;
//         }
//         else if (len >= 8 && ((cntA > 0) + (cnta > 0) + (cnt1 > 0) + (cnt_ > 0) >= 2))
//         {
//             cout<<"2"<<endl;
//         }
//         else if (len >= 6)
//         {
//             cout<<"1"<<endl;
//         }
//         else
//         {
//             cout<<"0"<<endl;
//         }
//     }

//     return 0;
// }