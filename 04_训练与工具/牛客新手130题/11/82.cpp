// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 计算出旺仔哥哥最后会站在哪位小朋友旁边
//      * @param a int整型vector 第 i 个小朋友的数字是 a_i
//      * @param m int整型 表示旺仔哥哥的移动次数
//      * @return int整型
//      */
//     int stopAtWho(vector<int>& a, int m) {
//         // write code here
//         int idx = 0;
//         int len = a.size();
//         while (m--)
//         {
//             int t = a[idx] % len;
//             idx = (idx + len - t) % len;
//         }
//         return idx + 1;
//     }
// };