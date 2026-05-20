// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 整理出一个将序列中的数字以逗号隔开从而得到的字符串
//      * @param a int整型vector 需要整理的序列 a
//      * @return string字符串
//      */
//     string commaTransformer(vector<int>& a) {
//         // write code here
//         string s;
//         for (int i = 0; i < a.size(); i++)
//         {
//             int k = a[i];
//             if (k < 0)
//             {
//                 s += '-';
//                 k = -k;
//             }
//             if (k == 0)
//             {
//                 s += k + '0';
//             }
//             string tmp;
//             while (k)
//             {
//                 tmp += k % 10 + '0';
//                 k /= 10;
//             }
//             for (int j = tmp.size() - 1; j >= 0; j--)
//             {
//                 s += tmp[j];
//             }
//             if (i < a.size() - 1)
//             {
//                 s += ',';
//             }
//         }
//         return s;
//     }
// };