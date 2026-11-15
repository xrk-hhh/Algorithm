// 原始稿：03_题目/蓝桥杯/国赛/OJ_前缀异或和.cpp
// 原文行号：1-38；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m;
        cin>>n>>m;

        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;
            pre[i] = pre[i - 1] ^ x;
        }

        while (m--)
        {
            int l, r;
            cin>>l>>r;

            cout<<(pre[r] ^ pre[l - 1])<<endl;
        }
    }

    return 0;
}
