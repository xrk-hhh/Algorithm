// #include <stdio.h>
// #include <math.h>

// int is_prime(long long n);
// long long reverse_num(long long n);

// int main()
// {
//     /*
//         需求：区间的真素数
//         题目描述：
//         找出正整数 M 和 N 之间（N 不小于 M）的所有真素数。

//         真素数的定义：如果一个正整数 P 为素数，且其反序也为素数，那么 P 就为真素数。

//         例如，11，13 均为真素数，因为 11 的反序还是为 11，13 的反序为 31 也为素数。

//         输入格式：
//         输入两个数 M 和 N，空格间隔。

//         输出格式：
//         按从小到大输出 M 和 N 之间（包括 M 和 N）的真素数，逗号间隔。如果之间没有真素数，则输出 No。

//         说明/提示：
//         1≤M≤N≤100000
    
//     */

//     long long a, b;
//     scanf("%lld %lld", &a, &b);

//     long long result[10000]; // 存储找到的真素数（1e5内足够）
//     int count = 0;           // 记录真素数个数

//     // 遍历区间[a, b]，逐个判断真素数
//     for (long long n = a; n <= b; n++) 
//     {
//         // 条件1：n是素数
//         if (is_prime(n)) 
//         {
//             // 条件2：n的反序数也是素数
//             long long rev = reverse_num(n);
//             if (is_prime(rev)) 
//             {
//                 result[count++] = n; // 存入结果数组
//             }
//         }
//     }

//     // 按要求输出结果
//     if (count == 0) 
//     {
//         printf("No\n"); // 无真素数时输出No
//     } 
//     else 
//     {
//         // 有真素数：逗号分隔输出，最后一个数后无逗号
//         for (int i = 0; i < count; i++) 
//         {
//             if (i > 0) 
//             {
//                 printf(",");
//             }
//             printf("%lld", result[i]);
//         }
//         printf("\n");
//     }

//     return 0;
// }


// // 质数判断函数
// int is_prime(long long n)
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
//     long long sqrt_n = (long long)sqrt(n);
//     // 只查奇数
//     for (long long i = 3; i <= sqrt_n; i += 2)
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
 
// // 计算数字n的反序数
// long long reverse_num(long long n) 
// {
//     long long rev = 0;
//     while (n > 0) 
//     {
//         rev = rev * 10 + n % 10; // 取最后一位，拼接到反序数末尾
//         n = n / 10;              // 去掉最后一位
//     }
//     return rev;
// }
