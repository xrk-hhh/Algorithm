// 原始稿：03_题目/牛客/contest/02/a.cpp
// 原文行号：40-74；恢复外层注释 1 层；保留方法内部注释。
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
        int a[3];
        cin>>a[0]>>a[1]>>a[2];

        sort(a, a + 3);

        if (a[0] + 1 >= a[2])
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
