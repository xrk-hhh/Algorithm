// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 求出最终获胜帮派的名称
//      * @param s string字符串 
//      * @return string字符串
//      */
//     string predictVictory(string s) {
//         // write code here
//         int len = s.size();
//         queue<int> r, d;
//         for (int i = 0; i < len; i++)
//         {
//             if (s[i] == 'R')
//             {
//                 r.push(i);
//             }
//             else 
//             {
//                 d.push(i);
//             }
//         }
//         while (!r.empty() && !d.empty())
//         {
//             int r_idx = r.front();
//             r.pop();
//             int d_idx = d.front();
//             d.pop();

//             if (r_idx < d_idx)
//             {
//                 r.push(r_idx + len);
//             }
//             else 
//             {
//                 d.push(d_idx + len);
//             }
//         }

//         if (r.empty())
//         {
//             return "Dark";
//         }
//         else 
//         {
//             return "Red";
//         }
//     }
// };