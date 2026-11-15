// #include <bits/stdc++.h>
// using namespace std;

// int board[5][5];
// int ans = 0;

// bool check(int r, int c) 
// {
//     int color = board[r][c];

//     bool win = true;
//     for (int j = 0; j < 5; j++) 
//     {
//         if (board[r][j] != color) 
//         {
//             win = false;
//             break;
//         }
//     }
//     if (win)
//     {
//         return true;
//     }

//     win = true;
//     for (int i = 0; i < 5; i++) 
//     {
//         if (board[i][c] != color) 
//         {
//             win = false;
//             break;
//         }
//     }
//     if (win)
//     {
//         return true;
//     }

//     if (r == c) 
//     {
//         win = true;
//         for (int i = 0; i < 5; i++) 
//         {
//             if (board[i][i] != color) 
//             {
//                 win = false;
//                 break;
//             }
//         }
//         if (win)
//         {
//             return true;
//         }
//     }

//     if (r + c == 4) 
//     {
//         win = true;
//         for (int i = 0; i < 5; i++) 
//         {
//             if (board[i][4 - i] != color) 
//             {
//                 win = false;
//                 break;
//             }
//         }
//         if (win)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// void dfs(int pos, int white, int black) 
// {
//     if (pos == 25) 
//     {
//         ans++;
//         return;
//     }
//     int r = pos / 5;
//     int c = pos % 5;

//     if (white < 13) 
//     {
//         board[r][c] = 0;
//         if (!check(r, c)) 
//         {
//             dfs(pos + 1, white + 1, black);
//         }
//         board[r][c] = -1;
//     }

//     if (black < 12) 
//     {
//         board[r][c] = 1;
//         if (!check(r, c)) 
//         {
//             dfs(pos + 1, white, black + 1);
//         }
//         board[r][c] = -1;
//     }
// }

// int main() 
// {
//     memset(board, -1, sizeof(board));
//     dfs(0, 0, 0);
//     cout << ans << endl;
//     return 0;
// }