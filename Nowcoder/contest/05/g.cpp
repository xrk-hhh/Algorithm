// // #include <iostream>
// // #include <string>
// // #include <vector>

// // using namespace std;

// // // 定义操作的置换函数
// // int applyOp(int state, int op) {
// //     // 状态映射：0:右上,1:右下,2:左下,3:左上
// //     switch(op) {
// //         case 0: // 垂直翻转
// //             return 3 - state; // 0<->3, 1<->2
// //         case 1: // 副对角线翻转（\）
// //             return (4 - state) % 4; // 等价于 -state mod 4
// //         case 2: // 水平翻转
// //             return state ^ 1; // 0<->1, 2<->3
// //         case 3: // 主对角线翻转（/）
// //             if (state == 0) return 2;
// //             if (state == 1) return 1;
// //             if (state == 2) return 0;
// //             if (state == 3) return 3;
// //             break;
// //         case 4: // 顺时针旋转90度
// //             return (state + 1) % 4;
// //         case 5: // 逆时针旋转90度
// //             return (state + 3) % 4; // 等价于 state-1 mod 4
// //         default:
// //             return state;
// //     }
// //     return state;
// // }

// // int main() {
// //     // 假设操作序列通过标准输入给出，为一个长度为100的字符串，仅包含'0'~'5'
// //     // 如果输入为空，则默认使用重复"012345"直到100次
// //     string op_str;
// //     if (!(cin >> op_str)) {
// //         // 没有输入，构造重复序列
// //         op_str = "";
// //         for (int i = 0; i < 100; ++i) {
// //             op_str.push_back('0' + (i % 6));
// //         }
// //     }
// // // 链接：https://ac.nowcoder.com/acm/contest/120565/G
// // // 来源：牛客网

// // // 0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532
// //     // 确保长度为100
// //     if (op_str.length() != 100) {
// //         // 如果不满足，可以截断或循环，这里按需处理
// //         // 简单起见，如果长度不足，重复最后一个字符；如果过长，截断
// //         if (op_str.length() < 100) {
// //             while (op_str.length() < 100) op_str += op_str.back();
// //         } else {
// //             op_str = op_str.substr(0, 100);
// //         }
// //     }

// //     int state = 0; // 初始状态
// //     string ans;
// //     for (char ch : op_str) {
// //         int op = ch - '0';
// //         state = applyOp(state, op);
// //         ans.push_back('0' + state);
// //     }

// //     cout << ans << endl;
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";

//         int way = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             char c = s[i];
//             if (c == '0')
//             {
//                 if (way == 0)
//                 {
//                     way = 3;
//                 }
//                 else if (way == 1)
//                 {
//                     way = 2;
//                 }
//                 else if (way == 2)
//                 {
//                     way = 1;
//                 }
//                 else if (way == 3)
//                 {
//                     way = 0;
//                 }
//             }
//             else if (c == '1')
//             {
//                 if (way == 0)
//                 {
//                     way = 0;
//                 }
//                 else if (way == 1)
//                 {
//                     way = 3;
//                 }
//                 else if (way == 2)
//                 {
//                     way = 2;
//                 }
//                 else if (way == 3)
//                 {
//                     way = 1;
//                 }
//             }
//             else if (c == '2')
//             {
//                 if (way == 0)
//                 {
//                     way = 1;
//                 }
//                 else if (way == 1)
//                 {
//                     way = 0;
//                 }
//                 else if (way == 2)
//                 {
//                     way = 3;
//                 }
//                 else if (way == 3)
//                 {
//                     way = 2;
//                 }
//             }
//             else if (c == '3')
//             {
//                 if (way == 0)
//                 {
//                     way = 2;
//                 }
//                 else if (way == 1)
//                 {
//                     way = 1;
//                 }
//                 else if (way == 2)
//                 {
//                     way = 0;
//                 }
//                 else if (way == 3)
//                 {
//                     way = 3;
//                 }
//             }
//             else if (c == '4')
//             {
//                 if (way == 0)
//                 {
//                     way = 1;
//                 }
//                 else if (way == 1)
//                 {
//                     way = 2;
//                 }
//                 else if (way == 2)
//                 {
//                     way = 3;
//                 }
//                 else if (way == 3)
//                 {
//                     way = 0;
//                 }
//             }
//             else if (c == '5')
//             {
//                 if (way == 0)
//                 {
//                     way = 3;
//                 }
//                 else if (way == 1)
//                 {
//                     way = 0;
//                 }
//                 else if (way == 2)
//                 {
//                     way = 1;
//                 }
//                 else if (way == 3)
//                 {
//                     way = 2;
//                 }
//             }
//             cout<<way;
//         }
//         cout<<endl;
//     }

//     return 0;
// }