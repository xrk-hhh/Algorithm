// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;

//     string s;
//     s[0] = 0;
//     int k = 1;
//     for (int i = 1; s.size() <= n; i++)
//     {
//         s += to_string(i);
//     }

//     cout<<s[n - 1];

//     return 0;
// }

// // #include <iostream>
// // #include <string>
// // #include <cmath>

// // using namespace std;

// // int main() 
// // {
// //     long long n;
// //     cin >> n;

// //     long long digits = 1;      // 当前处理的数字的位数
// //     long long count = 9;       // 当前位数下有多少个不同的数字
// //     long long start_num = 1;   // 当前位数下的起始数字

// //     while (n > digits * count) 
// //     {
// //         n -= digits * count;
// //         digits++;
// //         count *= 10;
// //         start_num *= 10;
// //     }

// //     // 确定目标字符所在的具体数字
// //     long long target_num = start_num + (n - 1) / digits;

// //     // 确定目标字符在该数字的第几位 (0-based)
// //     long long digit_index = (n - 1) % digits;

// //     // 提取该位数字
// //     string s_num = to_string(target_num);
// //     cout << s_num[digit_index] << endl;

// //     return 0;
// // }
