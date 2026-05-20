// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     /*
//         需求：小智的疑惑
//         题目描述：
//         传智专修学院给了小智一个仅包含小写字母的字符串 s，
//         他想知道，里面出现了多少次子串 chuanzhi 呢。

//         我们称一个字符串 t 是 s 的子串，
//         当且仅当将 s 的开头若干个（可以为 0 个）连续字符和结尾若干个（可以为 0 个）连续字符删去后，剩下的字符串和 t 相同。
//         例如，我们称 ab 是 abc 的子串，但 ac 不是 abc 的子串。

//         输入格式：
//         输入只有一行一个字符串，表示字符串 s。

//         输出格式：
//         输出一行一个整数表示答案。

//         说明/提示：
//         数据规模与约定
//         对于全部的测试点，保证 1≤∣s∣≤4×10^5，∣s∣ 表示 s 的长度，且 s 中只有小写字母。
//     */

//     char s[400001];
//     scanf("%s",s);

//     // 无需指定长度，自动计算（含'\0'）
//     char target[] = "chuanzhi";
//     int len_target = strlen(target);
//     int len_article = strlen(s);
//     int count = 0;

//     // 外层循环：i最多到 len_article - len_target，避免越界
//     for (int i = 0; i <= len_article - len_target;i++)
//     {
//         // 标记是否完全匹配（1=匹配，0=不匹配）
//         int match = 1;
//         // 内层循环：逐字符比较子串
//         for (int k = 0; k < len_target; k++)
//         {
//             if (s[i + k] != target[k])
//             {
//                 match = 0;
//                 // 不匹配，直接退出内层循环
//                 break;
//             }
//         }
//         // 只有完全匹配时，计数才+1
//         if (match)
//         {
//             count++;
//             // 匹配成功，跳过当前子串（避免重复匹配，提升效率）
//             i += len_target - 1;
//             // 配合循环i++，总共跳过 len_target 位
//         }
//     }

//     printf("%d",count);

//     return 0;
// }