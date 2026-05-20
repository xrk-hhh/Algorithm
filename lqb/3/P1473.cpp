// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// vector<string> ans;


// // 1 2 3 4 5 6 7
// // 两个数之间有三种可能
// // 空格(' ') / 加号('+') / 减号('-')
// // 使用 DFS 枚举
// // 需要注意的是，在这三者中 ASCII码顺序为： ' ' > '+' > '-'

// // num: 下一个要处理的数字（从2开始）
// // sum: 当前已计算的部分和（不包括最后一个操作数last）
// // last: 当前累积的最后一个操作数（带符号）
// // s: 当前构造的表达式字符串
// void dfs(int num, int sum, int last, string s)
// {
//     if (num > n)
//     {
//         if (sum + last == 0)
//         {
//             ans.push_back(s);
//         }
//         return;
//     }

//     // 先尝试空格（ASCII最小）
//     int new_last = last * 10 + (last > 0 ? num : -num);
//     dfs(num + 1, sum, new_last, s + ' ' + to_string(num));

//     // 再尝试加号
//     dfs(num + 1, sum + last, num, s + '+' + to_string(num));

//     // 最后尝试减号
//     dfs(num + 1, sum + last, -num, s + '-' + to_string(num));
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;

//         dfs(2, 0, 1, "1");

//         for (string s : ans)
//         {
//             cout<<s<<endl;
//         }
//     }

//     return 0;
// }