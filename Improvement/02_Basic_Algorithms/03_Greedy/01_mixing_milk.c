// // #include <stdio.h>

// // // 封装奶农的单价和产量，保证关联关系
// // typedef struct
// // {
// //     int price;  // 单价pi
// //     int amount; // 产量ai
// // } Farmer;

// // // 声明函数（参数类型与实现一致）
// // int get_pivot(Farmer *farmers, int low, int high);
// // void quick_sort(Farmer *farmers, int low, int high);

// // int main()
// // {
// //     /*
// //         需求：混合牛奶 Mixing Milk
// //         题目描述：
// //         由于乳制品产业利润很低，所以降低原材料（牛奶）价格就变得十分重要。
// //         帮助 Marry 乳业找到最优的牛奶采购方案。

// //         Marry 乳业从一些奶农手中采购牛奶，并且每一位奶农为乳制品加工企业提供的价格可能相同。
// //         此外，就像每头奶牛每天只能挤出固定数量的奶，每位奶农每天能提供的牛奶数量是一定的。
// //         每天 Marry 乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。

// //         给出 Marry 乳业每天对牛奶的需求量，还有每位奶农提供的牛奶单价和产量。
// //         计算采购足够数量的牛奶所需的最小花费。

// //         注：每天所有奶农的总产量不少于 Marry 乳业的需求量。

// //         输入格式：
// //         第一行二个整数 n,m，表示需要牛奶的总量，和提供牛奶的农民个数。

// //         接下来 m 行，每行两个整数 pi,ai，表示第 i 个农民牛奶的单价，和农民 i 一天最多能卖出的牛奶量。

// //         输出格式：
// //         单独的一行包含单独的一个整数，表示 Marry 的牛奶制造公司拿到所需的牛奶所要的最小费用。

// //         说明/提示：
// //         【数据范围】
// //         对于 100% 的数据：
// //         0≤n,ai≤2×10^6，0≤m≤5000，0≤pi≤1000

// //         本题按单价从小到大考虑(贪心)

// //     */

// //     int n, m;
// //     scanf("%d %d", &n, &m);

// //     Farmer farmers[5010]; // 结构体数组存储奶农信息
// //     for (int i = 0; i < m; i++)
// //     {
// //         scanf("%d %d", &farmers[i].price, &farmers[i].amount);
// //     }

// //     // 按单价升序排序结构体数组
// //     quick_sort(farmers, 0, m - 1);

// //     long long cost = 0; // 改用long long避免溢出
// //     int sum = 0;        // 已采购的牛奶总量
// //     for (int i = 0; i < m; i++)
// //     {
// //         if (sum >= n)
// //         {
// //             break; // 已采购足够，提前退出
// //         }
// //         // 计算本次能采购的量：取“剩余需求量”和“奶农产量”的较小值
// //         int buy = (n - sum) < farmers[i].amount ? (n - sum) : farmers[i].amount;
// //         cost += (long long)farmers[i].price * buy; // 强制转换避免乘法溢出
// //         sum += buy;
// //     }

// //     printf("%lld\n", cost); // 输出long long + 换行

// //     return 0;
// // }
// // // 三数取中法选基准（针对Farmer结构体的price）
// // int get_pivot(Farmer *farmers, int low, int high)
// // {
// //     int mid = low + (high - low) / 2;
// //     // 调整low、mid、high的price为升序
// //     if (farmers[low].price > farmers[mid].price)
// //     {
// //         Farmer tmp = farmers[low];
// //         farmers[low] = farmers[mid];
// //         farmers[mid] = tmp;
// //     }
// //     if (farmers[low].price > farmers[high].price)
// //     {
// //         Farmer tmp = farmers[low];
// //         farmers[low] = farmers[high];
// //         farmers[high] = tmp;
// //     }
// //     if (farmers[mid].price > farmers[high].price)
// //     {
// //         Farmer tmp = farmers[mid];
// //         farmers[mid] = farmers[high];
// //         farmers[high] = tmp;
// //     }
// //     // 把mid位置的基准结构体交换到low
// //     Farmer tmp = farmers[low];
// //     farmers[low] = farmers[mid];
// //     farmers[mid] = tmp;
// //     return farmers[low].price; // 返回基准单价
// // }

// // // 快速排序：按Farmer的price升序排序
// // void quick_sort(Farmer *farmers, int low, int high)
// // {
// //     if (low >= high)
// //     {
// //         return;
// //     }

// //     // 小范围用插入排序（更高效）
// //     if (high - low < 10)
// //     {
// //         for (int i = low + 1; i <= high; i++)
// //         {
// //             Farmer tmp = farmers[i];
// //             int j = i - 1;
// //             while (j >= low && farmers[j].price > tmp.price)
// //             {
// //                 farmers[j + 1] = farmers[j];
// //                 j--;
// //             }
// //             farmers[j + 1] = tmp;
// //         }
// //         return;
// //     }

// //     // 关键修正：先保存基准值，避免填坑时被覆盖
// //     Farmer pivot = farmers[low]; // 保存基准结构体（而不是只保存price）
// //     int key = pivot.price;
// //     int i = low, j = high;

// //     // 填坑逻辑（交换整个结构体，保证price和amount同步）
// //     while (i < j)
// //     {
// //         // 从右找price <= key的结构体
// //         while (i < j && farmers[j].price > key)
// //         {
// //             j--;
// //         }
// //         if (i < j)
// //         {
// //             farmers[i] = farmers[j];
// //             i++;
// //         }

// //         // 从左找price >= key的结构体
// //         while (i < j && farmers[i].price < key)
// //         {
// //             i++;
// //         }
// //         if (i < j)
// //         {
// //             farmers[j] = farmers[i];
// //             j--;
// //         }
// //     }

// //     // 基准结构体归位（用提前保存的pivot，而非被覆盖的farmers[low]）
// //     farmers[i] = pivot;

// //     // 递归排序左右子数组
// //     quick_sort(farmers, low, i - 1);
// //     quick_sort(farmers, i + 1, high);
// // }


// // 方法二：对于m≤5000的场景，手写快速排序容易出错，推荐用标准库qsort（代码更简洁，且经过优化）
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct
// {
//     int price;
//     int amount;
// } Farmer;

// // qsort比较函数：按price升序
// int cmp(const void *a, const void *b)
// {
//     // 结构体指针访问成员的语法（如果是结构体变量用.，结构体指针用->）
//     return ((Farmer *)a)->price - ((Farmer *)b)->price;
// }

// int main()
// {
//     int n, m;
//     scanf("%d %d", &n, &m);
//     Farmer farmers[5010];
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d %d", &farmers[i].price, &farmers[i].amount);
//     }

//     /*
//         qsort是 C 标准库的通用排序函数，它的比较函数必须接收两个const void*类型的参数（因为qsort能排序任意类型的数据，void*是通用指针），并返回一个int值：
//         返回值 < 0：第一个参数对应的元素，要排在第二个参数对应的元素前面；
//         返回值 = 0：两个元素顺序不变；
//         返回值 > 0：第一个参数对应的元素，要排在第二个参数对应的元素后面。
//     */
//     qsort(farmers, m, sizeof(Farmer), cmp); // 标准库排序，无bug

//     long long cost = 0;
//     int sum = 0;
//     for (int i = 0; i < m; i++)
//     {
//         if (sum >= n)
//         {
//             break;
//         }
//         int buy = (n - sum) < farmers[i].amount ? (n - sum) : farmers[i].amount;
//         cost += (long long)farmers[i].price * buy;
//         sum += buy;
//     }

//     printf("%lld\n", cost);
//     return 0;
// }