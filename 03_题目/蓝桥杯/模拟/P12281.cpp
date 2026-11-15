// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;
//     // 忽略第一行末尾换行
//     cin.ignore();

//     string s;
//     // 光标位置， 0表示最左，s.size()表示最右
//     int pos = 0;

//     while (T--)
//     {
//         string op;
//         getline(cin, op);

//         // 移动操作
//         if (op[0] >= '0' && op[0] <= '9')
//         {
//             int n = 0;
//             int idx = 0;
//             while (op[idx] >= '0' && op[idx] <= '9')
//             {
//                 n = n * 10 + op[idx] - '0';
//                 idx++;
//             }
//             char c = op[idx];
//             // 左移
//             if (c == 'h')
//             {
//                 pos = max(0, pos - n);
//             }
//             // 右移
//             else
//             {
//                 pos = min((int)s.size(), pos + n);
//             }
//         }
//         // 删除操作
//         else if (op[0] == 'd')
//         {
//             int n = 0;
//             int idx = 1;
//             while (op[idx] >= '0' && op[idx] <= '9')
//             {
//                 n = n * 10 + op[idx] - '0';
//                 idx++;
//             }
//             char c = op[idx];
//             // 删除左侧
//             if (c == 'h')
//             {
//                 int del = min(pos, n);
//                 s.erase(pos - del, del);
//                 pos -= del;
//             }
//             // 删除右侧
//             else
//             {
//                 int del = min(n, (int)s.size() - pos);
//                 s.erase(pos, del);
//             }
//         }
//         // 插入操作
//         else
//         {
//             size_t first = op.find('"');
//             size_t last = op.rfind('"');
//             string text = op.substr(first + 1, last - first - 1);
//             s.insert(pos, text);
//             pos += text.size();
//         }
//     }

//     cout<<s<<endl;

//     return 0;
// }