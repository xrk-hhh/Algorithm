// #include <stdio.h>

// int cnt[100];

// int main()
// {
//     int s1, s2, s3;
//     scanf("%d %d %d", &s1, &s2, &s3);

//     int sum = s1 + s2 + s3;
    
//     for (int i = 1; i <= s1; i++)
//     {
//         for (int j = 1; j <= s2; j++)
//         {
//             for (int k = 1; k <= s3; k++)
//             {
//                 int t = i + j + k;
//                 cnt[t]++;
//             }
//         }
//     }

//     int max = 0;
//     int ans = 0;
//     for (int i = 3; i <= sum; i++)
//     {
//         if (cnt[i] > max)
//         {
//             max = cnt[i];
//             ans = i;
//         }
//     }

//     printf("%d", ans);

//     return 0;
// }