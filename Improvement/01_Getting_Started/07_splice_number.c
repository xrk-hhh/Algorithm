// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int compare(const void *a, const void *b);

//  int main()
//  {
//     /*
//         需求：拼数
//         题目描述：
//         设有 n 个正整数 a1…an ，将它们联接成一排，相邻数字首尾相接，组成一个最大的整数。

//         输入格式：
//         第一行有一个整数，表示数字个数 n。

//         第二行有 n 个整数，表示给出的 n 个整数 ai。

//         输出格式：
//         一个正整数，表示最大的整数

//         说明/提示：
//         对于全部的测试点，保证 1≤n≤20，1≤ai≤10^9。
//     */

//     int n;
//     scanf("%d",&n);

//     // 存储每个数字的字符串形式（n≤20，每个数最多10位）
//     char *nums[21];
//     char temp[12];  // 临时存储单个数字的字符串（1e9是10位）
    
//     for (int i = 0; i < n; i++) 
//     {
//         int num;
//         scanf("%d", &num);
//         sprintf(temp, "%d", num);  // 数字转字符串
//         nums[i] = malloc(strlen(temp) + 1);  // 分配内存
//         strcpy(nums[i], temp);  // 存入数组
//     }
    
//     // 按自定义规则排序
//     /*
//         qsort函数：
    
//         头文件为stdlib.h
//         base：指向待排序数组的起始地址（这里是nums，存储字符串指针的数组）；
//         nitems：数组中元素的个数（这里是n，数字的个数）；
//         size：数组中单个元素的大小（这里是sizeof(char*)，因为数组元素是字符串指针）；
//         compar：指向自定义比较函数的指针（这里是compare函数，决定排序规则）。

//         qsort的比较函数要求：
//         接收两个const void*类型的参数（指向待比较的两个数组元素）；

//         若compare(a, b) < 0：a排在b前面；
//         若compare(a, b) > 0：b排在a前面；
//         若compare(a, b) = 0：a和b顺序不变。
//     */
//     qsort(nums, n, sizeof(char*), compare);
    
//     // 拼接所有字符串并输出
//     for (int i = 0; i < n; i++) 
//     {
//         printf("%s", nums[i]);
//         free(nums[i]);  // 释放内存
//     }
//     printf("\n");
   
//     return 0;
//  }
//  // 自定义比较函数：比较a+b和b+a的大小，决定排序顺序
// int compare(const void *a, const void *b) 
// {
//     char ab[22], ba[22];  // 每个数最多10位，拼接后最多20位
//     /*
//         strcpy的作用是将源字符串完整复制到目标字符串中（会覆盖目标字符串原有内容）
//         strcat的作用是将源字符串追加到目标字符串的末尾（目标字符串需以'\0'结尾）
//     */
//     /*
//         函数参数的类型转换
//         这里排序的数组元素是字符串指针（char*），
//         因此需要将const void*类型的a和b转换为const char**（指向字符串指针的指针），
//         再解引用得到实际的字符串（*(const char**)a就是第一个字符串，*(const char**)b是第二个字符串）。
//     */
//     strcpy(ab, *(const char**)a);
//     strcat(ab, *(const char**)b);
//     strcpy(ba, *(const char**)b);
//     strcat(ba, *(const char**)a);
//     // 返回ba和ab的比较结果（降序：ab>ba则a排前面）
//     //注：此处为ba,ab，因为后面需要用到的是qsort函数
//     return strcmp(ba, ab);
// }