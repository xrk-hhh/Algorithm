// #include <stdio.h>
// #include <math.h>

// #define MAXN 100010

// int is_prime(int x)
// {
//     if (x == 1)
//     {
//         return 0;
//     }
//     if (x == 2)
//     {
//         return 1;
//     }
//     if ((x & 1) == 0)
//     {
//         return 0;
//     }
//     int y = sqrt(x);
//     for (int i = 3; i <= y; i++)
//     {
//         if (x % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// int a[MAXN];
// int b[MAXN];

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int k = 0;
//     for(int j = 0; j < n; j++)
//     {
//         scanf("%d", &a[j]);
//         if (is_prime(a[j]))
//         {
//             b[k++] = a[j];
//         }
//     }

//     if (k > 0)
//     {
//         printf("%d", b[0]);
//         for (int j = 1; j < k; j++)
//         {
//             printf(" %d", b[j]);
//         }
//     }
    
//     return 0;
// }