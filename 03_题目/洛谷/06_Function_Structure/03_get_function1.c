// #include <stdio.h>
// #include <math.h>

// double get_sqrt(double x, int n);

// int main()
// {
//     /*
//         需求：求f(x,n)
//         题目描述
//         已知 f(x,n)= sqrt( n+sqrt( n-1+sqrt( n-2+sqrt(...+2+sqrt(1+x) ) ) ) )
//         计算 f(x,n) 的值。

//         输入格式：
//         输入 x 和 n。

//         输出格式：
//         函数值，保留两位小数。

//         说明/提示：
//         数据范围
//         对于 100% 的数据，1≤x,n≤10。
//     */

//     double x;
//     int n;
//     scanf("%lf %d",&x,&n);

//     // 获取结果
//     double result = get_sqrt(x,n);
//     // 输出打印
//     printf("%.2lf",result);

//     return 0;
// }

// // 求f(x,n)
// double get_sqrt(double x, int n)
// {
//     // 初始化 get_sqrt 为 sqrt(1+x)
//     double get_sqrt = sqrt(1 + x);
//     // 用循环模拟递归过程
//     for (int i = 2; i <= n; i++)
//     {
//         get_sqrt = sqrt(i + get_sqrt);
//     }
//     // 返回get_sqrt
//     return get_sqrt;
// }