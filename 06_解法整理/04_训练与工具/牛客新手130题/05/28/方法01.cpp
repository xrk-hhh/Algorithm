// 原始稿：04_训练与工具/牛客新手130题/05/28.cpp
// 原文行号：1-36；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin>>num;

    int month = num % 100;

    switch(month)
    {
        case 3:
        case 4:
        case 5:
            cout<<"spring";
            break;
        case 6:
        case 7:
        case 8:
            cout<<"summer";
            break;
        case 9:
        case 10:
        case 11:
            cout<<"autumn";
            break;
        case 12:
        case 1:
        case 2:
            cout<<"winter";
            break;
    }

    return 0;
}
