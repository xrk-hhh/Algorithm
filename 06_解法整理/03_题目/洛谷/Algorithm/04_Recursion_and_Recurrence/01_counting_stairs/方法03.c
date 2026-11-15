// 原始稿：03_题目/洛谷/Algorithm/04_Recursion_and_Recurrence/01_counting_stairs.c
// 原文行号：66-138；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1050  // 5000项的斐波那契数约1045位，预留足够空间

int main() 
{
    int N;
    scanf("%d", &N);

    // 特殊情况直接输出
    if (N == 1) 
    {
        printf("1\n");
        return 0;
    } 
    else if (N == 2) 
    {
        printf("2\n");
        return 0;
    }

    // 初始化前两项：dp[1]=1，dp[2]=2
    int f1[MAX_DIGITS] = {0};  // 存储 dp[i-2]（低位在前）
    int f2[MAX_DIGITS] = {0};  // 存储 dp[i-1]（低位在前）
    int f[MAX_DIGITS] = {0};   // 存储当前 dp[i]（低位在前）
    int len1 = 1, len2 = 1;    // f1和f2的有效位数
    f1[0] = 1;  // dp[1] = 1
    f2[0] = 2;  // dp[2] = 2

    // 递推计算从第3项到第N项
    for (int i = 3; i <= N; i++) 
    {
        int carry = 0;
        int max_len = (len1 > len2) ? len1 : len2;

        // 逐位相加（低位在前）
        for (int j = 0; j < max_len; j++) 
        {
            int sum = f1[j] + f2[j] + carry;
            f[j] = sum % 10;  // 当前位保留余数
            carry = sum / 10; // 进位传递到高位
        }

        // 处理剩余的进位（可能产生新的高位）
        if (carry > 0) 
        {
            f[max_len] = carry;
            len2 = max_len + 1;
        } 
        else 
        {
            len2 = max_len;
        }

        // 更新前两项：f1变为原来的f2，f2变为当前的f
        memcpy(f1, f2, sizeof(f1));
        memcpy(f2, f, sizeof(f2));
        len1 = len2;  // f1的长度更新为原f2的长度

        // 清空当前f数组，准备下一次计算
        memset(f, 0, sizeof(f));
    }

    // 输出结果（逆序输出，因为低位在前）
    for (int i = len2 - 1; i >= 0; i--) 
    {
        printf("%d", f2[i]);
    }
    printf("\n");

    return 0;
}
