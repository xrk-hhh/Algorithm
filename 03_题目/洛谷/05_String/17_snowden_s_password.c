// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct 
// {
//     char *word;
//     int num;
// } WordMap;

// WordMap maps[] = 
// {
//     {"zero", 0},
//     {"one", 1},
//     {"two", 2},
//     {"three", 3},
//     {"four", 4},
//     {"five", 5},
//     {"six", 6},
//     {"seven", 7},
//     {"eight", 8},
//     {"nine", 9},
//     {"ten", 10},
//     {"eleven", 11},
//     {"twelve", 12},
//     {"thirteen", 13},
//     {"fourteen", 14},
//     {"fifteen", 15},
//     {"sixteen", 16},
//     {"seventeen", 17},
//     {"eighteen", 18},
//     {"nineteen", 19},
//     {"twenty", 20},

//     {"a", 1},
//     {"both", 2},
//     {"another", 1},
//     {"first", 1},
//     {"second", 2},
//     {"third", 3},

//     {NULL, 0}
// };

// int isSmaller(const char *str1, const char *str2) 
// {
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);

//     if (len1 < len2) 
//     {
//         return 1;
//     } 
//     else if (len1 > len2) 
//     {
//         return 0;
//     }

//     return strcmp(str1, str2) < 0 ? 1 : 0;
// }

// void permute(char arr[][3], int start, int end, char minStr[]) 
// {
//     if (start == end) 
//     {
//         char temp[20] = {0};
//         for (int i = 0; i <= end; i++) 
//         {
//             strcat(temp, arr[i]);
//         }

//         char processed[20] = {0};
//         int idx = 0;
//         while (idx < strlen(temp) && temp[idx] == '0') 
//         {
//             idx++;
//         }
//         if (idx == strlen(temp)) 
//         {
//             strcpy(processed, "0");
//         } 
//         else 
//         {
//             strcpy(processed, temp + idx);
//         }

//         if (isSmaller(processed, minStr)) 
//         {
//             strcpy(minStr, processed);
//         }
//         return;
//     }

//     for (int i = start; i <= end; i++) 
//     {
//         char temp[3] = {0};
//         strcpy(temp, arr[start]);
//         strcpy(arr[start], arr[i]);
//         strcpy(arr[i], temp);

//         permute(arr, start + 1, end, minStr);

//         strcpy(temp, arr[start]);
//         strcpy(arr[start], arr[i]);
//         strcpy(arr[i], temp);
//     }
// }

// int main() 
// {
//     char line[1001] = {0};
//     fgets(line, sizeof(line), stdin);

//     int lineLen = strlen(line);
//     if (line[lineLen - 1] == '\n') 
//     {
//         line[lineLen - 1] = '\0';
//     }

//     char *token = strtok(line, " ");
//     char words[6][100] = {0};
//     int wordCount = 0;
//     while (token != NULL && wordCount < 6) 
//     {
//         int len = strlen(token);
//         if (token[len - 1] == '.') 
//         {
//             token[len - 1] = '\0';
//         }
//         strcpy(words[wordCount], token);
//         wordCount++;
//         token = strtok(NULL, " ");
//     }

//     int nums[6] = {0};
//     int numCount = 0;
//     for (int i = 0; i < 6; i++) 
//     {
//         for (int j = 0; maps[j].word != NULL; j++) 
//         {
//             if (strcmp(words[i], maps[j].word) == 0) 
//             {
//                 nums[numCount] = maps[j].num;
//                 numCount++;
//                 break;
//             }
//         }
//     }

//     if (numCount == 0) 
//     {
//         printf("0\n");
//         return 0;
//     }

//     char twoDigits[6][3] = {0};
//     for (int i = 0; i < numCount; i++) 
//     {
//         long long square = (long long)nums[i] * nums[i];
//         int mod = square % 100;
//         sprintf(twoDigits[i], "%02d", mod);
//     }

//     char minStr[20] = "99999999999999999999";
//     permute(twoDigits, 0, numCount - 1, minStr);

//     printf("%s\n", minStr);

//     return 0;
// }