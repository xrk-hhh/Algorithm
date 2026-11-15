// #include <stdio.h>

// int num[510][510];
// int tmp[510][510];

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             num[i][j] = (i - 1) * n + j;
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         int x, y, r, z;
//         scanf("%d %d %d %d", &x, &y, &r, &z);

//         int s = 2 * r + 1;
//         int sx = x - r;
//         int sy = y - r;

//         for (int l = 1; l <= s; l++)
//         {
//             for (int k = 1; k <= s; k++)
//             {
//                 tmp[l][k] = num[sx + l - 1][sy + k - 1];
//             }
//         }
//         if (z == 0)
//         {
//             for (int l = 1; l <= s; l++)
//             {
//                 for (int k = 1; k <= s; k++)
//                 {
//                     num[sx + l - 1][sy + k - 1] = tmp[s - k + 1][l];
//                 }
//             }
//         }
//         else if (z == 1)
//         {
//             for (int l = 1; l <= s; l++)
//             {
//                 for (int k = 1; k <= s; k++)
//                 {
//                     num[sx + l - 1][sy + k - 1] = tmp[k][s - l + 1];
//                 }
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             printf("%d", num[i][j]);
//             if (j != n)
//             {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }