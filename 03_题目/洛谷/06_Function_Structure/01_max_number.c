// #include <stdio.h>

// int max(int x, int y, int z);

// int main()
// {
//     /*
//         需求：最大数max(x,y,z)
//         题目描述:
//         已知：

//         m = max(a,b,c) / ( max(a+b,b,c) × max(a,b,b+c) )

//         输入三个整数 a，b，c，求 m。

//         把求三个数的最大数 max(x,y,z) 分别定义成函数和过程来做。

//         输入格式:
//         输入只有一个行三个整数，分别为 a,b,c。

//         输出格式:
//         输出一行一个小数，为答案，保留三位小数。

//         说明/提示:
//         数据规模与约定
//         对于全部的测试点，保证 ∣a∣,∣b∣,∣c∣≤50。换句话说，a,b,c 都在 −50 到 50 之间。
//         测试数据保证，分式的分母不为 0。

//     */

//     int a, b, c;
//     scanf("%d %d %d",&a,&b,&c);

//     // 将各最大数转换为 double 类型，以便后续 m 的计算
//     double max1 = (double)max(a,b,c);
//     double max2 = (double)max(a+b,b,c);
//     double max3 = (double)max(a,b,b+c);

//     // 计算 m 
//     double m = max1 / (max2 * max3);

//     // 输出打印
//     printf("%.3lf",m);

//     return 0;
// }

// // 获取最大数max
// int max(int x, int y, int z)
// {
//     int max = x;
//     max = max > y ? max : y;
//     max = max > z ? max : z;

//     return max;
// }