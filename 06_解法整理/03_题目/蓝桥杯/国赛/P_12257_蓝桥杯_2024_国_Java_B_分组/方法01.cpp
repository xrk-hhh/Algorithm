// 原始稿：03_题目/蓝桥杯/国赛/P_12257_蓝桥杯_2024_国_Java_B_分组.cpp
// 原文行号：1-71；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int n;
vector<int> a;

bool check(int x)
{
    for (int i = 0; i < x; i++)
    {
        // a[0],a[1],..,a[x-1] 与 a[n-x],a[n-x+1],...,a[n-1] 一一配对
        // 即最小的 x 个与最大的 x 个配对
        if (a[n - x + i] < (a[i] << 1))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        sort(a.begin(), a.end());

        // 特判一下，(全局 max < min * 2) 和 (n < 2)
        if ((a[n - 1] < (a[0] << 1)) || n < 2)
        {
            cout<<0<<endl;
            return 0;
        }

        // 二分答案
        int l = 1, r = n >> 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout<<r<<endl;
    }

    return 0;
}
