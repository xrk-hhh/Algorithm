// 原始稿：03_题目/蓝桥杯/国赛/P_12225_蓝桥杯_2023_国_Java_B_游戏.cpp
// 原文行号：1-87；恢复外层注释 1 层；保留方法内部注释。
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
        int n, k;
        cin>>n>>k;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        // 单调队列解决滑动窗口最值问题
        deque<int> dq;
        // 所有窗口的最大值之和
        ll sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            // 移除窗口外的过期元素
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            // 维护单调队列（队首最大）
            while (!dq.empty() && a[dq.back()] <= a[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            // 窗口形成时记录最大值
            if (i >= k - 1)
            {
                sum1 += a[dq.front()];
            }
        }

        dq.clear();
        // 所有窗口的最小值之和
        ll sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            // 维护单调队列（队首最小）
            while (!dq.empty() && a[dq.back()] >= a[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k - 1)
            {
                sum2 += a[dq.front()];
            }
        }

        // 窗口总个数
        ll m = n - k + 1;
        // 最大值平均数（期望）
        double avg1 = (double)sum1 / m;
        // 最小值平均数（期望）
        double avg2 = (double) sum2 / m;
        // 最大值与最小值两者独立操作，则 E(P - Q) = E(P) - E(Q)
        double ans = avg1 - avg2;

        cout<<fixed<<setprecision(2)<<ans<<endl;
    }

    return 0;
}
