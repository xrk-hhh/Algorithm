// 原始稿：03_题目/洛谷/Contest/44/D.cpp
// 原文行号：1-48；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        int k;
        cin>>k;

        if (a[k] == 0)
        {
            cout<<k<<endl;
            return 0;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 0)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
