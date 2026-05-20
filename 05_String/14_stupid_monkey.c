// #include <stdio.h>
// #include <string.h>
// #include <math.h>

// char str[110];
// int cnt[30];

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
//     for (int i = 3; i <= y; i += 2)
//     {
//         if (x % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     scanf("%s", str);

//     int len = strlen(str);

//     int maxn = 0;
//     int minn = 110;
//     for (int i = 0; i < len; i++)
//     {
//         int idx = str[i] - 'a';
//         cnt[idx]++;
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         if (cnt[i] == 0)
//         {
//             continue;
//         }
//         if (cnt[i] > maxn)
//         {
//             maxn = cnt[i];
//         }
//         if (cnt[i] < minn)
//         {
//             minn = cnt[i];
//         }
//     }
//     int dif = maxn - minn;
//     if (is_prime(dif))
//     {
//         printf("Lucky Word\n%d", dif);
//     }
//     else
//     {
//         printf("No Answer\n0");
//     }

//     return 0;
// }