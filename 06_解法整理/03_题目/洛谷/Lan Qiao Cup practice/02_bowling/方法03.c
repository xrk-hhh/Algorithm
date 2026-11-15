// 原始稿：03_题目/洛谷/Lan Qiao Cup practice/02_bowling.c
// 原文行号：231-338；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

// 定义结构体：绑定“瓶子数”和“对应位置”
// 原因：排序后位置会打乱，需保留值与位置的对应关系
typedef struct 
{
    int val;  // 存储每个位置的瓶子数（查询的关键字）
    int pos;  // 存储瓶子数对应的原始位置（最终要输出的结果）
} Node;

// qsort排序的比较函数：按瓶子数val升序排列
// 原因：二分查找要求数组有序，升序排列后可通过值快速定位
int cmp(const void *a, const void *b) 
{
    // 将void指针转为Node指针，比较val字段
    return ((Node *)a)->val - ((Node *)b)->val;
}

// 二分查找函数：在有序的Node数组中找目标值m对应的位置
// 参数：arr-有序数组，n-数组长度，m-要找的瓶子数
// 返回：找到则返回对应pos，否则返回0
int binary_search(Node *arr, int n, int m) 
{
    int left = 0;          // 左边界：初始为数组第一个元素
    int right = n - 1;     // 右边界：初始为数组最后一个元素
    
    // 二分查找核心循环：在[left, right]区间内缩小范围
    while (left <= right) 
    {
        // 计算中间位置mid：避免(left+right)溢出，等价于(left+right)/2
        int mid = left + (right - left) / 2;
        
        if (arr[mid].val == m) 
        {
            // 找到目标值：直接返回对应的原始位置pos
            return arr[mid].pos;
        } 
        else if (arr[mid].val < m) 
        {
            // 中间值小于目标值：目标在右半区，左边界右移
            left = mid + 1;
        } 
        else 
        {
            // 中间值大于目标值：目标在左半区，右边界左移
            right = mid - 1;
        }
    }
    // 循环结束未找到目标值：返回0（题目要求无解输出0）
    return 0;
}

int main() 
{
    int n;
    scanf("%d", &n);  // 输入位置数n
    
    // 动态分配Node数组：存储n个位置的“瓶子数-位置”对
    Node *arr = (Node *)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i].val);    // 输入第i+1个位置的瓶子数
        arr[i].pos = i + 1;          // 原始位置从1开始，绑定到pos字段
    }

    // 对Node数组按val升序排序
    // 作用：将无序的瓶子数转为有序，为二分查找做准备
    qsort(arr, n, sizeof(Node), cmp);

    int Q;
    scanf("%d", &Q);  // 输入查询次数Q
    
    // 处理Q次查询
    while (Q--) 
    {
        int m;
        scanf("%d", &m);  // 输入本次要找的瓶子数m
        // 二分查找m对应的位置并输出
        printf("%d\n", binary_search(arr, n, m));
    }

    free(arr);  // 释放动态分配的内存，避免内存泄漏

    /*
        关键逻辑拆解说明

        1.结构体Node的作用：
        原始数组的位置和瓶子数是一一对应的，但排序会打乱位置顺序，因此用结构体绑定两者，保证排序后仍能通过瓶子数找到原始位置。
        2.排序的必要性：
        二分查找的前提是数组有序，排序后可将 “遍历查找” 的O(n)时间复杂度优化为O(log n)，处理1e5次查询时效率大幅提升。
        3.二分查找的核心逻辑：
        通过不断比较中间值与目标值，将查找区间缩小一半（左半区或右半区），直到找到目标或区间为空，时间复杂度为O(log n)。
        4.边界处理：
        位置从 1 开始：题目中位置编号是 1~n，因此arr[i].pos = i+1；
        无解返回 0：严格匹配题目要求，二分查找未找到时返回 0。

        时间复杂度分析
        1.排序阶段：
        O(n log n)（qsort 的底层是快速排序，时间复杂度为O(n log n)）；
        2.查询阶段：
        每次查询是O(log n)，Q 次查询为O(Q log n)；
        3.整体复杂度：
        O(n log n + Q log n)，对于n, Q≤1e5的规模，完全能在时间限制内运行。
    */

    return 0;
}
