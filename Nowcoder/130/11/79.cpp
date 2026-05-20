// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 计算出这两个向量叉乘的结果
//      * @param vector1 int整型vector 
//      * @param vector2 int整型vector 
//      * @return int整型vector
//      */
//     vector<int> crossTimes(vector<int>& vector1, vector<int>& vector2) {
//         // write code here
//         int ax = vector1[0], ay = vector1[1], az = vector1[2];
//         int bx = vector2[0], by = vector2[1], bz = vector2[2];

//         vector<int> ans(3);
//         ans[0] = ay * bz - az * by;
//         ans[1] = az * bx - ax * bz;
//         ans[2] = ax * by - ay * bx;

//         return ans;
//     }
// };