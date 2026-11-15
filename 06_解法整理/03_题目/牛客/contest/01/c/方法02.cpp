// 原始稿：03_题目/牛客/contest/01/c.cpp
// 原文行号：65-100；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        vector<int> a(n);
        ll maxx = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (a[i] > maxx)
            {
                maxx = a[i];
            }
        }
        ll sum = maxx * (n - 2) + a[0] + a[n - 1];

        cout<<sum<<endl;
    }

    return 0;
}
