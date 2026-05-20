// // #include <stdio.h>

// // #define MAX_N 200000

// // typedef struct 
// // {
// //     int key;
// //     int count;
// // } HashNode;

// // /*
// //     哈希表的初始化（隐含）
// //     全局数组默认初始化为0，即每个HashNode的count=0（表示 “空位”），key=0（无意义）。
// // */
// // HashNode hash_table[MAX_N * 2];

// // /*
// //     哈希函数：把 “元素值” 映射到 “哈希表下标”
// //     目的：将任意整数key（数组元素值）转化为哈希表的一个初始下标，实现 “值→位置” 的映射。
// //     取模的模数是MAX_N*2（哈希表长度），保证下标不会超出数组范围。
// // */
// // int hash(int key) 
// // {
// //     return key % (MAX_N * 2);
// // }

// // /*
// //     插入函数：统计元素出现次数
// //     冲突处理逻辑：
// //     如果初始下标idx的位置已被占用（count≠0），
// //     且存储的key不是当前要插入的key（说明是不同值的冲突），就往后找下一个空位（idx+1，循环到表开头）。
// //     计数更新：
// //     若key是新元素（找到空位）：count从 0→1，key设为当前值；
// //     若key已存在：count直接加 1（统计重复次数）。
// // */
// // void insert(int key) 
// // {
// //     // 第一步：算初始下标
// //     int idx = hash(key);
// //     // 第二步：线性探测解决冲突
// //     while (hash_table[idx].count != 0 && hash_table[idx].key != key) 
// //     {
// //         idx = (idx + 1) % (MAX_N * 2);
// //     }
// //     // 第三步：更新计数（不管是新元素还是已存在元素）
// //     hash_table[idx].key = key;
// //     hash_table[idx].count++;
// // }

// // /*
// //     查找函数：查询元素的出现次数
// //     只有当count=0时，说明遍历到了空位，key一定不存在；
// //     否则继续检查当前位置的key是否匹配。
// // */
// // int find(int key) 
// // {
// //     // 第一步：算初始下标
// //     int idx = hash(key);
// //     // 第二步：遍历非空位
// //     while (hash_table[idx].count != 0) 
// //     {
// //         if (hash_table[idx].key == key) 
// //         {
// //             // 找到key，返回次数
// //             return hash_table[idx].count;
// //         }
// //         // 冲突则继续探测
// //         idx = (idx + 1) % (MAX_N * 2);
// //     }
// //     // 没找到，返回0
// //     return 0;
// // }
// // int main()
// // {
// //     /*
// //         需求：A-B 数对
// //         题目背景：
// //         出题是一件痛苦的事情！
// //         相同的题目看多了也会有审美疲劳，于是我舍弃了大家所熟悉的 A+B Problem，改用 A-B 了哈哈！

// //         题目描述：
// //         给出一串正整数数列以及一个正整数 C，
// //         要求计算出所有满足 A−B=C 的数对的个数（不同位置的数字一样的数对算不同的数对）。

// //         输入格式：
// //         输入共两行。

// //         第一行，两个正整数 N,C。
// //         第二行，N 个正整数，作为要求处理的那串数。

// //         输出格式：
// //         一行，表示该串正整数中包含的满足 A−B=C 的数对的个数。

// //         说明/提示：
// //         对于 75% 的数据，1≤N≤2000。
// //         对于 100% 的数据，1≤N≤2×10^5，0≤ai<2^30，1≤C<2^30。
    
// //     */


// //     // /*
// //     //     暴力解法：
// //     //     对每个a[i]，遍历整个数组找a[i]+c，时间复杂度是O(n²)
// //     //     —— 当n=2e5时，这会超时（计算量达 4e10 次）。
// //     // */
// //     // int N;
// //     // long long C;
// //     // scanf("%d %lld",&N, &C);

// //     // long long num[200010];
// //     // for (int i = 0; i < N; i++)
// //     // {
// //     //     scanf("%lld",&num[i]);
// //     // }
    
// //     // int count = 0;
// //     // for (int i = 0; i < N; i++)
// //     // {
// //     //     for (int j = 0; j < N; j++)
// //     //     {
// //     //         if (i == j)
// //     //         {
// //     //             continue;
// //     //         }
// //     //         if (num[i] - num[j] == C)
// //     //         {
// //     //             count++;
// //     //         }
// //     //     }
// //     // }

// //     // printf("%d",count);

// //     /*
// //         哈希表的作用是提前存储所有元素的出现次数，
// //         后续查询时直接 “查表” 而非 “遍历”，
// //         将查询效率从O(n)降到O(1)（平均情况），整体时间复杂度优化为O(n)。
    
