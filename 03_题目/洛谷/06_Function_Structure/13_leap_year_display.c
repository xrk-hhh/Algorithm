// #include <stdio.h>

// #define MAXN 1500

// int is_leap_year(int n)
// {
//     if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
//     {
//         return 1;
//     }
//     return 0;
// }

// int l_y[MAXN];

// int main()
// {
//     int x, y;
//     scanf("%d %d", &x, &y);

//     int cnt = 0;
//     int k = 0;
//     for (int i = x; i <= y; i++)
//     {
//         if (is_leap_year(i))
//         {
//             cnt++;
//             l_y[k++] = i;
//         }
//     }

//     printf("%d\n", cnt);
//     if (k > 0)
//     {
//         printf("%d", l_y[0]);
//         for (int i = 1; i < k; i++)
//         {
//             printf(" %d", l_y[i]);
//         }
//     }
//     printf("\n");

//     return 0;
// }