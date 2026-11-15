// 原始稿：03_题目/牛客/contest/02/a.cpp
// 原文行号：1-39；恢复外层注释 1 层；保留方法内部注释。
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
        ll a[3];
        cin>>a[0]>>a[1]>>a[2];

        sort(a, a + 3);

        ll sum = a[0] + a[1] + a[2];
        int j = sum % 3;

        if ((j == 0 && a[0] == a[1] && a[1] == a[2]) || (j == 1 && a[0] == a[1] && a[2] == a[1] + 1) || (j == 2 && a[1] == a[2] && a[1] == a[0] + 1))
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
