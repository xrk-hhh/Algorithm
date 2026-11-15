// 原始稿：03_题目/洛谷/Contest/44/A.cpp
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
    // cin>>T;

    while (T--)
    {
        int k, m;
        cin>>k>>m;

        cout<<(m / k - 1) / 2<<endl;;
    }

    return 0;
}
