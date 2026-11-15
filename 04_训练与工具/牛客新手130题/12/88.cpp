// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 给定一个后缀表达式，返回它的结果
//      * @param str string字符串 
//      * @return long长整型
//      */
//     long long legalExp(string str) {
//         // write code here
//         int len = str.size();
//         stack<long long> st;

//         long long num = 0;
//         for (int i = 0; i < len; i++)
//         {
//             if (str[i] >= '0' && str[i] <= '9')
//             {
//                 num = num * 10 + (str[i] - '0');
//             }
//             else if (str[i] == '#')
//             {
//                 st.push(num);
//                 num = 0;
//             }
//             else 
//             {
//                 char op = str[i];
//                 long long num2 = st.top();
//                 st.pop();
//                 long long num1 = st.top();
//                 st.pop();
//                 long long res;
//                 if (op == '+')
//                 {
//                     res = num1 + num2;
//                 }
//                 else if (op == '-')
//                 {
//                     res = num1 - num2;
//                 }
//                 else 
//                 {
//                     res = num1 * num2;
//                 }
//                 st.push(res);
//             }
//         }
//         return st.top();
//     }
// };