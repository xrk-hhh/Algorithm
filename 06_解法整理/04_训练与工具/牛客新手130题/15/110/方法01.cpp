// 原始稿：04_训练与工具/牛客新手130题/15/110.cpp
// 原文行号：1-34；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    multiset<int> a;

    while (n--)
    {
        int x;
        cin>>x;
        a.insert(x);
    }
    while (m--)
    {
        int b;
        cin>>b;
        int x = *a.begin();
        a.erase(a.find(x));
        a.insert(x + b);
        cout<<*--a.end()<<endl;
    }

    return 0;
}
