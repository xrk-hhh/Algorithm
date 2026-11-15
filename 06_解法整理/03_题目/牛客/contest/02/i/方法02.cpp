// 原始稿：03_题目/牛客/contest/02/i.cpp
// 原文行号：130-202；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        vector<vector<char>> a(n, vector<char>(m));

        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>a[i][j];
                if (a[i][j] == '0')
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '0')
                {
                    if (cnt0 >= 2)
                    {
                        cout<<'Y';
                    }
                    else
                    {
                        cout<<'N';
                    }
                }
                else
                {
                    if (cnt1 >= 2)
                    {
                        cout<<'Y';
                    }
                    else
                    {
                        cout<<'N';
                    }
                }
            }
            cout<<endl;
        }
    }

    return 0;
}
