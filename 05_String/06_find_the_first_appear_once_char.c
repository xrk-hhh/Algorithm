// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     /*
//         需求：找第一个只出现一次的字符
//         题目描述:
//         给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出 no。

//         输入格式:
//         一个字符串，长度小于 1100。

//         输出格式:
//         输出第一个仅出现一次的字符，若没有则输出 no。
//     */

//     char str[1100];
//     scanf("%s",str);

//     // 计数数组：统计每个字符出现次数（0=a,1=b,...25=z）
//     int count[26] = {0};
//     int len = strlen(str);

//     // 第一步：统计所有字符的出现次数
//     for (int i = 0; i < len; i++) 
//     {
//         count[str[i] - 'a']++;  // 直接计数，无冗余判断
//     }

//     // 第二步：按字符串原始顺序遍历，找第一个出现次数为1的字符
//     int found = 0;
//     for (int i = 0; i < len; i++) 
//     {
//         if (count[str[i] - 'a'] == 1) 
//         {
//             printf("%c\n", str[i]);
//             found = 1;
//             break;
//         }
//     }

//     // 没有找到则输出no
//     if (!found) 
//     {
//         printf("no\n");
//     }

//     return 0;
// }