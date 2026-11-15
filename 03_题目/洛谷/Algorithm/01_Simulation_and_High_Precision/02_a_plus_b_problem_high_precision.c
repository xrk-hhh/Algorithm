// #include <stdio.h>
// #include <string.h>

// #define MAXN 510

// char A[MAXN], B[MAXN];
// int a[MAXN], b[MAXN], c[MAXN];

// int main()
// {
//     scanf("%s", A);
//     scanf("%s", B);

//     int len_A = strlen(A);
//     int len_B = strlen(B);
//     int len_max = (len_A > len_B) ? len_A : len_B;

//     for (int i = len_A - 1, j = 1; i >= 0; i--, j++)
//     {
//         a[j] = A[i] - '0';
//     }
//     for (int i = len_B - 1, j = 1; i >= 0; i--, j++)
//     {
//         b[j] = B[i] - '0';
//     }

//     for (int i = 1; i <= len_max; i++)
//     {
//         c[i] += a[i] + b[i];
//         c[i + 1] = c[i] / 10;
//         c[i] %= 10;
//     }

//     if (c[len_max + 1])
//     {
//         len_max++;
//     }
//     for (int i = len_max; i >= 1; i--)
//     {
//         printf("%d", c[i]);
//     }

//     return 0;
// }