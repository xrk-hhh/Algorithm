// #include <stdio.h>

// #define N 3010

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);
//     static int a[N];
//     static int pre[N];
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", &a[i]);
//         if (i > 0)
//         {
//             pre[i] = pre[i - 1] + a[i];
//         }
//         else
//         {
//             pre[i] = a[i];
//         }
//     }

//     int l = 0;
//     int r = m - 1;
//     long long sum = pre[r];
//     while (r < n - 1)
//     {
//         l++;
//         r++;
//         if (pre[r] - pre[l - 1] < sum)
//         {
//             sum = pre[r] - pre[l - 1];
//         }
//     }
//     printf("%lld", sum);

//     return 0;
// }