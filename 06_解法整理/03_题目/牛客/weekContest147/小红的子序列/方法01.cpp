// 原始稿：03_题目/牛客/weekContest147/小红的子序列.cpp
// 原文行号：1-111；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXX = 1e6 + 10;
int minn[MAXX], len[MAXX], pre[MAXX];
vector<int> prime;

void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (minn[i] == 0)
        {
            minn[i] = i;
            prime.push_back(i);
        }

        for (int p : prime)
        {
            if (p > minn[i] || i * p > n)
            {
                break;
            }

            minn[i * p] = p;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        init(MAXX - 1);

        int n;
        cin>>n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        int maxx = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0, u = 0;
            int t = a[i];
            while (t > 1)
            {
                int p = minn[t];
                while (t % p == 0)
                {
                    t /= p;
                }

                int uu = a[i] / p;
                if (len[uu] > 0 && len[uu] + 1 > cur)
                {
                    cur = len[uu] + 1;
                    u = uu;
                }
            }

            if (cur == 0)
            {
                cur = 1;
            }

            if (cur > len[a[i]])
            {
                len[a[i]] = cur;
                pre[a[i]] = u;
            }
            if (len[a[i]] > maxx)
            {
                maxx = len[a[i]];
                last = a[i];
            }
        }

        vector<int> ans;
        int cur = last;
        while (cur)
        {
            ans.push_back(cur);
            cur = pre[cur];
        }

        reverse(ans.begin(), ans.end());

        cout<<maxx<<endl;
        for (int i = 0; i < maxx; i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
