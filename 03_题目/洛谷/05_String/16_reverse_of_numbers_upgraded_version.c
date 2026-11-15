// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// char* reverse_str(const char* s) 
// {
//     int len = strlen(s);
//     char* res = (char*)malloc(len + 1);
//     for (int i = 0; i < len; i++) 
//     {
//         res[i] = s[len - 1 - i];
//     }
//     res[len] = '\0';
//     return res;
// }

// char* process_int_part(char* s) 
// {
//     int len = strlen(s);
//     int start = 0;
    
//     while (start < len && s[start] == '0') 
//     {
//         start++;
//     }
    
//     if (start == len) 
//     {
//         free(s);
//         char* zero = (char*)malloc(2);
//         zero[0] = '0';
//         zero[1] = '\0';
//         return zero;
//     }
    
//     int res_len = len - start;
//     char* res = (char*)malloc(res_len + 1);
//     strncpy(res, s + start, res_len);
//     res[res_len] = '\0';
//     free(s);
//     return res;
// }

// char* process_dec_part(char* s) 
// {
//     int len = strlen(s);
//     int end = len - 1;

//     while (end >= 0 && s[end] == '0') 
//     {
//         end--;
//     }
    
//     if (end < 0) 
//     {
//         free(s);
//         char* zero = (char*)malloc(2);
//         zero[0] = '0';
//         zero[1] = '\0';
//         return zero;
//     }

//     int res_len = end + 1;
//     char* res = (char*)malloc(res_len + 1);
//     strncpy(res, s, res_len);
//     res[res_len] = '\0';
//     free(s);
//     return res;
// }

// int main() 
// {
//     char input[256];
//     scanf("%s", input);
//     int len = strlen(input);

//     if (input[len - 1] == '%') 
//     {
//         char num_part[256];
//         strncpy(num_part, input, len - 1);
//         num_part[len - 1] = '\0';

//         char* reversed = reverse_str(num_part);
//         char* processed = process_int_part(reversed);

//         printf("%s%%\n", processed);
//         free(processed);
//     }
//     else if (strchr(input, '/') != NULL) 
//     {
//         char* slash = strchr(input, '/');
//         int num_len = slash - input;
//         int den_len = len - num_len - 1;

//         char numerator[256], denominator[256];
//         strncpy(numerator, input, num_len);
//         numerator[num_len] = '\0';
//         strncpy(denominator, slash + 1, den_len);
//         denominator[den_len] = '\0';

//         char* rev_num = reverse_str(numerator);
//         char* proc_num = process_int_part(rev_num);

//         char* rev_den = reverse_str(denominator);
//         char* proc_den = process_int_part(rev_den);

//         printf("%s/%s\n", proc_num, proc_den);
//         free(proc_num);
//         free(proc_den);
//     }
//     else if (strchr(input, '.') != NULL) 
//     {
//         char* dot = strchr(input, '.');
//         int int_len = dot - input;
//         int dec_len = len - int_len - 1;
        
//         char integer[256], decimal[256];
//         strncpy(integer, input, int_len);
//         integer[int_len] = '\0';
//         strncpy(decimal, dot + 1, dec_len);
//         decimal[dec_len] = '\0';
        
//         char* rev_int = reverse_str(integer);
//         char* proc_int = process_int_part(rev_int);
        
//         char* rev_dec = reverse_str(decimal);
//         char* proc_dec = process_dec_part(rev_dec);

//         printf("%s.%s\n", proc_int, proc_dec);
//         free(proc_int);
//         free(proc_dec);
//     }
//     else 
//     {

//         char* reversed = reverse_str(input);
//         char* processed = process_int_part(reversed);

//         printf("%s\n", processed);
//         free(processed);
//     }

//     return 0;
// }