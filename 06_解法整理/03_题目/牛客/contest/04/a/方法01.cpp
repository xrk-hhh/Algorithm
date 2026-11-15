// 原始稿：03_题目/牛客/contest/04/a.cpp
// 原文行号：1-55；恢复外层注释 1 层；保留方法内部注释。
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
        int n;
        cin>>n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                else
                {
                    if (a[i] >= a[j])
                    {
                        cnt++;
                    }
                }
            }
            if (5 * cnt >= 4 * (n - 1))
            {
                sum += a[i];
            }
        }

        cout<<sum<<endl;
    }

    return 0;
}
