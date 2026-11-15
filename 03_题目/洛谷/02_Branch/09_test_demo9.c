// #include <stdio.h>

// int main()
// {
//     /*
//         需求：月份天数
//         题目描述
//         输入年份和月份，输出这一年的这一月有多少天。需要考虑闰年。

//         输入格式
//         输入两个正整数，分别表示年份 y 和月数 m，以空格隔开。

//         输出格式
//         输出一行一个正整数，表示这个月有多少天。
//     */
//    int y, m;
//    scanf("%d %d",&y,&m);
//    switch (m)
//     {
//         case 1:
//         case 3:
//         case 5:
//         case 7:
//         case 8:
//         case 10:
//         case 12:
//             printf("31");
//             break;
//         case 4:
//         case 6:
//         case 9:
//         case 11:
//             printf("30");
//             break;
//         default:
//             if ( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
//             {
//                 printf("29");
//             }
//             else
//             {
//                 printf("28");
//             }
//             break;
//     }
//     return 0;
// }