// 原始稿：03_题目/蓝桥杯/枚举/P12184.cpp
// 原文行号：1-36；恢复外层注释 1 层；保留方法内部注释。
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
        // int ans = 0;
        // for (int b = 0; b <= 255; b++)
        // {
        //     for (int r = 0; r < b; r++)
        //     {
        //         for (int g = 0; g < b; g++)
        //         {
        //             ans++;
        //         }
        //     }
        // }

        int n = 255;
        int ans = n * (n + 1) * (2 * n + 1) / 6;

        cout<<ans<<endl;
    }

    return 0;
}
