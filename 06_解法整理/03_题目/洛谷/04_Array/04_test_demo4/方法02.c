// 原始稿：03_题目/洛谷/04_Array/04_test_demo4.c
// 原文行号：83-159；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

// 定义区间结构体（存储起始点u和终止点v）
typedef struct 
{
    int u;
    int v;
} Interval;

// qsort排序的比较函数（按u升序排序）
int compare(const void* a, const void* b) 
{
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->u - y->u;  // 正数则x在y后，负数则x在y前
}

int main() 
{
    int l, m;
    scanf("%d %d", &l, &m);

    // 存储m个区间（若m=0，直接输出l+1）
    Interval* intervals = (Interval*)malloc(m * sizeof(Interval));
    for (int i = 0; i < m; i++) 
    {
        scanf("%d %d", &intervals[i].u, &intervals[i].v);
    }

    // 若没有区域，所有树都保留
    if (m == 0) 
    {
        printf("%d", l + 1);
        free(intervals);
        return 0;
    }

    // 按起始点u排序区间
    qsort(intervals, m, sizeof(Interval), compare);

    // 合并区间：初始化第一个合并区间
    int current_u = intervals[0].u;
    int current_v = intervals[0].v;
    int total_removed = 0;  // 移走的树总数

    // 遍历剩余区间，合并重叠或相邻的区间
    for (int i = 1; i < m; i++) 
    {
        if (intervals[i].u <= current_v) 
        {
            // 重叠或相邻（当前区间的u <= 前一个区间的v），合并为更大的区间
            if (intervals[i].v > current_v) 
            {
                current_v = intervals[i].v;  // 更新终点为较大值
            }
        } 
        else 
        {
            // 不重叠，计算当前合并区间的树数量并累加
            total_removed += current_v - current_u + 1;
            // 更新当前合并区间为新的区间
            current_u = intervals[i].u;
            current_v = intervals[i].v;
        }
    }

    // 加上最后一个合并区间的树数量
    total_removed += current_v - current_u + 1;

    // 剩余树数量 = 总树数 - 移走的树数
    int remaining = (l + 1) - total_removed;
    printf("%d", remaining);

    free(intervals);  // 释放动态内存
    return 0;
}
