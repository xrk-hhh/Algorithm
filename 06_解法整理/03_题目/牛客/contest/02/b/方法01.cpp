// 原始稿：03_题目/牛客/contest/02/b.cpp
// 原文行号：1-81；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

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

        int maxx = 0;

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (a[i] > maxx)
            {
                maxx = a[i];
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == maxx)
            {
                cnt++;
            }
        }

        for (int i = 0; i< n; i++)
        {
            if (cnt & 1)
            {
                if (a[i] == maxx)
                {
                    cout<<'1';
                }
                else
                {
                    cout<<'0';
                }
            }
            else
            {
                if (cnt == n)
                {
                    cout<<'0';
                }
                else
                {
                    if (a[i] == maxx)
                    {
                        cout<<'0';
                    }
                    else
                    {
                        cout<<'1';
                    }
                }
            }
        }

        cout<<endl;
    }

    return 0;
}
