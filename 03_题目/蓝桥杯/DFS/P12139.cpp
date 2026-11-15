// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;
// #define endl '\n'

// vector<vector<char>> board(6, vector<char>(6)); // 棋盘存储
// vector<int> row_ones(6, 0), row_zeros(6, 0);    // 每行1和0的数量
// vector<int> col_ones(6, 0), col_zeros(6, 0);    // 每列1和0的数量
// unordered_set<string> used_rows, used_cols;     // 已存在的行列模式
// bool found = false;                             // 找到解的标志

// /*
//  * 检查当前位置(r,c)是否导致行或列出现连续三个相同颜色
//  * 参数 r是当前行号 c是当前列号
//  * 返回值是true表示通过
//  */
// bool check_consecutive(int r, int c) 
// {
//     // 行检查：向左检查两个格子是否重复
//     if (c >= 2 && board[r][c] == board[r][c - 1] && board[r][c] == board[r][c - 2])
//     {
//         return false;
//     }
    
//     //列检查：向上检查两个格子是否重复
//     if (r >= 2 && board[r][c] == board[r - 1][c] && board[r][c] == board[r - 2][c])
//     {
//         return false;
//     }
    
//     return true;
// }

// /*
//  * 深度优先搜索主函数
//  *   r是当前处理的行号
//  *   c是当前处理的列号
//  */
// void dfs(int r, int c) 
// {
//     // 剪枝1：有解时结束
//     if (found)
//     {
//         return;
//     }

//     // 当所有行处理完毕
//     if (r == 6) 
//     {
//         //检查列唯一性
//         unordered_set<string> cols;
//         for (int j = 0; j < 6; j++) 
//         {
//             string col;
//             // 生成列字符串
//             for (int i = 0; i < 6; i++)
//             {
//                 col += board[i][j];
//             }
//             // 发现重复的列立即返回
//             if (cols.count(col))
//             {
//                 return;
//             }
//             cols.insert(col);
//         }
        
//         // 输出
//         for (auto &row : board) 
//         {
//             for (char c : row)
//             {
//                 cout<<c;
//             }
//         }
//         cout<<endl;
//         found = true; // 找到解了
//         return;
//     }

//     // 当前行结束时
//     if (c == 6) 
//     {
//         string row_str;
//         // 生成当前行字符串
//         for (char ch : board[r])
//         {
//             row_str += ch;
//         }
        
//         // 检查行的唯一性
//         if (used_rows.count(row_str))
//         {
//             return;
//         }
//         used_rows.insert(row_str);  // 记录当前行
        
//         // 处理下一行第一列
//         dfs(r + 1, 0);
        
//         used_rows.erase(row_str);   // 回溯时删除记录
//         return;
//     }

//     // 跳过已经填充位置
//     if (board[r][c] != '.') 
//     {
//         dfs(r, c + 1); // 直接处理下一列
//         return;
//     }

//     // 尝试填充0和1
//     for (char val : {'0', '1'}) 
//     {
//         // 剪枝2：数量限制检查
//         if (val == '0' && (row_zeros[r] >= 3 || col_zeros[c] >= 3))
//         {
//             continue;
//         }
//         if (val == '1' && (row_ones[r] >= 3 || col_ones[c] >= 3))
//         {
//             continue;
//         }

//         // 保存当前状态（用于回溯时恢复）
//         char original = board[r][c];
//         int ro = row_ones[r], rz = row_zeros[r];
//         int co = col_ones[c], cz = col_zeros[c];
        
//         // 更新棋盘和计数器
//         board[r][c] = val;
//         if (val == '0') 
//         {
//             row_zeros[r]++;
//             col_zeros[c]++;
//         } 
//         else 
//         {
//             row_ones[r]++;
//             col_ones[c]++;
//         }
        
//         // 剪枝3：检查通过后继续
//         if (check_consecutive(r, c))
//         {
//             dfs(r, c + 1); // 递归处理下一列
//         }
        
//         // 回溯恢复状态
//         board[r][c] = original;
//         row_ones[r] = ro;
//         row_zeros[r] = rz;
//         col_ones[c] = co;
//         col_zeros[c] = cz;
//     }
// }

// int main() 
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // 手动输入样例
//     vector<string> input = 
//     {
//         "10.0..", 
//         "...0..",  
//         "....00",   
//         "......",  
//         "..1..1", 
//         ".0..1."  
//     };
    
//     // 初始化棋盘状态
//     for (int i = 0; i < 6; i++) 
//     {
//         for (int j = 0; j < 6; j++) 
//         {
//             board[i][j] = input[i][j];
//             // 统计初始棋子的数量
//             if (board[i][j] == '0') 
//             {
//                 row_zeros[i]++;  // 行0计数
//                 col_zeros[j]++;  // 列0计数
//             } 
//             else if (board[i][j] == '1') 
//             {
//                 row_ones[i]++;   // 行1计数
//                 col_ones[j]++;   // 列1计数
//             }
//         }
//     }
    
//     // DFS搜索（从左上角(0,0)开始）
//     dfs(0, 0);
//     return 0;
// }
