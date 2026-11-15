// 原始稿：03_题目/蓝桥杯/contest/c.cpp
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        ll n, x ,y;
        cin>>n>>x>>y;

        if (x > y)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<y - x + 1<<endl;
        }
    }

    return 0;
}
