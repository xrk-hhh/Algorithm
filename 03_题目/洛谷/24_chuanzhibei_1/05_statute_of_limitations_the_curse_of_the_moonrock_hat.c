// #include <stdio.h>
// #include <string.h>

// void get_decimal_part(char *s, char *decimal);

// int main()
// {
//     /*
//         需求： 时效「月岩笠的诅咒」
//         题目背景：
//         蓬莱之药，被诅咒的不死之药。
//         奉命将蓬莱之药投入富士山中销毁的月岩笠，最终打算把蓬莱之药改投入八岳销毁。在下山途中妹红将其踹下山，抢到了蓬莱之药。
//         那已经是千年前的事情了。

//         题目描述：
//         时间节点上发生过的两件事情的时间可被看作两实数 a,b。
//         我们称两个事件满足「周年」关系，当且仅当可以通过执行以下两种操作（可以 0 次）使其相等：
//         将 a 加上 1，即 a←a+1；
//         将 b 加上 1，即 b←b+1。

//         现在给定实数 a,b，询问它们是否满足「周年」。

//         输入格式：
//         输入共一行两个实数 a,b。输入保留到小数点后 12 位。

//         输出格式：
//         输出共一行。如果存在合法方案，输出 YES，否则输出 NO。

//         说明/提示：
//         对于全部数据，保证 0<a,b≤10^9。
//     */

//     // 关键：以字符串形式读取输入，避免double精度丢失

//     char a_str[30], b_str[30];
//     char a_dec[13], b_dec[13];

//     scanf("%s %s", a_str, b_str);

//     // 提取两者的12位小数部分
//     get_decimal_part(a_str, a_dec);
//     get_decimal_part(b_str, b_dec);

//     // 比较小数部分是否完全相等
//     if (strcmp(a_dec, b_dec) == 0) 
//     {
//         printf("YES\n");
//     } 
//     else 
//     {
//         printf("NO\n");
//     }

//     return 0;
// }

// // 提取字符串s的小数部分，补0到12位，存入decimal（长度13，含'\0'）
// void get_decimal_part(char *s, char *decimal) 
// {
//     char *dot = strchr(s, '.'); // 查找小数点位置
//     if (dot == NULL) 
//     {
//         // 无小数点，小数部分为12个0
//         strcpy(decimal, "000000000000");
//         return;
//     }
//     // 有小数点，提取后12位（不足补0，超出截短）
//     dot++; // 跳过小数点
//     int len = strlen(dot);
//     for (int i = 0; i < 12; i++) 
//     {
//         decimal[i] = (i < len) ? dot[i] : '0';
//     }
//     decimal[12] = '\0'; // 字符串终止符
// }