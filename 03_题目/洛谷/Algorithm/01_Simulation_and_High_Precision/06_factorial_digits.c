// // #include <stdio.h>
// // #define MAX 2580

// // int main()
// // {
// //     int t;
// //     scanf("%d", &t);

// //     while (t--)
// //     {
// //         int n, a;
// //         scanf("%d %d", &n, &a);

// //         int res[MAX] = {0};
// //         res[0] = 1;
// //         int res_len = 1;

// //         for (int i = 2; i <= n; i++)
// //         {
// //             int carry = 0;
// //             for (int j = 0; j < res_len; j++)
// //             {
// //                 int product = res[j] * i + carry;
// //                 res[j] = product % 10;
// //                 carry = product / 10;
// //             }
// //             while (carry > 0)
// //             {
// //                 res[res_len] = carry % 10;
// //                 carry /= 10;
// //                 res_len++;
// //             }
// //         }
// //         int cnt = 0;
// //         for (int i = res_len - 1; i >= 0; i--)
// //         {
// //             if (res[i] == a)
// //             {
// //                 cnt++;
// //             }
// //         }
// //         printf("%d\n", cnt);
// //     }
    
// //     return 0;
// // }

// // 以上方法为每一次循环计算n的阶乘

// // 以下为预处理计算0到1000的阶乘
// #include <stdio.h>

// #define N 1010
// #define MAX 2580

// int fact[N][10];
// int res[MAX];
// int len;

// void init()
// {
//     res[0] = 1;
//     len = 1;
//     fact[0][1] = 1;

//     for (int i = 1; i <= 1000; i++)
//     {
//         int carry = 0;
//         for (int j = 0; j < len; j++)
//         {
//             int tmp = res[j] * i + carry;
//             res[j] = tmp % 10;
//             carry = tmp / 10;
//         }
//         while (carry)
//         {
//             res[len] = carry % 10;
//             carry /= 10;
//             len++;
//         }

//         int cnt[10] = {0};
//         for (int j = 0; j < len; j++)
//         {
//             cnt[res[j]]++;
//         }

//         for (int j = 0; j < 10; j++)
//         {
//             fact[i][j] = cnt[j];
//         }

//     }
// }

// int main()
// {
//     init();

//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         int n, a;
//         scanf("%d %d", &n, &a);

//         printf("%d\n", fact[n][a]);
//     }

//     return 0;
// }