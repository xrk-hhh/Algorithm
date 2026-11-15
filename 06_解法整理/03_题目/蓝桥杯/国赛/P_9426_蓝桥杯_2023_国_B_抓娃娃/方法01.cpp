// 原始稿：03_题目/蓝桥杯/国赛/P_9426_蓝桥杯_2023_国_B_抓娃娃.cpp
// 原文行号：1-59；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXX = 2e6 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        // 由于线段长度一定小于区间长度
        // 那么线段至少有一半在区间内
        // 等价于，线段中点在区间内
        // 那么，也就可以使用前缀和进行 “一维点数查询”
        // 注意，线段长度可以为奇数，以至于中点带0.5
        // 为了避免小数，可以将坐标都 * 2
        // 线段中点变为 l+r，区间变为[2L,2R]

        vector<int> cnt(MAXX, 0);
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin>>l>>r;

            int mid = l + r;
            cnt[mid]++;
        }

        vector<int> pre(MAXX, 0);
        for (int i = 1; i < MAXX; i++)
        {
            pre[i] = pre[i - 1] + cnt[i];
        }

        while (m--)
        {
            int l, r;
            cin>>l>>r;

            l <<= 1;
            r <<= 1;

            cout<<pre[r] - pre[l - 1]<<endl;
        }
    }

    return 0;
}