// //         核心细节的设计原因
// //         1. 哈希表大小设为MAX_N*2
// //         哈希表的负载因子（元素个数 / 表长度）越小，冲突概率越低。
// //         设为MAX_N*2时，负载因子最大为 0.5（当所有元素不同时），线性探测的效率最高，不会因为冲突过多导致查询变慢。
// //         2. 线性探测的选择
// //         线性探测是解决哈希冲突的简单方法：idx=(idx+1)%表长。
// //         虽然极端情况下会出现 “聚集”（连续空位被占），但对于题目中的数据规模，效率足够。
// //         3. 全局哈希表的初始化
// //         全局数组默认初始化为 0，正好利用count=0表示 “空位”，无需额外初始化代码，简化逻辑。

// //         总结代码的逻辑链条
// //         问题转化（a[j]-a[i]=c→a[j]=a[i]+c）→哈希表统计次数（第一次遍历插入）→
// //         查询累加结果（第二次遍历查找）→输出最终计数。
// //         每一步的设计都围绕 “高效统计 + 快速查询”，最终用O(n)时间解决原本O(n²)的问题。
// //     */
// //     int n, c;
// //     int a[MAX_N];
// //     // 用long long防溢出
// //     long long ans = 0;

// //     // 第一步：输入数据
// //     scanf("%d %d", &n, &c);
// //     for (int i = 0; i < n; i++) 
// //     {
// //         scanf("%d", &a[i]);
// //         // 第二步：插入所有元素，统计次数
// //         insert(a[i]);
// //     }

// //     // 第三步：遍历每个元素，查询a[i]+c的次数并累加
// //     for (int i = 0; i < n; i++) 
// //     {
// //         ans += find(a[i] + c);
// //     }

// //     // 输出结果
// //     printf("%lld\n", ans);
    
// //     return 0;
// // }

// /*
//     另外，此题也可用 排序 + 二分 来实现
//     利用 “排序后可二分快速定位元素范围” 的特性，时间复杂度为 O(N log N)（排序占 O(N log N)，
//     每个元素的二分查找占 O(log N)），适合 N=2×10⁵ 的数据规模。
//     核心思路
//     排序数组：将原数组升序排列，为二分查找做准备；
//     遍历每个元素作为B：对每个 B，计算目标值 target = B + C（即满足 A=B+C 的 A）；
//     二分找target的范围：用二分查找找到 target 在排序数组中第一次出现的下标（左边界）和最后一次出现的下标（右边界）；
//     统计数对数量：若 target 存在（左边界 ≤ 右边界），则该 B 对应的数对数量为 右边界 - 左边界 + 1，累加到答案中。

//     注：
//     这个函数采用的是左闭右开区间的二分框架（查找范围是 [left, right)）
//     [left, right) 是左闭右开区间（包含 left，不包含 right），
//     区间内的元素个数 = 右边界 - 左边界，因此这里是 right - left，不需要加 1。
// */
// #include <stdio.h>
// #include <stdlib.h>

// // 比较函数（用于qsort排序）
// int cmp(const void *a, const void *b) 
// {
//     return *(int *)a - *(int *)b;
// }

// // 二分找target的左边界（第一个>=target的下标）
// int lower_bound(int *a, int n, int target) 
// {
//     int left = 0, right = n;
//     while (left < right) 
//     {
//         int mid = left + (right - left) / 2;
//         if (a[mid] >= target) 
//         {
//             right = mid;
//         } 
//         else 
//         {
//             left = mid + 1;
//         }
//     }
//     return left;
// }

// // 二分找target的右边界（第一个>target的下标）
// int upper_bound(int *a, int n, int target) 
// {
//     int left = 0, right = n;
//     while (left < right) 
//     {
//         int mid = left + (right - left) / 2;
//         if (a[mid] > target) 
//         {
//             right = mid;
//         } 
//         else 
//         {
//             left = mid + 1;
//         }
//     }
//     return left;
// }

// int main() 
// {
//     int N, C;
//     scanf("%d %d", &N, &C);
//     int *a = (int *)malloc(N * sizeof(int));
//     for (int i = 0; i < N; i++) 
//     {
//         scanf("%d", &a[i]);
//     }

//     // 步骤1：排序数组
//     qsort(a, N, sizeof(int), cmp);

//     long long ans = 0;
//     for (int i = 0; i < N; i++) 
//     {
//         int B = a[i];
//         int target = B + C;
//         // 步骤2：二分找target的左右边界
//         int left = lower_bound(a, N, target);
//         int right = upper_bound(a, N, target);
//         // 步骤3：累加target的出现次数
//         ans += (right - left);
//     }

//     printf("%lld\n", ans);
//     free(a);
//     return 0;
// }