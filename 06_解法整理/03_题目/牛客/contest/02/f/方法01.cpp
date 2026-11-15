// 原始稿：03_题目/牛客/contest/02/f.cpp
// 原文行号：1-43；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pr pair<ll, ll>

const int mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
    while (b)
    {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while (T--)
    {
        ll n;
        cin>>n;

        ll p = 1LL << 32;
        ll x = n * p;
        ll y = x ^ n;

        cout<<x<<' '<<y<<endl;
    }

    return 0;
}
