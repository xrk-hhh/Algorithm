// #include <stdio.h>
// #include <string.h>

// #define MAXN 5010

// char A[MAXN], B[MAXN];
// int a[MAXN], b[MAXN], c[MAXN];

// int main()
// {
//     scanf("%s", A);
//     scanf("%s", B);

//     int len_A = strlen(A);
//     int len_B = strlen(B);

//     for (int i = len_A - 1; i >= 0; i--)
//     {
//         a[len_A - i] = A[i] - '0';
//     }
//     for (int i = len_B - 1; i >= 0; i--)
//     {
//         b[len_B - i] = B[i] - '0';
//     }

//     for (int i = 1; i <= len_A; i++)
//     {
//         for (int j = 1; j <= len_B; j++)
//         {
//             c[i + j - 1] += a[i] * b[j];
//         } 
//     }

//     int len = len_A + len_B;
//     for (int i = 1; i <= len; i++)
//     {
//         c[i + 1] += c[i] / 10;
//         c[i] %= 10;
//     }

//     while (!c[len])
//     {
//         len--;
//     }
//     for (int i = (1 > len) ? 1 : len; i >= 1; i--)
//     {
//         printf("%d", c[i]);
//     }

//     return 0;
// }