// // #include <stdio.h>

// // int main()
// // {
// //     /*
// //         需求：校门外的树
// //         题目描述：
// //         某校大门外长度为 l 的马路上有一排树，每两棵相邻的树之间的间隔都是 1 米。
// //         我们可以把马路看成一个数轴，马路的一端在数轴 0 的位置，另一端在 l 的位置；
// //         数轴上的每个整数点，即 0,1,2,…,l，都种有一棵树。

// //         由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。
// //         已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。
// //         现在要把这些区域中的树（包括区域端点处的两棵树）移走。
// //         你的任务是计算将这些树都移走后，马路上还有多少棵树。

// //         输入格式：
// //         第一行有两个整数，分别表示马路的长度 l 和区域的数目 m。

// //         接下来 m 行，每行两个整数 u,v，表示一个区域的起始点和终止点的坐标。

// //         输出格式：
// //         输出一行一个整数，表示将这些树都移走后，马路上剩余的树木数量。

// //         说明/提示:
// //         【数据范围】
// //         对于 20% 的数据，保证区域之间没有重合的部分。
// //         对于 100% 的数据，保证 1≤l≤10^4，1≤m≤100，0≤u≤v≤l。
// //     */

// //     // 方法一：标记法(适合小范围)
// //     int l, m;
// //     scanf("%d %d",&l,&m);

// //     int tree[l + 1];
// //      // 标记每个位置是否有树（1=有，0=移走）
// //     for (int i = 0; i <= l; i++)
// //     {
// //          // 初始所有位置都有树
// //         tree[i] = 1;
// //     }

// //     for (int i = 0; i < m; i++)
// //     {
// //         int u, v;
// //         scanf("%d %d",&u,&v);
// //         // 标记[u, v]区间内的树为“移走”
// //         for (int j = u; j <= v; j++)
// //         {
// //             tree[j] = 0;
// //         }
// //     }

// //     // 统计剩余的树（tree[j]==1的数量）
// //     int count = 0;
// //     for (int j = 0; j <= l; j++)
// //     {
// //         if (tree[j] == 1)
// //         {
// //             count++;
// //         }
// //     }
// //     printf("%d",count);
// //     return 0;
// // }

// // 方法二：区间合并
// /*
//     核心是
//     先将所有重叠或相邻的区间合并为一个整体区间，
//     再计算合并后所有区间的总长度，
//     最后用总树数减去移走的树数得到结果。
//     这种方法更高效（尤其适合 l 很大的场景）
// */
// /*
//     实现思路：
//     1.存储区间：用结构体数组存储所有区域的起始点 u 和终止点 v。
//     2.排序区间：按区间的起始点 u 升序排序（方便后续合并）。
//     3.合并区间：遍历排序后的区间，将重叠或相邻的区间合并为一个大区间（例如 [1,3] 和 [2,5] 合并为 [1,5]）。
//     4.计算移走的树：合并后每个区间的树数量为 v - u + 1（包含端点），累加得到总移走数。
//     5.计算剩余树：总树数为 l + 1（从 0 到 l 共 l+1 个点），剩余树数 = 总树数 - 移走的树数。
// */
// #include <stdio.h>
// #include <stdlib.h>

// // 定义区间结构体（存储起始点u和终止点v）
// typedef struct 
// {
//     int u;
//     int v;
// } Interval;

// // qsort排序的比较函数（按u升序排序）
// int compare(const void* a, const void* b) 
// {
//     Interval* x = (Interval*)a;
//     Interval* y = (Interval*)b;
//     return x->u - y->u;  // 正数则x在y后，负数则x在y前
// }

// int main() 
// {
//     int l, m;
//     scanf("%d %d", &l, &m);

//     // 存储m个区间（若m=0，直接输出l+1）
//     Interval* intervals = (Interval*)malloc(m * sizeof(Interval));
//     for (int i = 0; i < m; i++) 
//     {
//         scanf("%d %d", &intervals[i].u, &intervals[i].v);
//     }

//     // 若没有区域，所有树都保留
//     if (m == 0) 
//     {
//         printf("%d", l + 1);
//         free(intervals);
//         return 0;
//     }

//     // 按起始点u排序区间
//     qsort(intervals, m, sizeof(Interval), compare);

//     // 合并区间：初始化第一个合并区间
//     int current_u = intervals[0].u;
//     int current_v = intervals[0].v;
//     int total_removed = 0;  // 移走的树总数

//     // 遍历剩余区间，合并重叠或相邻的区间
//     for (int i = 1; i < m; i++) 
//     {
//         if (intervals[i].u <= current_v) 
//         {
//             // 重叠或相邻（当前区间的u <= 前一个区间的v），合并为更大的区间
//             if (intervals[i].v > current_v) 
//             {
//                 current_v = intervals[i].v;  // 更新终点为较大值
//             }
//         } 
//         else 
//         {
//             // 不重叠，计算当前合并区间的树数量并累加
//             total_removed += current_v - current_u + 1;
//             // 更新当前合并区间为新的区间
//             current_u = intervals[i].u;
//             current_v = intervals[i].v;
//         }
//     }

//     // 加上最后一个合并区间的树数量
//     total_removed += current_v - current_u + 1;

//     // 剩余树数量 = 总树数 - 移走的树数
//     int remaining = (l + 1) - total_removed;
//     printf("%d", remaining);

//     free(intervals);  // 释放动态内存
//     return 0;
// }