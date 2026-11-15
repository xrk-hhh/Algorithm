// #include <stdio.h>

// double get_fraction(double x, int n);

// int main()
// {
//     /*
//         需求：再求f(x,n)
//         题目描述：
//         已知

//         f(x,n) = x / ( n + (x / ( (n - 1) + x / ( n - 2 + .../ ... + x / (1 + x) ) ) ) )

//         用递归函数求解。

//         输入格式：
//         第一个数是 x 的值，第二个数是 n 的值。（x 为实数，n 为整数）

//         输出格式：
//         函数值，保留两位小数。
//     */

//     double x;
//     scanf("%lf",&x);
//     int n;
//     scanf("%d",&n);

//     // 获取结果
//     double result = get_fraction(x,n);
//     // 输出打印
//     printf("%.2lf",result);

//     return 0;
// }

// // 再求 f(x,n)
// double get_fraction(double x, int n)
// {
//     // 初始化 get_fraction 为 x / (1 + x)
//     double get_fraction = x / (1 + x);
//     // 利用循环实现递归
//     for (int i = 2; i <= n; i++)
//     {
//         get_fraction = x / (i + get_fraction);
//     }

//     // 返回get_fraction
//     return get_fraction;
// }