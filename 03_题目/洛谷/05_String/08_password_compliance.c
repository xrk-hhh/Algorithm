// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     /*
//         需求：密码合规
//         题目描述：
//         网站注册需要有用户名和密码，编写程序以检查用户输入密码的有效性。合规的密码应满足以下要求 :。

//         只能由 a∼z 之间 26 个小写字母、A∼Z 之间 26 个大写字母、0∼9 之间 10 个数字以及 !@#$ 四个特殊字符构成。

//         密码最短长度 :6 个字符，密码最大长度 :12 个字符。

//         大写字母，小写字母和数字必须至少有其中两种，以及至少有四个特殊字符中的一个。

//         输入格式：
//         输入一行不含空格的字符串。约定长度不超过 100。该字符串被英文逗号分隔为多段，作为多组被检测密码。

//         输出格式：
//         输出若干行，每行输出一组合规的密码。输出顺序以输入先后为序，即先输入则先输出。

//         说明/提示：
//         【样例 1 解释】
//         输入被英文逗号分为了四组被检测密码：
//         seHJ12!@、sjdkffH$123、sdf!@&12HDHa!、123&^YUhg@!。
//         其中 sdf!@&12HDHa! 长度超过 12 个字符，不合规；
//         123&^YUhg@! 包含四个特殊字符之外的字符不合规。
//     */

//     char password[101];
//     // 步骤1：去除换行符（关键预处理）
//     fgets(password,101,stdin);
//     password[strcspn(password, "\n")] = '\0';

//     // 步骤2：用strtok按逗号分割密码（自动处理最后一组无逗号的情况）
//     char *p = strtok(password, ",");
//     while (p != NULL) 
//     {
//         int len = strlen(p);
//         // 条件1：长度6-12
//         if (len < 6 || len > 12) 
//         {
//             p = strtok(NULL, ",");
//             continue;
//         }

//         int has_lower = 0;  // 小写字母
//         int has_upper = 0;  // 大写字母
//         int has_digit = 0;  // 数字
//         int has_special = 0; // 特殊字符(!@#$)
//         int has_invalid = 0; // 非法字符

//         // 步骤3：遍历字符，检查合规性
//         for (int i = 0; i < len; i++) 
//         {
//             if (p[i] >= 'a' && p[i] <= 'z') 
//             {
//                 has_lower = 1;
//             } 
//             else if (p[i] >= 'A' && p[i] <= 'Z') 
//             {
//                 has_upper = 1;
//             } 
//             else if (p[i] >= '0' && p[i] <= '9') 
//             {
//                 has_digit = 1;
//             } 
//             else if (p[i] == '!' || p[i] == '@' || p[i] == '#' || p[i] == '$') 
//             {
//                 has_special = 1;
//             } 
//             else 
//             {
//                 has_invalid = 1; // 存在非法字符
//                 break;
//             }
//         }

//         // 条件2：无非法字符；条件3：特殊字符≥1；条件4：字母/数字类别≥2
//         int type_count = has_lower + has_upper + has_digit;
//         if (!has_invalid && has_special && type_count >= 2) 
//         {
//             printf("%s\n", p); // 输出合规密码
//         }

//         p = strtok(NULL, ","); // 处理下一组密码
//     }


//     return 0;
// }