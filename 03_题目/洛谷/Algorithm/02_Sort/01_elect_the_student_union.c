// // #include <stdio.h>
// // #include <stdlib.h>

// // #define M 2000010

// // int cmp(const void* a, const void* b)
// // {
// //     return *(int*)a - *(int*)b;
// // }

// // int ballot[M];

// // int main()
// // {
// //     int n, m;
// //     scanf("%d %d", &n, &m);

// //     for (int i = 0; i < m; i++)
// //     {
// //         scanf("%d", &ballot[i]);
// //     }

// //     qsort(ballot, m, sizeof(int), cmp);

// //     printf("%d", ballot[0]);
// //     for (int i = 1; i < m; i++)
// //     {
// //         printf(" %d", ballot[i]);
// //     }

// //     printf("\n");

// //     return 0;
// // }

// // 以上为快排，时间复杂度为 nlogn

// //考虑本题需排序数据均为非负整数，且值域小（1~999），故可考虑计数排序

// #include <stdio.h>

// #define N 1010

// int cnt[N];

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);

//     for (int i = 0; i < m; i++)
//     {
//         int tmp;
//         scanf("%d", &tmp);
//         cnt[tmp]++;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= cnt[i]; j++)
//         {
//             printf("%d ", i);
//         }
//     }

//     return 0;
// }