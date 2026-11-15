// 原始稿：03_题目/牛客/contest/04/g.cpp
// 原文行号：1-54；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

// ll f(ll x)
// {
//     if (x == 0)
//     {
//         return x;
//     }

//     if ((x / 10) == 0)
//     {
//         return x;
//     }
//     ll res = 1;
//     while (x)
//     {
//         res *= (x % 10);
//         x /= 10;
//     }
//     return res;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        // int cnt = 0;

        // ll x = 99999999998777772;
        // ll x = 9988888877777721;
        // ll x = 277777788888899;
        // // ll x =  3778888999;
        // while (x != f(x))
        // {
        //     x = f(x);
        //     cnt++;
        // }
        // cout<<cnt<<endl;

        cout<<277777788888899<<' '<<99999999998777772<<endl;
    }

    return 0;
}
