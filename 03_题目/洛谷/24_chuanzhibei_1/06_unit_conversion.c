// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

// int unit_to_weight(char *unit);

// int main()
// {
//     /*
//         需求：单位转换
//         题目描述：
//         我们知道计算机的大小单位有 B, KB, MB 等，现在请你编写一个计算器进行大小单位换算。

//         提示，1 GB = 2^10 MB = 2^20 KB = 2^30 B。

//         输入格式：
//         输入一个字符串，由一个 0 到 1023 之间的整数，一个单位名称（大写字母），一个等于号和问号，以及第二个单位名称。

//         单位只有可能是 GB,MB,KB,B 之间的一个。

//         输出格式：
//         输出一个数字，精确到小数点后 6 位。
//     */

//     // // 方法一：暴力模拟
//     // // 判断 源单位 和 目标单位，进而算出结果
//     // char str[12];
//     // scanf("%s", str);

//     // // 用 atoi 函数提取字符串中 源数字 
//     // // 将以数字开头的字符串（可含正负号、前导空格）转换为 int 类型整数
//     // int num_start = atoi(str);
//     // // 目标数字
//     // double num_end = 0.000000;
//     // // 源单位索引
//     // int start = 0;
//     // // 目标单位索引
//     // int end;

//     // // 先用'='确定 源单位索引
//     // while (str[start] != '=')
//     // {
//     //     start++;
//     // }

//     // // 再进一步推出 目标单位索引
//     // if (str[start - 2] == 'G' || str[start - 2] == 'M' || str[start - 2] == 'K')
//     // {
//     //     start -= 2;
//     //     end = start + 4;
//     // }
//     // else
//     // {
//     //     start--;
//     //     end = start + 3;
//     // }
//     // // 用 switch嵌套 源单位 和 目标单位
//     // switch (str[start])
//     // {
//     //     case 'G':
//     //         switch (str[end])
//     //         {
//     //             case 'G':
//     //                 num_end = num_start;
//     //                 break;
//     //             case 'M':
//     //                 num_end = num_start * pow(2,10);
//     //                 break;
//     //             case 'K':
//     //                 num_end = num_start * pow(2,20);
//     //                 break;
//     //             case 'B':
//     //                 num_end = num_start * pow(2,30);
//     //                 break;
//     //         }
//     //         break;
//     //     case 'M':
//     //         switch (str[end])
//     //         {
//     //             case 'G':
//     //                 num_end = num_start * pow(2,-10);
//     //                 break;
//     //             case 'M':
//     //                 num_end = num_start;
//     //             case 'K':
//     //                 num_end = num_start * pow(2,10);
//     //                 break;
//     //             case 'B':
//     //                 num_end = num_start * pow(2,20);
//     //                 break;
//     //         }
//     //         break;
//     //     case 'K':
//     //         switch (str[end])
//     //         {
//     //             case 'G':
//     //                 num_end = num_start * pow(2,-20);
//     //                 break;
//     //             case 'M':
//     //                 num_end = num_start * pow(2,-10);
//     //                 break;
//     //             case 'K':
//     //                 num_end = num_start;
//     //             case 'B':
//     //                 num_end = num_start * pow(2,10);
//     //                 break;
//     //         }
//     //         break;
//     //     case 'B':
//     //         switch (str[end])
//     //         {
//     //             case 'G':
//     //                 num_end = num_start * pow(2,-30);
//     //                 break;
//     //             case 'M':
//     //                 num_end = num_start * pow(2,-20);
//     //                 break;
//     //             case 'K':
//     //                 num_end = num_start * pow(2,-10);
//     //                 break;
//     //             case 'B':
//     //                 num_end = num_start;
//     //         }
//     //         break;
//     // }

//     // // 输出打印
//     // printf("%.6lf",num_end);
    
//     // 方法二：充分利用 string 函数

//     char str[20]; // 扩大数组容量，避免输入超长
//     scanf("%s", str); // 输入无空格，%s 可正确读取

//     // 1. 提取数字（num_start）：从开头到非数字字符结束
//     int num_start = atoi(str);

//     // 2. 定位 = 的位置
//     char *equal = strchr(str, '=');

//     // 3. 提取源单位（数字后到 = 前）
//     char src_unit[3] = {0}; // 单位最多2位，+1位'\0'
//     int src_start = 0;
//     // 找到数字的结束位置（src_start 指向第一个非数字字符）
//     while (str[src_start] >= '0' && str[src_start] <= '9') 
//     {
//         src_start++;
//     }
//     // 复制源单位（从数字结束到 = 前）
//     int src_len = equal - str - src_start; // 源单位长度（1或2）
//     strncpy(src_unit, str + src_start, src_len);
//     src_unit[src_len] = '\0'; // 确保字符串终止

//     // 4. 提取目标单位（? 后到字符串结束）
//     char dst_unit[3] = {0};
//     char *q_mark = strchr(str, '?');

//     // 复制目标单位（从 ? 后到结束）
//     strncpy(dst_unit, q_mark + 1, 2); // 最多2位
//     dst_unit[2] = '\0';

//     // 5. 单位权重换算
//     int src_w = unit_to_weight(src_unit);
//     int dst_w = unit_to_weight(dst_unit);
//     int power = 10 * (src_w - dst_w); // 权重差 × 10（因为1级=2^10）
//     double num_end = num_start * pow(2, power);

//     // 6. 精确到小数点后6位输出
//     printf("%.6lf\n", num_end);


//     return 0;
// }

// // 辅助函数：将单位转换为权重（B=0, KB=1, MB=2, GB=3）
// int unit_to_weight(char *unit) 
// {
//     if (strcmp(unit, "B") == 0) 
//     {
//         return 0;
//     }
//     if (strcmp(unit, "KB") == 0)
//     {
//         return 1;
//     } 
//     if (strcmp(unit, "MB") == 0)
//     {
//         return 2;
//     } 
//     if (strcmp(unit, "GB") == 0)
//     {
//         return 3;
//     } 

// }