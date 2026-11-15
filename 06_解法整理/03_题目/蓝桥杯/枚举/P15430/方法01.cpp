// 原始稿：03_题目/蓝桥杯/枚举/P15430.cpp
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
        int ans = 0;
        for (int i = 1; i <= 2025; i++)
        {
            for (int d = 1; d <= 1012; d++)
            {
                if (i + 2 * d <= 2025)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }

        cout<<ans * 2<<endl;
    }

    return 0;
}
