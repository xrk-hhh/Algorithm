// 原始稿：03_题目/牛客/weekContest147/小红打舞萌.cpp
// 原文行号：1-27；恢复外层注释 1 层；保留方法内部注释。
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
        int x;
        cin>>x;

        ll cnt = x / 5;
        ll ans = (cnt + 1) / 2 * 4 + cnt / 2 * 3;
        
        cout<<ans<<endl;
    }

    return 0;
}
