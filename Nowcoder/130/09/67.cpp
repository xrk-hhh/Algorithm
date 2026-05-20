// class Solution {
// public:
//     /**
//      * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//      *
//      * 计算 n 的阶乘
//      * @param n int整型 
//      * @return int整型
//      */
//     int factorialOfN(int n) {
//         long long ans = 1;
//         long long mod = 1000000007;
//         for (int i = 2; i <= n; i++)
//         {
//             ans = (ans * i) % mod;
//         }
//         return (long long)ans;
//     }
// };