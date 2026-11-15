// 原始稿：03_题目/牛客/contest/03/f.cpp
// 原文行号：1-24；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

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

        cout<<n - 1 + n / 5<<endl;
    }

    return 0;
}
