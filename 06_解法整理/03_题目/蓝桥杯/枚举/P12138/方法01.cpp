// 原始稿：03_题目/蓝桥杯/枚举/P12138.cpp
// 原文行号：1-56；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

bool is_prime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    if (!(n & 1))
    {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int cnt = 0;
        int num = 1;
        while (cnt < 2025)
        {
            if (is_prime(num))
            {
                cnt++;
            }
            num++;
        }

        cout<<num - 1<<endl;
    }

    return 0;
}
