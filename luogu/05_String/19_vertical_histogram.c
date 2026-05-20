// #include <stdio.h>
// #include <string.h>

// int cnt[30];

// int main()
// {
//     int t = 4;
//     int maxx = 0;
//     while (t--)
//     {
//         char str[100];
//         fgets(str, sizeof(str), stdin);

//         int len = strlen(str);
//         if (str[len - 1] == '\n')
//         {
//             str[len - 1] = '\0';
//             len--;
//         }
        
//         for (int i = 0; i < len; i++)
//         {
//             char c = str[i];
//             if (c >= 'A' && c <= 'Z')
//             {
//                 int idx = c - 'A';
//                 cnt[idx]++;
//                 if (cnt[idx] > maxx)
//                 {
//                     maxx = cnt[idx];
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < maxx; i++)
//     {
//         for (int j = 0; j < 26; j++)
//         {
//             if (cnt[j] >= maxx - i)
//             {
//                 printf("*");
//             }
//             else
//             {
//                 printf(" ");
//             }
//             if (j != 25)
//             {
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
//     for (int i = 0; i < 26; i++)
//     {
//         char c = i + 'A';
//         printf("%c", c);
//         if (i != 25)
//         {
//             printf(" ");
//         }
//     }
//     printf("\n");

//     return 0;
// }