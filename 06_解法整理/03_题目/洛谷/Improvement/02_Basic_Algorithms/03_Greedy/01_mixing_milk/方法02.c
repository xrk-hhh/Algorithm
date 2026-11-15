// 原始稿：03_题目/洛谷/Improvement/02_Basic_Algorithms/03_Greedy/01_mixing_milk.c
// 原文行号：174-223；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int price;
    int amount;
} Farmer;

// qsort比较函数：按price升序
int cmp(const void *a, const void *b)
{
    // 结构体指针访问成员的语法（如果是结构体变量用.，结构体指针用->）
    return ((Farmer *)a)->price - ((Farmer *)b)->price;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Farmer farmers[5010];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &farmers[i].price, &farmers[i].amount);
    }

    /*
        qsort是 C 标准库的通用排序函数，它的比较函数必须接收两个const void*类型的参数（因为qsort能排序任意类型的数据，void*是通用指针），并返回一个int值：
        返回值 < 0：第一个参数对应的元素，要排在第二个参数对应的元素前面；
        返回值 = 0：两个元素顺序不变；
        返回值 > 0：第一个参数对应的元素，要排在第二个参数对应的元素后面。
    */
    qsort(farmers, m, sizeof(Farmer), cmp); // 标准库排序，无bug

    long long cost = 0;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (sum >= n)
        {
            break;
        }
        int buy = (n - sum) < farmers[i].amount ? (n - sum) : farmers[i].amount;
        cost += (long long)farmers[i].price * buy;
        sum += buy;
    }

    printf("%lld\n", cost);
    return 0;
}
