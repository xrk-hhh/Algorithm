// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define MAX_LINES 10005    // 最大支持的文本行数（匹配题目数据范围）
// #define MAX_LINE_LEN 100010 // 每行最大字符数（满足题目总字符数≤1e5的限制）

// char* process_backspace(const char* raw_line);
// int read_text_until_eof(char** lines, int max_lines);
// int count_correct_chars(char** fanwen_lines, int fanwen_count, char** input_lines, int input_count);

// int main()
// {
//     /*
//         需求：打字练习
//         题目描述：
//         R 君在练习打字。
//         有这样一个打字练习网站，给定一个范文和输入框，会根据你的输入计算准确率和打字速度。
//         可以输入的字符有小写字母、空格和 .（英文句号），输入字符后，光标也会跟着移动。

//         输入的文本有多行，R 君可以通过换行键来换行，换行后光标移动到下一行的开头。

//         R 君也可以按退格键（为了方便，退格键用 < 表示），以删除上一个打的字符，并将光标回移一格。
//         特殊的，如果此时光标已经在一行的开头，则不能继续退格（即忽略此时输入的退格键）。

//         网站的比较方式遵循以下两个原则：
//         逐行比较，即对于范文和输入的每一行依次比较，不同行之间不会产生影响，多余的行会被忽略。
//         逐位比较，即对于两行的每一个字符依次比较，当且仅当字符相同时才会被算作一次正确，否则会被算作错误。计算答案时，只统计相同的字符个数。
//         需要注意的是，回车键不会被计入正确的字符个数。

//         R 君看到网站上显示他花了 T 秒完成了这次的打字游戏，
//         请你计算出他的 KPM（Keys per minutes，每分钟输入的字符个数），答案四舍五入保留整数部分。

//         输入格式：
//         R 君会依次告诉你网站的范文，他的输入和花费的时间。

//         其中范文和输入将会这样读入：给定若干行字符串，以单独的一行 EOF 结束，其中 EOF 不算入输入的文本。
//         最后一行一个整数 T，表示他打字花费了 T 秒。

//         输出格式：
//         一行一个整数，表示 KPM。

//         说明/提示：
//         数据范围
//         对于 20% 的数据，不存在换行键。
//         对于 40% 的数据，不存在退格键。
//         对于 100% 的数据，T≤10^3，保证每个文本段的总字符数（包括换行）不超过 10^5个且总行数不超过 10^4。
//     */

//     // 1. 定义存储范文和输入的数组（动态分配每行内容）
//     char* fanwen_lines[MAX_LINES] = {NULL};
//     char* input_lines[MAX_LINES] = {NULL};
    
//     // 2. 读取范文（自动处理退格）
//     int fanwen_count = read_text_until_eof(fanwen_lines, MAX_LINES);
    
//     // 3. 读取输入（自动处理退格）
//     int input_count = read_text_until_eof(input_lines, MAX_LINES);
    
//     // 4. 读取花费时间
//     int cost_time;
//     scanf("%d", &cost_time);
    
//     // 5. 统计正确字符数
//     int correct_count = count_correct_chars(fanwen_lines, fanwen_count, input_lines, input_count);
    
//     // 6. 计算KPM（四舍五入）
//     int kpm_result = (int)((correct_count * 60.0 / cost_time) + 0.5);
//     printf("%d\n", kpm_result);
    
//     // 7. 释放动态分配的内存（避免泄漏）
//     for (int i = 0; i < fanwen_count; i++) 
//     {
//         free(fanwen_lines[i]);
//     }
//     for (int i = 0; i < input_count; i++) 
//     {
//         free(input_lines[i]);
//     }

//     return 0;
// }
// /*
//     @brief 处理字符串中的退格符（<），返回处理后的动态字符串
//     @param raw_line 原始输入行（含退格符）
//     @return 处理后的字符串（需手动free释放）
// */
// char* process_backspace(const char* raw_line) 
// {
//     int raw_len = strlen(raw_line);
//     // 分配足够内存存储处理后的字符串（最长与原字符串一致）
//     char* processed_line = (char*)malloc(raw_len + 1);
    
//     int valid_index = 0; // 记录处理后有效字符的位置
//     for (int i = 0; i < raw_len; i++) 
//     {
//         if (raw_line[i] == '<') 
//         { 
//             // 遇到退格符
//             if (valid_index > 0) 
//             { 
//                 // 非行首，回退一个字符
//                 valid_index--;
//             }
//             // 行首则忽略退格（valid_index保持0）
//         } 
//         else 
//         { 
//             // 普通字符，直接保留
//             processed_line[valid_index++] = raw_line[i];
//         }
//     }
//     processed_line[valid_index] = '\0'; // 截断字符串
    
//     return processed_line;
// }

// /*
//     @brief 读取文本直到EOF行，自动处理退格并填充字符串数组
//     @param lines 存储文本行的指针数组（需提前初始化）
//     @param max_lines 数组最大容量（防止越界）
//     @return 实际读取的行数（不含EOF行）
// */
// int read_text_until_eof(char** lines, int max_lines) 
// {
//     char temp_line[MAX_LINE_LEN]; // 临时缓冲区
//     int line_count = 0;           // 已读取的有效行数
    
//     while (1) 
//     {
//         // 读取一行（含空格/换行，遇EOF则终止）
//         if (fgets(temp_line, MAX_LINE_LEN, stdin) == NULL)
//         {
//             break;
//         } 
        
//         // 去除fgets读取的末尾换行符
//         char* newline_pos = strchr(temp_line, '\n');
//         if (newline_pos != NULL) 
//         {
//             *newline_pos = '\0';
//         }
        
//         // 遇到EOF行，终止读取
//         if (strcmp(temp_line, "EOF") == 0) 
//         {
//             break;
//         }
        
//         // 处理退格并存储到数组（防止数组越界）
//         if (line_count < max_lines) 
//         {
//             lines[line_count] = process_backspace(temp_line);
//             line_count++;
//         }
//     }
    
//     return line_count;
// }

// /*
//     @brief 统计范文与输入的匹配字符数
//     @param fanwen_lines 范文行数组
//     @param fanwen_count 范文行数
//     @param input_lines 输入行数组
//     @param input_count 输入行数
//     @return 匹配的字符总数
// */
// int count_correct_chars(char** fanwen_lines, int fanwen_count, char** input_lines, int input_count) 
// {
//     int correct_count = 0;
//     // 取较少的行数（多余行忽略）
//     int min_lines = (fanwen_count < input_count) ? fanwen_count : input_count;
    
//     for (int i = 0; i < min_lines; i++) 
//     {
//         int fw_len = strlen(fanwen_lines[i]);
//         int in_len = strlen(input_lines[i]);
//         // 取较短的字符长度（多余字符忽略）
//         int min_len = (fw_len < in_len) ? fw_len : in_len;
        
//         for (int j = 0; j < min_len; j++) 
//         {
//             if (fanwen_lines[i][j] == input_lines[i][j]) 
//             {
//                 correct_count++;
//             }
//         }
//     }
    
//     return correct_count;
// }