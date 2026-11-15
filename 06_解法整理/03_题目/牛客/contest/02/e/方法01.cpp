// 原始稿：03_题目/牛客/contest/02/e.cpp
// 原文行号：1-45；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<vector<char>> a(n + 1, vector<char>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int minn = min(i, j);
            if (minn & 1)
            {
                a[i][j] = '0';
            }
            else
            {
                a[i][j] = '1';
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}
