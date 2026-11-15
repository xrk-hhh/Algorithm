// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     /*
//         需求：判断字符串是否为回文
//         题目描述：
//         输入一个字符串，输出该字符串是否回文。回文是指顺读和倒读都一样的字符串。

//         输入格式：
//         输入一行字符串，长度小于 100。

//         输出格式：
//         如果字符串是回文，输出 yes；否则，输出 no。
//     */

//     char str[100];
//     scanf("%s",str);

//     int len_str = strlen(str);
//     // 判断是否回文，初始化标记为1
//     int is_palindrome = 1;
//     // 只需循环到中间位置
//     for (int i = 0; i < len_str / 2; i++)
//     {
//         // 判断索引 i 与索引 len_str - 1 - i 是否相同
//         // 注意：索引 len_str - i 为 '\0'
//         if (str[i] != str[len_str - 1 - i])
//         {
//             // 发现不相等，标记为非回文
//             is_palindrome = 0;
//             // 直接跳出循环，无需继续比较
//             break;
//         }
//     }

//     if (is_palindrome)
//     {
//         printf("yes");
//     }
//     else
//     {
//         printf("no");
//     }
    
//     return 0;
// }