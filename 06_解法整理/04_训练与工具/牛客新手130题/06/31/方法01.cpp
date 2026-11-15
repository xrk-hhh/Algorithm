// 原始稿：04_训练与工具/牛客新手130题/06/31.cpp
// 原文行号：1-44；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        bool is_prime = true;
        if (n == 1)
        {
            is_prime = false;
        }
        if (((n & 1) == 0) && (n != 2))
        {
            is_prime = false;
        }
        int x = sqrt(n);
        for (int i = 3; i <= x; i += 2)
        {
            if (n % i == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
