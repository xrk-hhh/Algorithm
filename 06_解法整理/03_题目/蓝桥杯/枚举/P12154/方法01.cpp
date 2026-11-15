// 原始稿：03_题目/蓝桥杯/枚举/P12154.cpp
// 原文行号：1-32；恢复外层注释 1 层；保留方法内部注释。
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
        int ans = 0;
        for (int i = 1; i <= 2025; i++)
        {
            int x = i % 10;
            int t = x * x * x;
            if (t % 10 == 3)
            {
                ans++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
