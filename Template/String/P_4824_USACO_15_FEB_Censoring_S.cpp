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
//         string s, t;
//         cin>>s>>t;

//         int n = s.size(), m = t.size();

//         // 构建 next 数组
//         vector<int> nxt(m + 1, 0);
//         nxt[0] = -1;
//         int j = 0;
//         for (int i = 1; i < m; i++)
//         {
//             while (j > 0 && t[i] != t[j])
//             {
//                 j = nxt[j];
//             }

//             if (t[i] == t[j])
//             {
//                 j++;
//             }

//             nxt[i + 1] = j;
//         }

//         // 当前匹配长度
//         j = 0;
//         // 栈顶指针
//         int top = 0;
//         // st1：记录字符在 s 中的下标
//         // st2：记录当前匹配的长度
//         vector<int> st1(n + 1, 0), st2(n + 1, 0);
//         for (int i = 0; i < n; i++)
//         {
//             while (j > 0 && s[i] != t[j])
//             {
//                 j = nxt[j];
//             }

//             if (s[i] == t[j])
//             {
//                 j++;
//             }

//             // 入栈
//             st1[top] = i;
//             st2[top] = j;
//             top++;
//             // 匹配成功，弹出 m 个字符
//             if (j == m)
//             {
//                 top -= m;
//                 // 恢复匹配状态：栈顶若还有元素，取它的匹配长度；否则为 0
//                 if (top > 0)
//                 {
//                     j = st2[top - 1];
//                 }
//                 else
//                 {
//                     j = 0;
//                 }
//             }
//         }

//         for (int i = 0; i < top; i++)
//         {
//             cout<<s[st1[i]];
//         }
//         cout<<endl;
//     }

//     return 0;
// }