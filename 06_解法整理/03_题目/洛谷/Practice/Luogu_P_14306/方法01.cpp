// 原始稿：03_题目/洛谷/Practice/Luogu_P_14306.cpp
// 原文行号：1-47；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3fll

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin>>c;

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n, k;
        cin>>n>>k;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }

        sort(a.begin(), a.end());

        ll minn = INF;
        ll ans = -INF;

        for (int i = 1; i <= n; i++)
        {
            ll tmp = 1LL * i * k - a[i];
            minn = min(tmp, minn);
            ans = max(ans, tmp - minn + k);
        }

        cout<<ans<<endl;
    }

    return 0;
}
