// #include <stdio.h>

// int main()
// {
//     /*
//         需求：三角形分类
//         题目描述：
//         给出三条线段 a,b,c 的长度，均是不大于 10000 的正整数。打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

//         如果三条线段不能组成一个三角形，输出Not triangle；
//         如果是直角三角形，输出Right triangle；
//         如果是锐角三角形，输出Acute triangle；
//         如果是钝角三角形，输出Obtuse triangle；
//         如果是等腰三角形，输出Isosceles triangle；
//         如果是等边三角形，输出Equilateral triangle。
//         如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。

//         输入格式：
//         输入 3 个整数 a、b 和 c。

//         输出格式：
//         输出若干行判定字符串。

//         说明/提示：
//         当两短边的平方和大于一长边的平方，说明是锐角三角形。

//         当两短边的平方和等于一长边的平方，说明是直角三角形。

//         当两短边的平方和小于一长边的平方，说明是钝角三角形。
//     */
//     int a, b, c;
//     scanf("%d %d %d",&a,&b,&c);

//     //任意两边之和
//     // int sum1, sum2, sum3;
//     // sum1 = a + b;
//     // sum2 = b + c;
//     // sum3 = a + c;

//     //将a,b,c存入数组，再用选择排序，使其按升序排列
//     int arr[] = {a,b,c};
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = i + 1; j < 3; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     //d-最短边  e-第二短边  f-最长边
//     int d = arr[0], e = arr[1], f = arr[2];
//     //g-最短边平方  h-第二短边平方  i-最长边平方
//     int g = d * d, h = e * e, i = f * f;

//     //是否能组成三角形
//     if (d + e > f)
//     {
//         //锐角
//         if (g + h > i)
//         {
//             //等腰
//             if (d == e )
//             {
//                 //等边
//                 if (d == f)
//                 {
//                     printf("Acute triangle\nIsosceles triangle\nEquilateral triangle");
//                 }
//                 else
//                 {
//                     printf("Acute triangle\nIsosceles triangle");
//                 }
//             }
//             else
//             {
//                 printf("Acute triangle");
//             }
//         }
//         //直角
//         else if (g + h == i)
//         {
//             //等腰
//             if (d == e )
//             {
//                 printf("Right triangle\nIsosceles triangle");
//             }
//             else
//             {
//                 printf("Right triangle");
//             }
//         }
//         //钝角
//         else
//         {
//             //等腰
//             if (d == e )
//             {
//                 printf("Obtuse triangle\nIsosceles triangle");
//             }
//             else 
//             {
//                 printf("Obtuse triangle");
//             }
//         }
//     }
//     else
//     {
//         printf("Not triangle");
//     }
//     return 0;
// }