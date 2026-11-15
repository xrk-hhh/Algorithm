// 原始稿：04_训练与工具/牛客新手130题/07/43.cpp
// 原文行号：1-46；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
        ll sum2 = 0.0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin>>num;
            if (num > maxx)
            {
                maxx = num;
            }
            if (num < minn)
            {
                minn = num;
            }

            sum1 += num;
            sum2 += num * num;
        }

        ll ans1 = maxx - minn;

        double avg = sum1 * 1.0 / n;
        double ans2 = sum2 * 1.0 / n - avg * avg;

        cout<<ans1<<' '<<fixed<<setprecision(3)<<ans2<<endl;
    }

    return 0;
}
