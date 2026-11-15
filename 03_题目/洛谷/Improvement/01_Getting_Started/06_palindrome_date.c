// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int is_leap(int year);
// int is_valid_date(int year, int month, int day);
// int generate_palindrome(int year);

// int main()
// {
//     /*
//         需求：回文日期
//         题目描述：
//         在日常生活中，通过年、月、日这三个要素可以表示出一个唯一确定的日期。

//         牛牛习惯用 8 位数字表示一个日期，其中，前 4 位代表年份，接下来 2 位代表月份，最后 2 位代表日期。
//         显然：一个日期只有一种表示方法，而两个不同的日期的表示方法不会相同。

//         牛牛认为，一个日期是回文的，当且仅当表示这个日期的 8 位数字是回文的。
//         现在，牛牛想知道：在他指定的两个日期之间（包含这两个日期本身），有多少个真实存在的日期是回文的。

//         一个 8 位数字是回文的，当且仅当对于所有的 i（1≤i≤8）从左向右数的第 i 个数字和第 9−i 个数字（即从右向左数的第 i 个数字）是相同的。

//         例如：

//         对于 2016 年 11 月 19 日，用 8 位数字 20161119 表示，它不是回文的。
//         对于 2010 年 1 月 2 日，用 8 位数字 20100102 表示，它是回文的。
//         对于 2010 年 10 月 2 日，用 8 位数字 20101002 表示，它不是回文的。
//         每一年中都有 12 个月份：

//         其中，1,3,5,7,8,10,12 月每个月有 31 天；4,6,9,11 月每个月有 30 天；而对于 2 月，闰年时有 29 天，平年时有 28 天。

//         一个年份是闰年当且仅当它满足下列两种情况其中的一种：
//         这个年份是 4 的整数倍，但不是 100 的整数倍；
//         这个年份是 400 的整数倍。

//         例如：
//         以下几个年份都是闰年：2000,2012,2016。
//         以下几个年份是平年：1900,2011,2014。

//         输入格式：
//         两行，每行包括一个 8 位数字。
//         第一行表示牛牛指定的起始日期。
//         第二行表示牛牛指定的终止日期。

//         保证 date1和 date2都是真实存在的日期，且年份部分一定为 4 位数字，且首位数字不为 0。
//         保证 date1 一定不晚于 date2。

//         输出格式：
//         一个整数，表示在 date1 和 date2 之间，有多少个日期是回文的。

//         说明/提示：
//         【子任务】
//         对于 60% 的数据，满足 date1 = date2。

//     */

//     int date1, date2;
//     scanf("%d %d",&date1,&date2);

//     int count = 0;
//     // 遍历年份范围：从date1的年份到date2的年份
//     int start_year = date1 / 10000;
//     int end_year = date2 / 10000;
    
//     for (int year = start_year; year <= end_year; year++) 
//     {
//         // 生成当前年份对应的回文日期
//         int palindrome_date = generate_palindrome(year);
        
//         // 跳过超出区间的回文日期
//         if (palindrome_date < date1 || palindrome_date > date2) 
//         {
//             continue;
//         }
        
//         // 拆分回文日期的年、月、日
//         int month = (palindrome_date / 100) % 100;
//         int day = palindrome_date % 100;
        
//         // 验证日期合法性，合法则计数+1
//         if (is_valid_date(year, month, day)) 
//         {
//             count++;
//         }
//     }
    
//     printf("%d\n", count);

//     return 0;
// }
// // 判断是否为闰年
// int is_leap(int year) 
// {
//     return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
// }
// // 判断日期是否合法（年、月、日有效）
// int is_valid_date(int year, int month, int day) 
// {
//     // 月份必须在1-12之间
//     if (month < 1 || month > 12)
//     {
//         return 0;
//     } 
    
//     // 每个月的天数（平年2月28天）
//     int days_of_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
//     // 闰年2月补1天
//     if (month == 2 && is_leap(year)) 
//     {
//         days_of_month[2] = 29;
//     }
    
//     // 日期必须在当月天数范围内
//     return day >= 1 && day <= days_of_month[month];
// }
// // 由年份生成对应的8位回文日期（如2010→20100102）
// int generate_palindrome(int year) 
// {
//     char year_str[5], reversed_str[5];
//     // 将年份转为4位字符串（不足补前导0）
//     sprintf(year_str, "%04d", year);
    
//     // 反转年份字符串得到月日部分（如"2010"→"0102"）
//     reversed_str[0] = year_str[3];
//     reversed_str[1] = year_str[2];
//     reversed_str[2] = year_str[1];
//     reversed_str[3] = year_str[0];
//     reversed_str[4] = '\0';
    
//     // 组合成8位回文日期（年份*10000 + 反转后的月日）
//     int month_day = atoi(reversed_str);
//     return year * 10000 + month_day;
// }
