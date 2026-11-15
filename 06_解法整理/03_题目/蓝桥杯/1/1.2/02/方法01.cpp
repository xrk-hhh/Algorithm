// 原始稿：03_题目/蓝桥杯/1/1.2/02.cpp
// 原文行号：1-32；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int a, b, x, y;
        cin>>a>>b>>x>>y;

        int cnt = 20;
        for (int i = 0; i <= 20; i++)
        {
            int t1 = max(0, (a - i * y + x - 1) / x);
            int t2 = max(0, (b - i * y + x - 1) / x);
            cnt = min(cnt, t1 + t2 + i);
        }

        cout<<cnt<<endl;
    }

    return 0;
}
