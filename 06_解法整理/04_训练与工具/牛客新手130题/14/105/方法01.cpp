// 原始稿：04_训练与工具/牛客新手130题/14/105.cpp
// 原文行号：1-37；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while (T--)
    {

        set<int> s;

        int n;
        cin>>n;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;

            if (!s.count(x))
            {
                cout<<x<<' ';
                s.insert(x);
            }
        }
        cout<<endl;
    }

    return 0;
}
