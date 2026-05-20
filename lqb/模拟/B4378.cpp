// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 旋转一层，clockwise=true表示顺时针，false表示逆时针
// void rotateLayer(vector<vector<int>>& mat, int r1, int c1, int r2, int c2, bool clockwise)
// {
//     // 边长 - 1
//     int len = r2 - r1;
//     if (len <= 0)
//     {
//         return;
//     }
//     if (clockwise)
//     {
//         // 顺时针旋转 90°
//         for (int i = 0; i < len; i++)
//         {
//             int tmp = mat[r1][c1 + i];
//             mat[r1][c1 + i] = mat[r2 - i][c1];
//             mat[r2 - i][c1] = mat[r2][c2 - i];
//             mat[r2][c2 - i] = mat[r1 + i][c2];
//             mat[r1 + i][c2] = tmp;
//         }
//     }
//     else
//     {
//         // 逆时针旋转 90°
//         for (int i = 0; i < len; i++)
//         {
//             int tmp = mat[r1][c1 + i];
//             mat[r1][c1 + i] = mat[r1 + i][c2];
//             mat[r1 + i][c2] = mat[r2][c2 - i];
//             mat[r2][c2 - i] = mat[r2 - i][c1];
//             mat[r2 - i][c1] = tmp;
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         int n;
//         cin>>n;

//         // 更为通用的
//         // 顺 90°：(i, j) -> (j, n - 1 - i)
//         // 逆 90°：(i, j) -> (m - 1 - j, j)
//         // 270°：(i, j) -> (n - 1 - i, m - 1 - j)

//         vector<vector<int>> mat(n, vector<int>(n));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 cin>>mat[i][j];
//             }
//         }

//         // 层数
//         int layers = (n + 1) / 2;
//         for (int k = 0; k < layers; k++)
//         {
//             // 左上角(r1, c1)，右下角(r2, c2)
//             int r1 = k, c1 = k, r2 = n - 1 - k, c2 = n - 1 - k;
//             // 中心点
//             if (r1 == r2)
//             {
//                 continue;
//             }
//             // 偶数层为顺(true)，奇数层为逆(false)
//             bool clockwise = !(k & 1);
//             rotateLayer(mat, r1, c1, r2, c2, clockwise);
//         }

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (j)
//                 {
//                     cout<<' ';
//                 }
//                 cout<<mat[i][j];
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }