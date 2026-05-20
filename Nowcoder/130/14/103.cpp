// #include <bits/stdc++.h>
// using namespace std;

// // class Solution {
// // public:
// //     /**
// //      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
// //      *
// //      * 
// //      * @param n int整型 
// //      * @return bool布尔型
// //      */

// //     int happy(int t)
// //     {
// //         int res = 0;
// //         while (t)
// //         {
// //             res += (t % 10) * (t % 10);
// //             t /= 10;
// //         }
// //         return res;
// //     }

// //     bool happynum(int n) {
// //         // write code here
// //         while (n > 9)
// //         {
// //             n = happy(n);
// //         }
// //         return n == 1;
// //     }
// // };

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 
//      * @param n int整型 
//      * @return bool布尔型
//      */

//     bool happynum(int n) {
//         // write code here
//         multiset<int> s;
//         while (n != 1)
//         {
//             if (s.count(n))
//             {
//                 return false;
//             }

//             s.insert(n);

//             int sum = 0;
//             int tmp = n;
//             while (tmp)
//             {
//                 int num = tmp % 10;
//                 sum += num * num;
//                 tmp /= 10;
//             }
//             n = sum;
//         }
//         return true;
//     }
// };