// 原始稿：03_题目/洛谷/Practice/B_3611_模板_传递闭包.cpp
// 原文行号：1-56；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

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

        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>>a[i][j];
            }
        }

        // Floyd-Warshall 计算传递闭包
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (a[i][k] && a[k][j])
                    {
                        a[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }

    return 0;
}
