// 原始稿：04_训练与工具/牛客新手130题/08/54.cpp
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

bool can_eat(string s1, string s2)
{
    return (s1 == "elephant" && s2 == "tiger") || 
    (s1 == "tiger" && s2 == "cat") || 
    (s1 == "cat" && s2 == "mouse") || 
    (s1 == "mouse" && s2 == "elephant");
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;

    if (can_eat(s1, s2))
    {
        cout<<"win";
    }
    else if (can_eat(s2, s1))
    {
        cout<<"lose";
    }
    else
    {
        cout<<"tie";
    }

    return 0;
}
