// 原始稿：03_题目/牛客/contest/05/b.cpp
// 原文行号：1-52；恢复外层注释 1 层；保留方法内部注释。
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

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i & 1)
                {
                    if (j & 1)
                    {
                        cout<<'/';
                    }
                    else
                    {
                        cout<<'\\';
                    }
                }
                else
                {
                    if (j & 1)
                    {
                        cout<<'\\';
                    }
                    else
                    {
                        cout<<'/';
                    }
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
