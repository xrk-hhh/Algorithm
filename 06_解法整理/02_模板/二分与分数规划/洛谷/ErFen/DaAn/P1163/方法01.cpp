// 原始稿：02_模板/二分与分数规划/洛谷/ErFen/DaAn/P1163.cpp
// 原文行号：1-49；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int w0, w, m;
        cin>>w0>>w>>m;

        auto check = [&](double x) -> bool
        {
            double s = w0;
            for (int i = 1; i <= m; i++)
            {
                s = s * (1 + x) - w;
            }

            return s >= 0;
        };

        double l = 0, r = 10;
        while (r - l > 1e-5)
        {
            double mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        cout<<fixed<<setprecision(1)<<r * 100<<endl;
    }

    return 0;
}
