// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h> // 用于fgets

// #define MAP_SIZE 12  // 0-11：边界+10x10有效区域
// char map[MAP_SIZE][MAP_SIZE];

// // 状态定义：[0]方向(0=北,1=东,2=南,3=西) [1]x坐标 [2]y坐标
// int f[3] = {0, 0, 0};  // Farmer John
// int c[3] = {0, 0, 0};  // Cow
// int step = 0;

// // 状态标记：避免循环（F坐标+方向 + C坐标+方向）
// bool visited[MAP_SIZE][MAP_SIZE][MAP_SIZE][MAP_SIZE][4][4] = {false};

// // 移动逻辑：更新传入的对象（F/C）状态
// void move_entity(int *entity) 
// {
//     int dir = entity[0];
//     int x = entity[1];
//     int y = entity[2];
//     int nx = x, ny = y;

//     // 1. 根据当前方向计算下一步坐标
//     switch (dir) 
//     {
//         case 0: nx = x - 1; break;  // 北：行-1
//         case 1: ny = y + 1; break;  // 东：列+1
//         case 2: nx = x + 1; break;  // 南：行+1
//         case 3: ny = y - 1; break;  // 西：列-1
//     }

//     // 2. 判断是否是障碍（边界/星号）
//     if (map[nx][ny] == '*') 
//     {
//         // 遇障碍：顺时针转90度（循环）
//         entity[0] = (dir + 1) % 4;
//     } 
//     else 
//     {
//         // 无障碍：移动到新位置
//         entity[1] = nx;
//         entity[2] = ny;
//     }
// }

// int main() 
// {
//     // 1. 初始化地图边界为障碍（*）
//     memset(map, '*', sizeof(map)); // 先全部设为*
//     // 仅保留1-10行、1-10列为可移动区域（后续覆盖为输入值）
//     for (int i = 1; i <= 10; i++) 
//     {
//         for (int j = 1; j <= 10; j++) 
//         {
//             map[i][j] = '.';
//         }
//     }

//     // 2. 读取10x10地图（用fgets避免换行符问题）
//     char line[20]; // 每行最多10个字符+换行+结束符
//     for (int i = 1; i <= 10; i++) 
//     {
//         // 读取整行（自动跳过换行符）
//         fgets(line, sizeof(line), stdin);
//         // 提取前10个有效字符（避免换行符干扰）
//         for (int j = 1; j <= 10; j++) 
//         {
//             map[i][j] = line[j-1]; // line[0]对应map[i][1]
//             // 记录F和C的初始位置
//             if (map[i][j] == 'F') 
//             {
//                 f[1] = i;
//                 f[2] = j;
//                 map[i][j] = '.'; // 清空，避免误判为障碍
//             } 
//             else if (map[i][j] == 'C') 
//             {
//                 c[1] = i;
//                 c[2] = j;
//                 map[i][j] = '.'; // 清空，避免误判为障碍
//             }
//         }
//     }

//     // 3. 模拟移动过程（核心逻辑）
//     while (1) 
//     {
//         // 防无限循环：步数超过10万则判定无法相遇
//         if (step > 100000) 
//         {
//             printf("0\n");
//             return 0;
//         }

//         // 检查是否进入循环（状态重复）
//         if (visited[f[1]][f[2]][c[1]][c[2]][f[0]][c[0]]) 
//         {
//             printf("0\n");
//             return 0;
//         }
//         // 标记当前状态为已访问
//         visited[f[1]][f[2]][c[1]][c[2]][f[0]][c[0]] = true;

//         // 步数+1（每轮移动F和C各一次，计1步）
//         step++;

//         // 移动F和C
//         move_entity(f);
//         move_entity(c);

//         // 检查是否相遇
//         if (f[1] == c[1] && f[2] == c[2]) 
//         {
//             printf("%d\n", step);
//             return 0;
//         }
//     }

//     return 0;
// }