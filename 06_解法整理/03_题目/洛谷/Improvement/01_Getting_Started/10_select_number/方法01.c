// 原始稿：03_题目/洛谷/Improvement/01_Getting_Started/10_select_number.c
// 原文行号：1-118；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>
#include <math.h>

// 方法一：递归，但需注意，此时的质数判断函数需将long long改为int，否则将会TE

int result = 0; // 统计符合条件的组合数（全局变量，方便递归访问）

int is_prime(int n);
void backtrack(int num[], int n, int k, int start, int count, int sum);

int main()
{
    /*
        需求：选数
        题目描述
        已知 n 个整数 x1,x2,⋯,xn，以及 1 个整数 k（k<n）。
        从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。
        例如当 n=4，k=3，4 个整数分别为 3,7,12,19 时，可得全部的组合与它们的和为：

        3+7+12=22

        3+7+19=29

        7+12+19=38

        3+12+19=34

        现在，要求你计算出和为素数共有多少种。

        例如上例，只有一种的和为素数：3+7+19=29。

        输入格式
        第一行两个空格隔开的整数 n,k（1≤n≤20，k<n）。

        第二行 n 个整数，分别为 x1,x2,⋯,xn（1≤xi≤5×10^6）。

        输出格式
        输出一个整数，表示种类数。
    
    */

    int n, k;
    scanf("%d %d",&n, &k);

    int num[21];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&num[i]);
    }

     // 调用回溯函数：从索引0开始，已选0个，和为0
    backtrack(num, n, k, 0, 0, 0);

    // 输出结果
    printf("%d\n", result);

    return 0;
}
// 质数判断函数
int is_prime(int n)
 {
    // <= 1不是质数
    if (n <= 1)
    {
        return 0;
    }
    // 2是质数
    if (n == 2)
    {
        return 1;
    }
    // 偶数（>2）不是质数
    if (n % 2 == 0)
    {
        return 0;
    }
    // 检查到平方根即可
    int sqrt_n = (int)sqrt(n);
    // 只查奇数
    for (int i = 3; i <= sqrt_n; i += 2)
    {
        // 有因数，不是质数
        if (n % i == 0)
        {
            return 0;
        }
    }
    // 是质数
    return 1;
 }

// 回溯函数：枚举选k个数的组合
// start：当前遍历的起始索引（避免重复组合）
// count：已选数的个数
// sum：已选数的和
void backtrack(int num[], int n, int k, int start, int count, int sum) 
{
    // 终止条件：选够 k 个数
    if (count == k) 
    {
        if (is_prime(sum)) 
        { 
            // 判断和是否为素数
            result++;
        }
        return;
    }

    // 遍历从start开始的数（避免重复组合，如[0,1]和[1,0]视为同一组合）
    for (int i = start; i < n; i++) 
    {
        // 选择当前数，递归处理下一个位置
        backtrack(num, n, k, i + 1, count + 1, sum + num[i]);
    }
}


// 方法二：DFS 回溯
