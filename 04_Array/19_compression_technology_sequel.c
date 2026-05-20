// #include <stdio.h>
// #include <string.h>

// #define MAX_MATRIX 40010
// #define MAX_CODES 20010

// char matrix[MAX_MATRIX];
// int codes[MAX_CODES];

// int main() 
// {
    
//     char line[210];
//     int idx = 0;
//     int N = 0;
//     int code_len = 0;

//     if (fgets(line, sizeof(line), stdin) == NULL) 
//     {
//         return 1;
//     }
//     line[strcspn(line, "\n")] = '\0';
//     N = strlen(line);
//     strcpy(matrix + idx, line);
//     idx += N;

//     for (int i = 1; i < N; i++) 
//     {
//         if (fgets(line, sizeof(line), stdin) == NULL) 
//         {
//             return 1;
//         }
//         line[strcspn(line, "\n")] = '\0';
//         strcpy(matrix + idx, line);
//         idx += strlen(line);
//     }

//     char current_char = matrix[0];
//     int count = 1;

//     if (current_char != '0') 
//     {
//         codes[code_len++] = 0;
//     }
    
//     for (int i = 1; i < idx; i++) 
//     {
//         if (matrix[i] == current_char) 
//         {
//             count++;
//         } 
//         else 
//         {
//             codes[code_len++] = count;
//             current_char = matrix[i];
//             count = 1;
//         }
//     }
//     codes[code_len++] = count;

//     printf("%d", N);
//     for (int i = 0; i < code_len; i++) 
//     {
//         printf(" %d", codes[i]);
//     }
//     printf("\n");

//     return 0;
// }