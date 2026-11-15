// 原始稿：02_模板/二分与分数规划/洛谷/ErFen/ChaZhao/P2249.cpp
// 原文行号：1-58；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m;
        cin>>n>>m;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        while (m--)
        {
            int q;
            cin>>q;

            int l = 0, r = n + 1;
            while (l + 1 < r)
            {
                int mid = (l + r) >> 1;

                if (a[mid] >= q)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }

            if (a[r] == q)
            {
                cout<<r<<' ';
            }
            else
            {
                cout<<-1<<' ';
            }
        }
    }

    return 0;
}
