// // #include <stdio.h>

// // int a[1024][1024];

// // void divide(int x, int y, int s) 
// // {
// //     if (s == 1) 
// //     {
// //         return;
// //     }
// //     int half = s / 2;

// //     for (int i = x; i < x + half; i++) 
// //     {
// //         for (int j = y; j < y + half; j++) 
// //         {
// //             a[i][j] = 0;
// //         }
// //     }

// //     divide(x, y + half, half);
// //     divide(x + half, y, half);
// //     divide(x + half, y + half, half);
// // }

// // int main() 
// // {
// //     int n;
// //     scanf("%d", &n);

// //     int x = 1 << n;

// //     for (int i = 0; i < x; i++) 
// //     {
// //         for (int j = 0; j < x; j++) 
// //         {
// //             a[i][j] = 1;
// //         }
// //     }

// //     divide(0, 0, x);

// //     for (int i = 0; i < x; i++) 
// //     {
// //         printf("%d", a[i][0]);
// //         for (int j = 1; j < x; j++) 
// //         {
// //             printf(" %d", a[i][j]);
// //         }
// //         printf("\n");
// //     }

// //     return 0;
// // }


// //以上为手动赋值+分治递归


// //以下为通过位运算技巧和一维字符数组直接构造结果


// #include <stdio.h>
// #include <string.h>

// char row[2050];

// int main()
// {
//     int n;
//     scanf("%d", &n);
    
//     memset(row, ' ', 2<<n);
    
//     n=(1 << n) - 1;
//     for(int i = 0; i<=n; i++)
//     {
//     	for(int j = 0;j <= n; j++)
//     	{
//     		row[j << 1] = '0' + ((i | j) == n);
// 		}
// 		printf("%s\n", row);
// 	}
    
// 	return 0;
// }