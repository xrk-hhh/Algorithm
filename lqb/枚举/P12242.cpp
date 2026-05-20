// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         vector<string> s =
//         {
//             "1101011111",
//             "1110011110",
//             "1100101111",
//             "1011011110",
//             "1010111100",
//             "1001010101",
//             "1111111110",
//             "0111111110",
//             "0110101111",
//             "1010010100",
//         };

//         vector<vector<bool>> ok(10, vector<bool>(10, false));
//         for (int i = 0; i < 10; i++)
//         {
//             for (int j = 0; j < 10; j++)
//             {
//                 if (s[i][j] == '1')
//                 {
//                     ok[i][j] = true;
//                 }
//             }
//         }

//         set<int> st;
//         for (int x1 = 0; x1 < 10; x1++)
//         {
//             for (int y1 = 0; y1 < 10; y1++)
//             {
//                 if (!ok[x1][y1])
//                 {
//                     continue;
//                 }
//                 for (int x2 = 0; x2 < 10; x2++)
//                 {
//                     for (int y2 = 0; y2 < 10; y2++)
//                     {
//                         if (x1 == x2 && y1 == y2)
//                         {
//                             continue;
//                         }
//                         if (!ok[x2][y2])
//                         {
//                             continue;
//                         }
//                         // AB向量坐标
//                         int dx = x2 - x1;
//                         int dy = y2 - y1;
                        
//                         // 逆时针旋转90°(-dy, dx)
//                         int x3 = x1 - dy;
//                         int y3 = y1 + dx;
//                         int x4 = x2 - dy;
//                         int y4 = y2 + dx;
//                         if (x3 >= 0 && x3 < 10 && y3 >= 0 && y3 < 10 && x4 >= 0 && x4 < 10 && y4 >= 0 && y4 < 10 && ok[x3][y3] && ok[x4][y4])
//                         {
//                             st.insert(dx * dx + dy * dy);
//                         }

//                         // 顺时针旋转90°(dy, -dx)
//                         x3 = x1 + dy;
//                         y3 = y1 - dx;
//                         x4 = x2 + dy;
//                         y4 = y2 - dx;
//                         if (x3 >= 0 && x3 < 10 && y3 >= 0 && y3 < 10 && x4 >= 0 && x4 < 10 && y4 >= 0 && y4 < 10 && ok[x3][y3] && ok[x4][y4]) 
//                         {
//                             st.insert(dx * dx + dy * dy);
//                         }
//                     }
//                 }
//             }
//         }

//         cout<<st.size()<<endl;
//     }

//     return 0;
// }