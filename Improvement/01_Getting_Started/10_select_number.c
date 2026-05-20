// // #include <stdio.h>
// // #include <math.h>

// // 方法一：递归，但需注意，此时的质数判断函数需将long long改为int，否则将会TE

// // int result = 0; // 统计符合条件的组合数（全局变量，方便递归访问）

// // int is_prime(int n);
// // void backtrack(int num[], int n, int k, int start, int count, int sum);

// // int main()
// // {
// //     /*
// //         需求：选数
// //         题目描述
// //         已知 n 个整数 x1,x2,⋯,xn，以及 1 个整数 k（k<n）。
// //         从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。
// //         例如当 n=4，k=3，4 个整数分别为 3,7,12,19 时，可得全部的组合与它们的和为：

// //         3+7+12=22

// //         3+7+19=29

// //         7+12+19=38

// //         3+12+19=34

// //         现在，要求你计算出和为素数共有多少种。

// //         例如上例，只有一种的和为素数：3+7+19=29。

// //         输入格式
// //         第一行两个空格隔开的整数 n,k（1≤n≤20，k<n）。

// //         第二行 n 个整数，分别为 x1,x2,⋯,xn（1≤xi≤5×10^6）。

// //         输出格式
// //         输出一个整数，表示种类数。
    
// //     */

// //     int n, k;
// //     scanf("%d %d",&n, &k);

// //     int num[21];
// //     for (int i = 0; i < n; i++)
// //     {
// //         scanf("%d",&num[i]);
// //     }

// //      // 调用回溯函数：从索引0开始，已选0个，和为0
// //     backtrack(num, n, k, 0, 0, 0);

// //     // 输出结果
// //     printf("%d\n", result);

// //     return 0;
// // }
// // // 质数判断函数
// // int is_prime(int n)
// //  {
// //     // <= 1不是质数
// //     if (n <= 1)
// //     {
// //         return 0;
// //     }
// //     // 2是质数
// //     if (n == 2)
// //     {
// //         return 1;
// //     }
// //     // 偶数（>2）不是质数
// //     if (n % 2 == 0)
// //     {
// //         return 0;
// //     }
// //     // 检查到平方根即可
// //     int sqrt_n = (int)sqrt(n);
// //     // 只查奇数
// //     for (int i = 3; i <= sqrt_n; i += 2)
// //     {
// //         // 有因数，不是质数
// //         if (n % i == 0)
// //         {
// //             return 0;
// //         }
// //     }
// //     // 是质数
// //     return 1;
// //  }

// // // 回溯函数：枚举选k个数的组合
// // // start：当前遍历的起始索引（避免重复组合）
// // // count：已选数的个数
// // // sum：已选数的和
// // void backtrack(int num[], int n, int k, int start, int count, int sum) 
// // {
// //     // 终止条件：选够 k 个数
// //     if (count == k) 
// //     {
// //         if (is_prime(sum)) 
// //         { 
// //             // 判断和是否为素数
// //             result++;
// //         }
// //         return;
// //     }

// //     // 遍历从start开始的数（避免重复组合，如[0,1]和[1,0]视为同一组合）
// //     for (int i = start; i < n; i++) 
// //     {
// //         // 选择当前数，递归处理下一个位置
// //         backtrack(num, n, k, i + 1, count + 1, sum + num[i]);
// //     }
// // }


// // 方法二：DFS 回溯
// #include <stdio.h>

// // 全局变量：总数字个数、数字数组、需选个数、结果计数
// int total_num;       // 输入的总数字数量
// int nums[25];        // 存储输入的数字数组
// int select_num;      // 需要选择的数字个数
// int result;          // 符合条件的组合数结果

// _Bool is_prime(int num);
// void dfs(int prev_index, int current_sum, int selected_count);

// int main()
// {
//     scanf("%d %d", &total_num, &select_num);  // 读入总数量和需选数量
//     // 读入所有数字（下标从1开始，保持原逻辑）
//     for (int idx = 1; idx <= total_num; idx++) 
//     {
//         /*
//             在 C 语言中：
//             数组名 nums 本质是数组首元素的地址（即 &nums[0]，类型是 int*）。
//             指针运算中，nums + idx 表示 “从数组首地址出发，向后偏移 idx 个 int 类型元素的地址”
//             —— 这恰好就是 nums[idx] 这个元素的地址，等价于 &nums[idx]。
//         */
//         // 此处的 nums + idx 等价于 &num[idx]
//         scanf("%d", nums + idx);
//     }
//     // 初始调用：上一个下标0（未选）、当前和 0、已选0个
//     dfs(0, 0, 0);
//     printf("%d", result);

//     return 0;
// }

// // 判断一个数是否为素数
// _Bool is_prime(int num) 
// {
//     // <= 1不是质数
//     if (num <= 1)
//     {
//         return 0;
//     }
//     // 2是质数
//     if (num == 2)
//     {
//         return 1;
//     }
//     // 偶数（>2）不是质数
//     if (num % 2 == 0)
//     {
//         return 0;
//     }
//     // 只查奇数，且// 检查到平方根即可
//     for (int i = 2; i * i <= num; i += 2) 
//     {
//         // 有因数，不是质数
//         if (num % i == 0)
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

// // 深度优先搜索枚举组合
// // prev_index：上一次选中数字的下标，避免重复组合
// // current_sum：当前已选数字的和
// // selected_count：当前已选数字的个数
// void dfs(int prev_index, int current_sum, int selected_count) 
// {
//     // 终止条件：选够指定数量的数字
//     if (selected_count == select_num) 
//     {
//         result += is_prime(current_sum);  // 和为素数则结果+1
//         return;
//     }
//     // 从上次选的下一个下标开始遍历，避免重复组合
//     for (int index = prev_index + 1; index <= total_num; index++) 
//     {
//         dfs(index, current_sum + nums[index], selected_count + 1);
//     }
// }

