// 原始稿：03_题目/牛客/contest/03/a.cpp
// 原文行号：1-41；恢复外层注释 1 层；保留方法内部注释。
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
        int x;
        cin>>x;

        bool check = false;
        for (int i = 1; i <= 9; i++)
        {
            if (x == i * (i + 1))
            {
                check = true;
                break;
            }
        }

        if (check)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
