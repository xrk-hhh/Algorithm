// #include <stdio.h>

// #define MAXN 40010

// char str[MAXN];

// int main()
// {
//     int N;
//     int num;
//     int idx = 0;
//     for (int i = 0; scanf("%d", &num) != EOF; i++)
//     {
//         if (i == 0)
//         {
//             N = num;
//             continue;
//         }
//         if ((i & 1) == 1)
//         {
//             for (int j = 0; j < num; j++)
//             {
//                 str[idx++] = '0';
//             }
//         }
//         else
//         {
//             for (int j = 0; j < num; j++)
//             {
//                 str[idx++] = '1';
//             }
//         }
//     }

//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             printf("%c", str[i * N + j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }