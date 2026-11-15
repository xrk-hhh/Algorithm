// 原始稿：03_题目/洛谷/04_Array/03_test_demo3.c
// 原文行号：60-85；恢复外层注释 2 层；保留方法内部注释。
// 补入原共享头文件或评测接口所需的标准库头文件。
#include <stdio.h>
// 计算从n到1的冰雹序列长度
int get_sequence_length(int n) 
{
    int len = 1;
    while (n != 1) 
    {
        n = (n % 2 == 0) ? n / 2 : n * 3 + 1;
        len++;
    }
    return len;
}
int main() 
{
    int max_len = 0;
    for (int i = 1; i <= 100; i++)
    {
        int len = get_sequence_length(i);
        if (len > max_len) 
        {
            max_len = len;
            printf("n=%d 时，序列长度为 %d\n", i, len);
        }
    }
    printf("1~100中最长的序列长度为：%d\n", max_len);
    return 0;
}
