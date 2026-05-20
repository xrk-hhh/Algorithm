// #include <stdio.h>

// #define MAX_N 20

// int isEqual(char a[MAX_N][MAX_N], char b[MAX_N][MAX_N], int n) 
// {
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < n; j++) 
//         {
//             if (a[i][j] != b[i][j]) 
//             {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

// void rotate90(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < n; j++) 
//         {
//             res[j][n - 1 - i] = original[i][j];
//         }
//     }
// }

// void rotate180(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < n; j++) 
//         {
//             res[n - 1 - i][n - 1 - j] = original[i][j];
//         }
//     }
// }

// void rotate270(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < n; j++) 
//         {
//             res[n - 1 - j][i] = original[i][j];
//         }
//     }
// }

// void reflect(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     for (int i = 0; i < n; i++) 
//     {
//         for (int j = 0; j < n; j++) 
//         {
//             res[i][n - 1 - j] = original[i][j];
//         }
//     }
// }

// void combo90(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     char ref[MAX_N][MAX_N];
//     reflect(original, ref, n);
//     rotate90(ref, res, n);
// }

// void combo180(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     char ref[MAX_N][MAX_N];
//     reflect(original, ref, n);
//     rotate180(ref, res, n);
// }

// void combo270(char original[MAX_N][MAX_N], char res[MAX_N][MAX_N], int n) 
// {
//     char ref[MAX_N][MAX_N];
//     reflect(original, ref, n);
//     rotate270(ref, res, n);
// }

// char original[MAX_N][MAX_N];
// char target[MAX_N][MAX_N];
// char temp[MAX_N][MAX_N];

// int main() 
// {
//     int n;
//     scanf("%d", &n);
    
//     for (int i = 0; i < n; i++) 
//     {
//         scanf("%s", original[i]);
//     }
//     for (int i = 0; i < n; i++) 
//     {
//         scanf("%s", target[i]);
//     }

//     rotate90(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("1\n");
//         return 0;
//     }

//     rotate180(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("2\n");
//         return 0;
//     }

//     rotate270(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("3\n");
//         return 0;
//     }

//     reflect(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("4\n");
//         return 0;
//     }

//     combo90(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("5\n");
//         return 0;
//     }
//     combo180(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("5\n");
//         return 0;
//     }
//     combo270(original, temp, n);
//     if (isEqual(temp, target, n)) 
//     {
//         printf("5\n");
//         return 0;
//     }

//     if (isEqual(original, target, n)) 
//     {
//         printf("6\n");
//         return 0;
//     }

//     printf("7\n");
//     return 0;
// }