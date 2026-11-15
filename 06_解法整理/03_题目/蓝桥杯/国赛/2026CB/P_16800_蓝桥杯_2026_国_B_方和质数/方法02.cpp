// 原始稿：03_题目/蓝桥杯/国赛/2026CB/P_16800_蓝桥杯_2026_国_B_方和质数.cpp
// 原文行号：80-162；恢复外层注释 0 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

bool check(ll x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum == 1 || sum == 4 || sum == 9 || sum == 16 || sum == 25 || sum == 36 || sum == 49 || sum == 64 || sum == 81 || sum == 100;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        ll l, r, k;
        cin>>l>>r>>k;

        int sq = sqrt(r);
        vector<bool> isP(sq + 1, true);
        vector<int> prime;
        for (int i = 2; i <= sq; i++)
        {
            if (isP[i])
            {
                prime.push_back(i);

                for (ll j = 1LL * i * i; j <= sq; j += i)
                {
                    isP[j] = false;
                }
            }
        }

        int len = r - l + 1;
        vector<bool> ok(len, true);
        if (l == 1)
        {
            ok[0] = false;
        }

        for (int p : prime)
        {
            ll start = max(1LL * p * p, ((l + p - 1) / p) * p);

            for (ll j = start; j <= r; j += p)
            {
                ok[j - l] = false;
            }
        }

        int cnt = 0;
        for (ll i = l; i <= r; i++)
        {
            if (ok[i - l] && check(i))
            {
                cnt++;
                if (cnt == k)
                {
                    cout<<i<<endl;
                    return 0;
                }
            }
        }

        cout<<-1<<endl;
    }

    return 0;
}
