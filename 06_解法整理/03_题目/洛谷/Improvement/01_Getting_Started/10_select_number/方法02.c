// 原始稿：03_题目/洛谷/Improvement/01_Getting_Started/10_select_number.c
// 原文行号：119-200；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

// 全局变量：总数字个数、数字数组、需选个数、结果计数
int total_num;       // 输入的总数字数量
int nums[25];        // 存储输入的数字数组
int select_num;      // 需要选择的数字个数
int result;          // 符合条件的组合数结果

_Bool is_prime(int num);
void dfs(int prev_index, int current_sum, int selected_count);

int main()
{
    scanf("%d %d", &total_num, &select_num);  // 读入总数量和需选数量
    // 读入所有数字（下标从1开始，保持原逻辑）
    for (int idx = 1; idx <= total_num; idx++) 
    {
        /*
            在 C 语言中：
            数组名 nums 本质是数组首元素的地址（即 &nums[0]，类型是 int*）。
            指针运算中，nums + idx 表示 “从数组首地址出发，向后偏移 idx 个 int 类型元素的地址”
            —— 这恰好就是 nums[idx] 这个元素的地址，等价于 &nums[idx]。
        */
        // 此处的 nums + idx 等价于 &num[idx]
        scanf("%d", nums + idx);
    }
    // 初始调用：上一个下标0（未选）、当前和 0、已选0个
    dfs(0, 0, 0);
    printf("%d", result);

    return 0;
}

// 判断一个数是否为素数
_Bool is_prime(int num) 
{
    // <= 1不是质数
    if (num <= 1)
    {
        return 0;
    }
    // 2是质数
    if (num == 2)
    {
        return 1;
    }
    // 偶数（>2）不是质数
    if (num % 2 == 0)
    {
        return 0;
    }
    // 只查奇数，且// 检查到平方根即可
    for (int i = 2; i * i <= num; i += 2) 
    {
        // 有因数，不是质数
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// 深度优先搜索枚举组合
// prev_index：上一次选中数字的下标，避免重复组合
// current_sum：当前已选数字的和
// selected_count：当前已选数字的个数
void dfs(int prev_index, int current_sum, int selected_count) 
{
    // 终止条件：选够指定数量的数字
    if (selected_count == select_num) 
    {
        result += is_prime(current_sum);  // 和为素数则结果+1
        return;
    }
    // 从上次选的下一个下标开始遍历，避免重复组合
    for (int index = prev_index + 1; index <= total_num; index++) 
    {
        dfs(index, current_sum + nums[index], selected_count + 1);
    }
}
