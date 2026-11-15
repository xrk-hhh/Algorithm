// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 返回表达式的值
//      * @param s string字符串 待计算的表达式
//      * @return int整型
//      */
//     vector<int> fun(string s, int idx)
//     {
//         stack<int> st;
//         int num = 0;
//         char op = '+';
//         int i;
//         for (i = idx; i < s.size(); i++)
//         {
//             if (s[i] >= '0' && s[i] <= '9')
//             {
//                 num = num * 10 + (s[i] - '0');
//                 if (i != s.size() - 1)
//                 {
//                     continue;
//                 }
//             }
//             else if (s[i] == '(')
//             {
//                 vector<int> res = fun(s, i + 1);
//                 num = res[0];
//                 i = res[1];
//                 if (i != s.size() - 1)
//                 {
//                     continue;
//                 }
//             }
//             switch(op)
//             {
//                 case '+':
//                     st.push(num);
//                     break;
//                 case '-':
//                     st.push(-num);
//                     break;
//                 case '*':
//                     int tmp = st.top();
//                     st.pop();
//                     st.push(tmp * num);
//                     break;
//             }
//             num = 0;
//             if (s[i] == ')')
//             {
//                 break;
//             }
//             else 
//             {
//                 op = s[i];
//             }
//         }
//         int sum = 0;
//         while (!st.empty())
//         {
//             sum += st.top();
//             st.pop();
//         }
//         return vector<int> {sum, i};
//     }

//     int solve(string s) {
//         // write code here
//         return fun(s, 0)[0];
//     }
// };