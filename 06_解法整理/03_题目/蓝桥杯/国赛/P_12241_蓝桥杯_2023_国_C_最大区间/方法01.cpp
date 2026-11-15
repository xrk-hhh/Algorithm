// 原始稿：03_题目/蓝桥杯/国赛/P_12241_蓝桥杯_2023_国_C_最大区间.cpp
// 原文行号：1-66；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        // l[i]：i 位置左边第一个比 a[i]小的元素的位置
        // r[i]：i 位置右边第一个比 a[i]小的元素的位置
        vector<int> l(n, -1), r(n, n);
        // 单调栈求解
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[st.top()] > a[i])
            {
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && a[st.top()] > a[i])
            {
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int len = r[i] - l[i] - 1;
            // 贡献：区间长度 * 区间最小值
            ans = max(ans, 1LL * a[i] * len);
        }

        cout<<ans<<endl;
    }

    return 0;
}
