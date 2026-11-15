// 原始稿：03_题目/蓝桥杯/国赛/luogu_imitation/T_736500_盆栽.cpp
// 原文行号：1-52；恢复外层注释 1 层；保留方法内部注释。
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

        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        while (m--)
        {
            int k;
            cin>>k;

            // 考虑贡献：在[l,r]内的贡献为 a[i]异或k，[l,r]外的贡献为 a[i]
            // 可以考虑变化量，则只有[l,r]内的有贡献，即为 dif= a[i]异或k - a[i]
            // 那么，所求即变为求 最小子段和 和 最大子段和
            ll maxx = 0, minn = 0;
            ll curx = 0, curn = 0;
            for (int i = 0; i < n; i++)
            {
                ll dif = (a[i] ^ k) - a[i];
                curx = max(0LL, curx + dif);
                curn = min(0LL, curn + dif);
                maxx = max(maxx, curx);
                minn = min(minn, curn);
            }

            cout<<sum + minn<<' '<<sum + maxx<<endl;
        }
    }

    return 0;
}
