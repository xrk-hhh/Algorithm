// #include <stdio.h>
// #include <math.h>

// int is_prime(long long n);

// int main()
// {
//     /*
//         需求：回文质数 Prime Palindromes
//         题目描述：
//         因为 151 既是一个质数又是一个回文数（从左到右和从右到左是看一样的），所以 151 是回文质数。

//         写一个程序来找出范围 [a,b](5≤a<b≤100,000,000)（一亿）间的所有回文质数。

//         输入格式：
//         第一行输入两个正整数 a 和 b。

//         输出格式：
//         输出一个回文质数的列表，一行一个。

//         说明/提示：
//         Hint 1: Generate the palindromes and see if they are prime.
//         提示 1: 找出所有的回文数再判断它们是不是质数（素数）.

//         Hint 2: Generate palindromes by combining digits properly. You might need more than one of the loops like below.
//         提示 2: 要产生正确的回文数，你可能需要几个像下面这样的循环。
//         题目翻译来自NOCOW。

//         USACO Training Section 1.5

//         产生长度为 5 的回文数：

//         for (d1 = 1; d1 <= 9; d1+=2) 
//         {    // 只有奇数才会是素数
//             for (d2 = 0; d2 <= 9; d2++) 
//             {
//                 for (d3 = 0; d3 <= 9; d3++) 
//                 {
//                 palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;//(处理回文数...)
//                 }
//             }
//         }
//     */
//     long long a, b;
//     scanf("%lld %lld",&a,&b);

//     // 方法一：效率太低，对于处理1亿范围内的数而言，非常浪费资源与时间
//     // for (long long i = a; i <= b; i++)
//     // {
//     //     long long num = i;
//     //     long long rev = 0;
//     //     while (num != 0)
//     //     {
//     //         long long temp = num % 10;
//     //         num = num / 10;
//     //         rev = rev * 10 + temp;
//     //     }
//     //     if (rev == i)
//     //     {
//     //         if (is_prime(rev))
//     //         {
//     //             printf("%lld\n",rev);
//     //         }
//     //     }
//     // }


//     // 方法二：效率极高，高效生成回文数再判断是否在[a,b]范围内，最后判断其是否为质数

//     /*
//         1.利用回文数特性减少范围：
//         除 11 外，所有偶数位回文数（如 4 位、6 位、8 位）均可被 11 整除，因此不是质数，可直接跳过。
//         质数（除 2 外）均为奇数，因此回文数的首位和末位（因对称，首位 = 末位）必须是奇数（1、3、5、7、9），避免生成偶数回文数。

//         2.按位数构造回文数：
//         针对 1 位、3 位、5 位、7 位（奇数位）和特殊的 2 位（仅 11）构造回文数，覆盖所有可能的回文质数范围。

//         3.分步筛选：
//         生成回文数后，先检查是否在 [a, b] 范围内，再判断是否为质数，最后输出。
//     */

//     // 1位数回文质数：2,3,5,7（1位数回文数即自身，且只有这4个是质数）
//     // 即使此处数值很小，依旧使用long long，是为了保证类型一致性、代码健壮性和输出格式的严格匹配。
//     long long one_digits[] = {2,3,5,7};
//     for (int i = 0; i < 4; i++)
//     {
//         long long p = one_digits[i];
//         if (p >= a && p <= b)
//         {
//             printf("%lld\n",p);
//         }
//     }

//     // 2位数回文质数：仅11（其他2位回文数如22、33等均为11的倍数，非质数）
//     if (11 >= a && 11 <= b)
//     {
//         printf("11\n");
//     }

//     // 3位数回文数：结构为aba（a为1,3,5,7,9；b为0-9）
//     // 首位a3为奇数
//     for (int a3 = 1; a3 <= 9; a3 += 2)
//     {
//         // 中间位b3
//         for (int b3 = 0; b3 <= 9; b3++)
//         {
//             // 构造3位数aba
//             long long pal = 100 * a3 + 10 * b3 + a3;
//             // 超出范围，无需继续
//             if (pal > b)
//             {
//                 break;
//             }
//             if (pal >= a && is_prime(pal))
//             {
//                 printf("%lld\n",pal);
//             }
//         }
//     }


//     // 5位数回文数：结构为abcba（a为1,3,5,7,9；b,c为0-9）
//     for (int a5 = 1; a5 <= 9; a5 += 2)
//     {
//         for (int b5 = 0; b5 <= 9; b5++)
//         {
//             for (int c5 = 0; c5 <= 9; c5++)
//             {
//                 long long pal = 10000 * a5 + 1000 * b5 + 100 * c5 + 10 * b5 + a5;
//                 // 若此时pal已经大于b，其后数也必定大于b，无继续循环必要
//                 // 但若是小于a，pal可继续随着循环增大
//                 if (pal > b)
//                 {
//                     break;
//                 }
//                 if (pal >= a && is_prime(pal))
//                 {
//                     printf("%lld\n",pal);
//                 }
//                 }
//         }
//     }


//     // 7位数回文数：结构为abcdcba（a为1,3,5,7,9；b,c,d为0-9）
//     for (int a7 = 1; a7 <= 9; a7 += 2)
//     {
//         for (int b7 = 0; b7 <= 9; b7++)
//         {
//             for (int c7 = 0; c7 <= 9; c7++)
//             {
//                 for (int d7 = 0; d7 <= 9; d7++)
//                 {
//                     long long pal = 1000000 * a7 + 100000 * b7 + 10000 * c7 + 1000 * d7 + 100 * c7 + 10 * b7 + a7;
//                     if (pal > b)
//                     {
//                         break;
//                     }
//                     if (pal >= a && is_prime(pal))
//                     {
//                         printf("%lld\n",pal);
//                     }
//                 }
//             }
//         }
//     }


//     return 0;
// }
// // 质数判断函数
// int is_prime(long long n)
//  {
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
//  }