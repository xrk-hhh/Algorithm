// 原始稿：04_训练与工具/牛客新手130题/04/12.cpp
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int num;
    // cin>>num;

    // int ge, shi, bai, qian;
    // ge = num % 10;
    // num /= 10;
    // shi = num% 10;
    // num /= 10;
    // bai = num % 10;
    // num /= 10;
    // qian = num % 10;
    // cout<<ge<<shi<<bai<<qian;

    // 以上为分别求出个、十、百、千位，再逆向输出

    // 以下为字符串顺序输入与逆序输出
    string s;
    cin>>s;

    for (int i = 3; i >= 0; i--)
    {
        cout<<s[i];
    }

    return 0;
}
