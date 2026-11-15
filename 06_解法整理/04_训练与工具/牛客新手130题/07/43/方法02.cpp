// 原始稿：04_训练与工具/牛客新手130题/07/43.cpp
// 原文行号：47-96；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[100010];

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        int minn = 1000000001, maxx = -1000000001;
        ll sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (a[i] > maxx)
            {
                maxx = a[i];
            }
            if (a[i] < minn)
            {
                minn = a[i];
            }

            sum1 += a[i];
        }

        ll ans1 = maxx - minn;

        double avg = sum1 * 1.0 / n;
        double sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum2 += (a[i] - avg) * (a[i] - avg);
        }

        double ans2 = sum2 / n;

        cout<<ans1<<' '<<fixed<<setprecision(3)<<ans2<<endl;
    }

    return 0;
}
