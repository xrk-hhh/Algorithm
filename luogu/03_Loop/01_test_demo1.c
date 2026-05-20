// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     /*
//         需求：找最小值
//         题目描述:
//         给出 n 和 n 个整数 ai，求这 n 个整数中最小值是什么。

//         输入格式:
//         第一行输入一个正整数 n，表示数字个数。

//         第二行输入 n 个非负整数，表示 a1,a2,...an ，以空格隔开。

//         输出格式：
//         输出一个非负整数，表示这 n 个非负整数中的最小值。
//     */

//     int n;
//     scanf("%d",&n);

//     // int arr[1000000];
//     // 为数组分配内存
//     int* arr = (int*)malloc(n * sizeof(int));
//     if (arr == NULL)
//     {
//         //检查内存分配是否成功
//         return 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     // 初始化第一个元素为最小值
//     int min = arr[0];
//     // 遍历替换最小值
//     for (int i = 1; i < n; i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//         }
//     }

//     printf("%d",min);

//     // 释放内存
//     free(arr);
//     arr = NULL;
//     return 0;
// }