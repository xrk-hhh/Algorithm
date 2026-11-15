// 原始稿：03_题目/蓝桥杯/模拟/P8781.cpp
// 原文行号：1-34；恢复外层注释 1 层；保留方法内部注释。
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

        for (int i = 1; i <= n; i++)
        {
            // 从左往右
            int a1 = i - 1;
            // 从右往左
            int a2 = n - i;
            // 来回
            int ans = max(a1, a2) * 2;

            cout<<ans<<endl;
        }
    }

    return 0;
}
