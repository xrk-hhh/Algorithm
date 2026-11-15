// 原始稿：03_题目/牛客/contest/02/f.cpp
// 原文行号：44-78；恢复外层注释 1 层；保留方法内部注释。
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
        ll n;
        cin>>n;

        ll L = 1;
        while (L <= n)
        {
            L <<= 1;
        }

        ll x = n * L;
        ll y = n * (L + 1);

        cout<<x<<' '<<y<<endl;
    }

    return 0;
}
