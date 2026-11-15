// 原始稿：03_题目/洛谷/Lan Qiao Cup practice/01_a_b_number_pairs.c
// 原文行号：195-270；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

// 比较函数（用于qsort排序）
int cmp(const void *a, const void *b) 
{
    return *(int *)a - *(int *)b;
}

// 二分找target的左边界（第一个>=target的下标）
int lower_bound(int *a, int n, int target) 
{
    int left = 0, right = n;
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (a[mid] >= target) 
        {
            right = mid;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    return left;
}

// 二分找target的右边界（第一个>target的下标）
int upper_bound(int *a, int n, int target) 
{
    int left = 0, right = n;
    while (left < right) 
    {
        int mid = left + (right - left) / 2;
        if (a[mid] > target) 
        {
            right = mid;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    return left;
}

int main() 
{
    int N, C;
    scanf("%d %d", &N, &C);
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &a[i]);
    }

    // 步骤1：排序数组
    qsort(a, N, sizeof(int), cmp);

    long long ans = 0;
    for (int i = 0; i < N; i++) 
    {
        int B = a[i];
        int target = B + C;
        // 步骤2：二分找target的左右边界
        int left = lower_bound(a, N, target);
        int right = upper_bound(a, N, target);
        // 步骤3：累加target的出现次数
        ans += (right - left);
    }

    printf("%lld\n", ans);
    free(a);
    return 0;
}
