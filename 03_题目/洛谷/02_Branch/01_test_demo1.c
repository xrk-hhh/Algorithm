// #include <stdio.h>

// int main()
// {
//     /*
//         需求：三位数排序
//         题目描述：
//         给出三个整数 a,b,c(0≤a,b,c≤100)，要求把这三位整数从小到大排序。

//         输入格式：
//         输入三个整数 a,b,c，以空格隔开。

//         输出格式：
//         输出一行，三个整数，表示从小到大排序后的结果。
//     */
    
//     int a, b, c;
//     scanf("%d %d %d",&a,&b,&c);
//     //方法一：嵌套判断语句
//     if (a <= b && a <= c )
//     {
//         if (b <= c)
//         {
//             printf("%d %d %d",a,b,c);
//         }
//         else
//         {
//             printf("%d %d %d",a,c,b);
//         }
//     }
//     else if (b <= a && b <=c)
//     {
//         if (a <= c)
//         {
//             printf("%d %d %d",b,a,c);
//         }
//         else
//         {
//             printf("%d %d %d",b,c,a);
//         }
//     }
//     else
//     {
//         if (a <= b)
//         {
//             printf("%d %d %d",c,a,b);
//         }
//         else
//         {
//             printf("%d %d %d",c,b,a);
//         }
//     }

//     //方法二：通过选择排序，将数组中的数据按照升序进行排列
//     int arr[] = {a,b,c};
//     int len = sizeof(arr) / sizeof(int);

//     for (int i = 0; i < len - 1; i++)
//     {
//         for (int j = i + 1; j < len; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }