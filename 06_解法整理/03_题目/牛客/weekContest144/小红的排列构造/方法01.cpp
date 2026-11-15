// 原始稿：03_题目/牛客/weekContest144/小红的排列构造.cpp
// 原文行号：1-93；恢复外层注释 1 层；保留方法内部注释。
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
        int n;
        cin>>n;

        vector<int> a(n + 1);
        vector<vector<int>> pos(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
            pos[a[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++)
        {
            // 出现两次以上，直接 pass
            if (pos[i].size() > 2)
            {
                cout<<-1<<endl;
                return 0;
            }
        }

        vector<int> b(n + 1), c(n + 1);
        vector<int> ap, bp, un;
        for (int i = 1; i <= n; i++)
        {
            // 出现两次的数量 p
            if (pos[i].size() == 2)
            {
                int j = pos[i][0], k = pos[i][1];
                b[j] = c[k] = i;
                // c 未填
                ap.push_back(j);
                // b 未填
                bp.push_back(k);
            }
            // 出现一次的数量 q
            else if (pos[i].size() == 1)
            {
                int j = pos[i][0];
                b[j] = c[j] = i;
            }
            // 未出现的数量 r
            else
            {
                un.push_back(i);
            }
        }

        // 则有 位置数 n = 2n + q
        // 又 p + q + r = n
        // 则有 r = p

        // 则 a[i] = b[i]的数量有 p + q
        // 则 a[i] = c[i]的数量有 p + q
        // 而 a[i]种类数有 2p + q，
        // 那么 n/2 即为 p + q/2 <= p + q

        for (int i = 0; i < un.size(); i++)
        {
            int x = un[i];
            c[ap[i]] = b[bp[i]] = x;
        }

        for (int i = 1; i <= n; i++)
        {
            cout<<b[i]<<' ';
        }
        cout<<endl;
        for (int i = 1; i <= n; i++)
        {
            cout<<c[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
