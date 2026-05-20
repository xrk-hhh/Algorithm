// #include <stdio.h>
// #include <math.h>

// int is_prime(int n);

// int main()
// {
//     /*
//         需求：质因数分解
//         题目描述：
//         已知正整数 n 是两个不同的质数的乘积，试求出两者中较大的那个质数。

//         输入格式：
//         输入一个正整数 n。

//         输出格式：
//         输出一个正整数 p，即较大的那个质数。

//         说明/提示：
//         1≤n≤2×10^9
//     */


//     /*
//         注：对于本题，也可不用判断其是否为质数
//         因为：已知正整数 n 是两个不同的质数的乘积
//         所以只需找到2到sqrtn的一个整数，
//         满足其能被n整除，
//         则对应的另一个因数n/i即为所求
//     */
//     int n;
//     scanf("%d",&n);

//     int large_prime = 0;
//     for (int i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             if (is_prime(i) && is_prime(n / i))
//             {
//                 large_prime = n / i;
//                 break;
//             }
//         }
//     }

//     printf("%d",large_prime);
//     return 0;
// }
// // 质数判断函数
// int is_prime(int n)
// {
//     // <= 1不是质数
//     if (n <= 1)
//     {
//         return 0;
//     }
//     // 2是质数
//     if (n == 2)
//     {
//         return 1;
//     }
//     // 偶数（>2）不是质数
//     if (n % 2 == 0)
//     {
//         return 0;
//     }
//     // 检查到平方根即可
//     int sqrt_n = (int)sqrt(n);
//     // 只查奇数
//     for (int i = 3; i <= sqrt_n; i += 2)
//     {
//         // 有因数，不是质数
//         if (n % i == 0)
//         {
//             return 0;
//         }
//     }
//     // 是质数
//     return 1;
// }