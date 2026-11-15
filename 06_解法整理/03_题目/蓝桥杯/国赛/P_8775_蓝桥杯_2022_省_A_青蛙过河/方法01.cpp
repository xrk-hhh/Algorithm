// 原始稿：03_题目/蓝桥杯/国赛/P_8775_蓝桥杯_2022_省_A_青蛙过河.cpp
// 原文行号：1-75；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n;
ll x;
vector<int> h;
vector<int> pre;

bool check(ll y)
{
    // 可直接跳过河
    if (y >= n)
    {
        return true;
    }

    // 最小的区间长度为 y 的区间和
    int minn = 1e9;
    for (int i = 1; i <= n - y; i++)
    {
        int cur = pre[i + y - 1] - pre[i - 1];

        minn = min(minn, cur);
    }

    // 要求所有长度为 y 为的区间高度和均 >= 2x
    return minn >= 2 * x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n>>x;
        h.resize(n);
        for (int i = 1; i < n; i++)
        {
            cin>>h[i];
        }

        pre.resize(n, 0);
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + h[i];
        }

        // 二分答案
        int l = 1, r = n + 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout<<l<<endl;
    }

    return 0;
}
