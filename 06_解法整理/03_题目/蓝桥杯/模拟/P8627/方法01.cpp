// 原始稿：03_题目/蓝桥杯/模拟/P8627.cpp
// 原文行号：1-37；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        int cur = 0;
        int ans = 0;
        while (n--)
        {
            cur++;
            if (cur == 3)
            {
                n++;
                cur = 0;
            }
            ans++;
        }

        cout<<ans<<endl;
    }

    return 0;
}
