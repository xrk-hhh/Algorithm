// #include <stdio.h>

// // 统计操作数
// int count = 0;

// void move(char from, char to);
// void Hanoi(int n, char pos1, char pos2, char pos3);

// int main()
// {
//     /*
//         需求：汉诺塔
//         汉诺塔由三根柱子（分别用A、B、C表示）和n个大小互不相同的空心盘子组成。
//         一开始n个盘子都摞在柱子A上，大的在下面，小的在上面，形成了一个塔状的锥形体。 

//         对汉诺塔的一次合法的操作是指：
//         从一根柱子的最上层拿一个盘子放到另一根柱子的最上层，同时要保证:
//         被移动的盘子一定放在比它更大的盘子上面 （如果移动到空柱子上就不需要满足这个要求）。
//         汉诺塔的游戏目标是将所有的盘子从柱子A移动到柱子B或柱子C上面。
//         （要求：输入n值为4，要求将所有盘子从A柱子挪到B柱子上，并打印出所有的操作以及计算并输出总的操作数）
//     */

//     int n = 4;

//     Hanoi(n, 'A', 'C', 'B');
//     printf("\n");
//     // 打印总的操作数
//     printf("总的操作数为：%d\n",count);
//     return 0;
// }

// // 移动函数：打印移动步骤并计数
// void move(char from, char to)
// {
//     printf("%c -> %c\n",from,to);
//     // 每次移动 计数加一
//     count++;
// }

// // 汉诺塔递归函数：将 n 个盘子从 pos1（起始柱）经 pos2（中转柱）移到 pos3（目标柱）
// void Hanoi(int n, char pos1, char pos2, char pos3)
// {
//     // 1个盘子直接移动到目标柱
//     if (n == 1)
//     {
//         move(pos1, pos3);
//     }
//     else
//     {
//         // 1.先将上面的 n - 1 个盘子从 起始柱 移到 中转柱
//         Hanoi(n - 1, pos1, pos3, pos2);
//         // 2.再将第 n 个盘子移到 目标柱
//         move(pos1, pos3);
//         // 3.最后将 n - 1 个盘子从 中转柱 移到 目标柱
//         Hanoi(n - 1, pos2, pos1, pos3);
//     }
// }