// 原始稿：03_题目/蓝桥杯/contest/d.cpp
// 原文行号：1-42；恢复外层注释 1 层；保留方法内部注释。
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
        int n;
        cin>>n;

        ll sum = 0;
        int maxx = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;

            sum += x;
            maxx = max(maxx, x);
        }

        if (sum % 5 == 0 && maxx <= sum / 5)
        {
            cout<<'T'<<endl;
        }
        else
        {
            cout<<'F'<<endl;
        }
    }

    return 0;
}
