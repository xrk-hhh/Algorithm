// #include <stdio.h>

// int b[30];

// int max(int x, int y)
// {
//     return x > y ? x : y;
// }

// int min(int x, int y)
// {
//     return x < y ? x : y;
// }

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);

//     double max_s = -1;
//     for (int i = 0; i < n; i++)
//     {
//         int maxx = -1;
//         int minn = 11;
//         int sum = 0;
//         for (int j = 0; j < m; j++)
//         {
//             scanf("%d", &b[j]);
//             sum += b[j];
//             maxx = max(b[j], maxx);
//             minn = min(b[j], minn);
//         }
//         double score =  1.0 * (sum - maxx - minn) / (m - 2);
//         max_s = score > max_s ? score : max_s;
//     }

//     printf("%.2f", max_s);
    
//     return 0;
// }