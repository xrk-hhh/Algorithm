// 原始稿：03_题目/牛客/weekContest142/小苯的区间操作.cpp
// 原文行号：1-48；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            // 存在唯一极大值，则不合法
            if (a[i] > a[i + 1] && a[i] > a[i - 1])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
