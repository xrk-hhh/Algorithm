// #include <stdio.h>
// #include <string.h>

// long long w(long long a, long long b, long long c);

// // 记忆化数组（a,b,c≤20，所以开21*21*21足够）
// long long memo[21][21][21];

// int main()
// {
//     /*
//         需求：Function
//         题目描述：
//         对于一个递归函数 w(a,b,c)

//         如果 a≤0 或 b≤0 或 c≤0 就返回值 1。
//         如果 a>20 或 b>20 或 c>20 就返回 w(20,20,20)
//         如果 a<b 并且 b<c 就返回 w(a,b,c−1)+w(a,b−1,c−1)−w(a,b−1,c)。
//         其它的情况就返回 w(a−1,b,c)+w(a−1,b−1,c)+w(a−1,b,c−1)−w(a−1,b−1,c−1)
//         这是个简单的递归函数，但实现起来可能会有些问题。当 a,b,c 均为 15 时，调用的次数将非常的多。你要想个办法才行。

//         注意：例如 w(30,−1,0) 又满足条件 1 又满足条件 2，请按照最上面的条件来算，答案为 1。

//         输入格式：
//         会有若干行。
//         并以 −1,−1,−1 结束。

//         输出格式
//         输出若干行，每一行格式：
//         w(a, b, c) = ans
//         注意空格。
    
//         说明/提示：
//         数据规模与约定
//         保证输入的数在 [−9223372036854775808,9223372036854775807] 之间，并且是整数。
//         保证不包括 −1,−1,−1 的输入行数 T 满足 1≤T≤10^5。
//     */

//     // 初始化记忆化数组为-1（未计算）
//     memset(memo, -1, sizeof(memo));

//     long long a, b, c;
//     // 循环读取三个数，直到输入-1,-1,-1
//     while (scanf("%lld %lld %lld", &a, &b, &c) != EOF) 
//     {
//         // 终止条件：三个数都是-1
//         if (a == -1 && b == -1 && c == -1)
//         {
//             break;
//         }
//         // 计算并输出结果（格式匹配）
//         printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
//     }

//     return 0;
// }

// long long w(long long a, long long b, long long c)
// {
//     // 条件1：a <= 0 或 b <= 0 或 c <= 0 返回 1
//     if (a <= 0 || b <= 0 || c <= 0)
//     {
//         return 1;
//     }
//     // 条件2：a > 20 或 b > 20 或 c > 20 返回 w(20,20,20)
//     if (a > 20 || b > 20 || c > 20)
//     {
//         return w(20, 20, 20);
//     }
//     // 记忆化：已计算过的子问题直接返回
//     if (memo[(int)a][(int)b][(int)c] != -1)
//     {
//         return memo[(int)a][(int)b][(int)c];
//     }
//     // 条件3：a < b 且 b < c
//     if (a < b && b < c)
//     {
//         memo[(int)a][(int)b][(int)c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
//         return memo[(int)a][(int)b][(int)c];
//     }
//     // 其他情况
//     memo[(int)a][(int)b][(int)c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
//     return memo[(int)a][(int)b][(int)c];
// }