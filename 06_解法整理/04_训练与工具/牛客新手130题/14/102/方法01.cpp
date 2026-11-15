// 原始稿：04_训练与工具/牛客新手130题/14/102.cpp
// 原文行号：1-38；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll C;
    cin>>N>>C;

    multiset<ll> s;

    while (N--)
    {
        ll x;
        cin>>x;
        s.insert(x);
    }

    ll cnt = 0;

    auto it = s.begin();

    while (it != s.end())
    {
        cnt += s.count(*it + C);
        it++;
    }

    cout<<cnt<<endl;

    return 0;
}
