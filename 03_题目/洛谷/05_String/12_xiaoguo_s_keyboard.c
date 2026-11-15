// #include <stdio.h>
// #include <string.h>

// char s[110];

// int main() 
// {
//     int n;
    
//     scanf("%d %s", &n, s);

//     int original = 0;
//     for (int i = 0; i < n - 1; i++) 
//     {
//         if (s[i] == 'V' && s[i + 1] == 'K') 
//         {
//             original++;
//         }
//     }

//     int max_count = original;

//     for (int i = 0; i < n; i++) 
//     {
//         char c = s[i];
     
//         int prev_old = 0, next_old = 0;
//         if (i > 0) 
//         {
//             prev_old = (s[i - 1] == 'V' && s[i] == 'K') ? 1 : 0;
//         }
//         if (i < n - 1) 
//         {
//             next_old = (s[i] == 'V' && s[i + 1] == 'K') ? 1 : 0;
//         }
//         int old = prev_old + next_old;

//         s[i] = (c == 'V') ? 'K' : 'V';

//         int prev_new = 0, next_new = 0;
//         if (i > 0) 
//         {
//             prev_new = (s[i - 1] == 'V' && s[i] == 'K') ? 1 : 0;
//         }
//         if (i < n - 1) 
//         {
//             next_new = (s[i] == 'V' && s[i + 1] == 'K') ? 1 : 0;
//         }
//         int new_val = prev_new + next_new;


//         int current = original + (new_val - old);
//         if (current > max_count) 
//         {
//             max_count = current;
//         }

//         s[i] = c;
//     }

//     printf("%d\n", max_count);
//     return 0;
// }