// #include <stdio.h>

// int main()
// {
//     /*
//         需求：数糖果
//         题目描述：
//         幼儿园里，有5个小朋友编号为1、2、3、4、5，他们按自己的编号顺序围坐在一张圆桌旁。
//         他们身上都有若干个糖果(键盘输入)，现在他们做个分糖果游戏。
//         从1号小朋友开始，将自己的糖果均分三份(如果有多余的糖果，则立即吃掉)，自己留一份，其余两份分给他的相邻的两个小朋友。
//         接着2号、3号、4号、5号小朋友同样这么做。问
//         一轮后，每个小朋友手上分别有多少糖果。
//         输入格式：
//         5个小朋友的糖果数。
//         输出格式：
//         游戏后5个小朋友的糖果数。(按5位宽度输出)

//         注：不能使用循环
//     */
//     int num1, num2, num3, num4, num5;
//     scanf("%d %d %d %d %d",&num1, &num2, &num3, &num4, &num5);

//     // 1号
//     // 定义临时变量记录 1号 均分的量
//     int temp1 = num1 / 3;
//     num1 = temp1;
//     num2 += temp1;
//     num5 += temp1;

//     // 2号
//     int temp2 = num2 / 3;
//     num2 = temp2;
//     num1 += temp2;
//     num3 += temp2;

//     // 3号
//     int temp3 = num3 / 3;
//     num3 = temp3;
//     num2 += temp3;
//     num4 += temp3;

//     // 4号
//     int temp4 = num4 / 3;
//     num4 = temp4;
//     num3 += temp4;
//     num5 += temp4;

//     // 5号
//     int temp5 = num5 / 3;
//     num5 = temp5;
//     num4 += temp5;
//     num1 += temp5;

//     // 输出打印糖果数
//     printf("%5d %5d %5d %5d %5d",num1, num2, num3, num4, num5);
    
//     return 0;
// }