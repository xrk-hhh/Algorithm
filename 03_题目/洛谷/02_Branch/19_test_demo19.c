// #include <stdio.h>

// long long gcd(long long a, long long b);
// int main()
// {
//     /*
//         需求：三角函数
//         题目描述：
//         输入一组勾股数 a,b,c（a ≠ b ≠ c），用分数格式输出其较小锐角的正弦值。（要求约分）

//         输入格式：
//         一行，包含三个正整数，即勾股数 a,b,c（无大小顺序）。

//         输出格式：
//         一行，包含一个分数，即较小锐角的正弦值

//         说明/提示：
//         数据保证：a,b,c 为正整数且 ∈[1,10^9]。
//     */
//     long long a, b, c;
//     scanf("%lld %lld %lld",&a,&b,&c);

//     // // 三步排序：确保x≤y≤z（x是最短直角边，z是斜边）
//     // long long x, y, z;
//     // x = a; y = b; z = c;
//     // if (x > y) { long long t = x; x = y; y = t; }
//     // if (y > z) { long long t = y; y = z; z = t; }
//     // if (x > y) { long long t = x; x = y; y = t; }
//     // 将三个数存入数组并按从小到大排序
//     long long arr[3] = {a, b, c};
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = i + 1; j < 3; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 long long temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     // 较小锐角的正弦值 = 较短直角边（arr[0]） / 斜边（arr[2]）
//     // 分子：较短直角边
//     long long numerator = arr[0];   
//     // 分母：斜边
//     long long denominator = arr[2]; 
//     // 计算GCD
//     long long g = gcd(numerator, denominator); 

//     // 约分后输出
//     printf("%lld/%lld\n", numerator / g, denominator / g);
//     return 0;
// }
// /* 
//     辗转相除法：
//     核心原理：两个数的最大公约数等于其中较小的数与两数相除余数的最大公约数。
//             对于任意两个正整数 a 和 b （假设a > b），设 a 除以 b的商为q，余数为 r
//             （a = b * q + r）
//             GCD(a,b) = GCD(b,a%b)
//             通过反复运用这个等式，将“求a和b的GCD”转化为“求b和r的GCD”，再转化为更小的数对的GCD，直到余数为0。
//             此时，当前的除数就是最初两个数的GCD
//  */
// // 辗转相除法计算最大公约数（GCD）
// long long gcd(long long a, long long b) 
// {
//     while (b != 0) 
//     {
//         long long temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
// // long long gcd(long long a, long long b) 
// // { 
// //     // 如果 b=0 ，此时 a 即为GCD，返回a
// //     // 如果 b≠0 ，执行gcd(b, a % b)
// //     return b ? gcd(b, a % b) : a; 
// // }