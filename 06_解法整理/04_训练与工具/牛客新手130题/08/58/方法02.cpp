// 原始稿：04_训练与工具/牛客新手130题/08/58.cpp
// 原文行号：22-56；恢复外层注释 2 层；保留方法内部注释。
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() 
{
    long long n;
    cin >> n;

    long long digits = 1;      // 当前处理的数字的位数
    long long count = 9;       // 当前位数下有多少个不同的数字
    long long start_num = 1;   // 当前位数下的起始数字

    while (n > digits * count) 
    {
        n -= digits * count;
        digits++;
        count *= 10;
        start_num *= 10;
    }

    // 确定目标字符所在的具体数字
    long long target_num = start_num + (n - 1) / digits;

    // 确定目标字符在该数字的第几位 (0-based)
    long long digit_index = (n - 1) % digits;

    // 提取该位数字
    string s_num = to_string(target_num);
    cout << s_num[digit_index] << endl;

    return 0;
}
