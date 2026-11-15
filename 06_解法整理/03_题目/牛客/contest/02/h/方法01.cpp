// 原始稿：03_题目/牛客/contest/02/h.cpp
// 原文行号：1-53；恢复外层注释 2 层；保留方法内部注释。
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
        int n;
        cin>>n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        unordered_map<ll, ll> mp;

        ll t = 0;

        for (int i = 0; i < n; i++)
        {
            ll num = a[i];
            ll pos = i + 1;

            ll cnt = pos - mp[num];

            ll len = n - pos + 1;
            ll sum = len * (len + 1) / 2;

            t += cnt * sum;

            mp[num] = pos;
        }

        cout<<t<<endl;
    }

    return 0;
}
