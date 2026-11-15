// 原始稿：03_题目/牛客/weekContest140/小红的三角形构造.cpp
// 原文行号：1-46；恢复外层注释 1 层；保留方法内部注释。
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
        ll x;
        cin>>x;

        if (x == 1 || x == 2)
        {
            cout<<"No"<<endl;
            continue;
        }

        cout<<"Yes"<<endl;

        if (x & 1)
        {
            ll b = (x * x - 1) >> 1;
            ll c = (x * x + 1) >> 1;

            cout<<x<<' '<<b<<' '<<c<<endl;
        }
        else
        {
            ll t = x >> 1;
            ll b = t * t - 1;
            ll c = t * t + 1;

            cout<<x<<' '<<b<<' '<<c<<endl;
        }
    }

    return 0;
}
