// #include <stdio.h>
// // 引入sqrt函数，用于计算平方根
// #include <math.h>
// // 用于memset初始化数组
// #include <string.h>

// int main()
// {
//     /*
//         需求：完全平方数
//         题目描述：
//         小杨同学有一个包含 n 个非负整数的序列 A，他想要知道其中有多少对下标组合 ⟨i,j⟩（1≤i<j≤n），使得 Ai+Aj 是完全平方数。

//         如果 x 是完全平方数，则存在非负整数 y 使得 y×y=x。

//         输入格式：
//         第一行一个非负整数 n，表示非负整数个数。
//         第二入行包含 n 个非负整数 A1,A2,…An，表示序列 A 包含的非负整数。

//         输出格式：
//         输出一行一个整数表示答案。

//         说明/提示：
//         对全部的测试数据，保证 1≤n≤1000，0≤Ai≤10^5
//     */
//     // 方法一：模拟题目逻辑
//     int n;
//     scanf("%d",&n);

//     // 存储序列
//     int seq[n];
//     // 读取序列
//     for (int i = 0; i < n; i++)
//     {
        
//         scanf("%d",&seq[i]);
//     }
    
//     // 记录符合条件的对数
//     int count = 0;
//     // 遍历所有i<j的下标对
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             // 计算两数之和
//             int sum = seq[i] + seq[j];
//             // 取平方根的整数部分
//             int root = (int)sqrt(sum);
//             // 验证是否为完全平方数
//             if (root * root == sum)
//             {
//                 count++;
//             }
//         }
//     }
//     printf("%d",count);

//     // // 方法二：查表判断
//     // // 预计算所有可能的完全平方数（0~2e5）
//     // int max_sum = 200000;  // 最大可能的sum（1e5 + 1e5）
//     // char is_square[max_sum + 1];  // 标记是否为完全平方数（0/1）
//     // memset(is_square, 0, sizeof(is_square));  // 初始化为0

//     // // 标记所有y²（y从0到447）
//     // for (int y = 0; y * y <= max_sum; y++) 
//     // {
//     //     is_square[y * y] = 1;
//     // }

//     // // 读取输入
//     // int n;
//     // scanf("%d", &n);
//     // int seq[n];
//     // for (int i = 0; i < n; i++) 
//     // {
//     //     scanf("%d", &seq[i]);
//     // }

//     // // 统计符合条件的对数
//     // int count = 0;
//     // for (int i = 0; i < n; i++) 
//     // {
//     //     for (int j = i + 1; j < n; j++) 
//     //     {
//     //         int sum = seq[i] + seq[j];
//     //         if (is_square[sum]) 
//     //         {  // 查表判断
//     //             count++;
//     //         }
//     //     }
//     // }

//     // printf("%d", count);
//     return 0;
// }
