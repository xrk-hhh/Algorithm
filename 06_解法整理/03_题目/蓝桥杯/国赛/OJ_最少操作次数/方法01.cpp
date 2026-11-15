// 原始稿：03_题目/蓝桥杯/国赛/OJ_最少操作次数.cpp
// 原文行号：1-52；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> a(n );
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        // 经典区间减 1 操作
        // 差分思想
        // 每当需要比前一个位置多减一些次数时，就必须新开一个（或多个）操作来覆盖这个增量

        // 每次操作可以视为在高度图的一行上涂抹一条横线
        // 最少操作次数等于高度图的 轮廓线 总上升量，即对相邻高度差取正数求和
        // 这与经典的 用最少的水平线段覆盖直方图 问题一致

        ll ans = 0;
        // d[i-1]，初始 d[-1]=0
        int prev = 0;
        for (int x : a)
        {
            int cur = x - 1;
            if (cur > prev)
            {
                ans += cur - prev;
            }

            prev = cur;
        }

        cout<<ans<<endl;
    }

    return 0;
}
