// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main()
// {
//     /*
//         需求：口算练习题
//         题目描述：
//         王老师正在教简单算术运算。
//         细心的王老师收集了 i 道学生经常做错的口算题，并且想整理编写成一份练习。
//         编排这些题目是一件繁琐的事情，为此他想用计算机程序来提高工作效率。
//         王老师希望尽量减少输入的工作量，比如 5+8 的算式最好只要输入 5 和 8，输出的结果要尽量详细以方便后期排版的使用，
//         比如对于上述输入进行处理后输出 5+8=13 以及该算式的总长度 6。王老师把这个光荣的任务交给你，请你帮他编程实现以上功能。

//         输入格式：
//         第一行一个整数 i。

//         接着的 i 行为需要输入的算式，每行可能有三个数据或两个数据。

//         若该行为三个数据则第一个数据表示运算类型，a 表示加法运算，b 表示减法运算，c 表示乘法运算，接着的两个数据表示参加运算的运算数。

//         若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。

//         输出格式：
//         输出 2×i 行。对于每个输入的算式，输出完整的运算式及结果，第二行输出该运算式的总长度。

//         说明/提示：
//         【数据规模与约定】
//         对于 50% 的数据，输入的算式都有三个数据。

//         对于所有数据，0<i≤50，第一个算式一定有三个数据，运算数为非负整数且小于 10000。
//     */

//     int i;
//     scanf("%d",&i);
//     getchar(); // 吸收输入i后的换行符，避免干扰后续读取


//     char last_op = 0; // 初始化，避免未定义行为
//     char line[100];
//     int num1, num2, result;
//     char op_char;
//     char formula[100];

//     for (int k = 0; k < i; k++) 
//     {
//         // 读取一行输入（确保读取成功）
//         if (fgets(line, sizeof(line), stdin) == NULL) 
//         {
//             break; // 输入异常时退出
//         }
//         // 去除换行符（用'\0'更清晰）
//         line[strcspn(line, "\n")] = '\0';

//         // 跳过行首空白字符
//         int pos = 0;
//         while (isspace((unsigned char)line[pos])) 
//         { // 强制转换避免负数ASCII问题
//             pos++;
//         }

//         // 解析输入：第一行必须包含运算类型
//         if (line[pos] == 'a' || line[pos] == 'b' || line[pos] == 'c') 
//         {
//             sscanf(line + pos, "%c %d %d", &last_op, &num1, &num2);
//         } 
//         else 
//         {
//             // 非第一行且无运算类型时，继承上一个
//             if (last_op == 0) 
//             {
//                 printf("错误：第一行必须指定运算类型（a/b/c）\n");
//                 return 1;
//             }
//             sscanf(line + pos, "%d %d", &num1, &num2);
//         }

//         // 计算结果并确定运算符
//         switch (last_op) 
//         {
//             case 'a':
//                 result = num1 + num2;
//                 op_char = '+';
//                 break;
//             case 'b':
//                 result = num1 - num2;
//                 op_char = '-';
//                 break;
//             case 'c':
//                 result = num1 * num2;
//                 op_char = '*';
//                 break;
//             default:
//                 printf("错误：无效的运算类型\n");
//                 return 1;
//         }

//         // 构造算式并输出
//         sprintf(formula, "%d%c%d=%d", num1, op_char, num2, result);
//         printf("%s\n", formula);
//         printf("%zu\n", strlen(formula)); // 用%zu匹配size_t类型
//     }
//     return 0;
// }
// /*
// 注：scanf的返回值是成功读取的输入项数量
//     read_cnt的值为实际成功读取的数量（甚至可能返回EOF，即-1，表示输入结束）。

//     格式串中的空格（如" %c"中的空格）会自动跳过输入中的空白字符（包括换行、空格、制表符等）。
//     这确保了%c能正确读取到运算类型，而不会误读为前一行输入的换行符（比如第一行输入i后残留的换行符）。
// */


                