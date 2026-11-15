// 原始稿：03_题目/蓝桥杯/国赛/2026CB/P_16800_蓝桥杯_2026_国_B_方和质数.cpp
// 原文行号：1-79；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

bool check(ll x)
{
    if (x == 1)
    {
        return false;
    }
    if (x == 2)
    {
        return true;
    }
    if (!(x & 1))
    {
        return false;
    }

    for (ll i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
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

        int cnt = 0;
        for (ll i = l; i <= r; i++)
        {
            int t = i;
            int sum = 0;
            while (t)
            {
                sum += t % 10;
                t /= 10;
            }
            int tt = sqrt(sum);
            if (tt * tt == sum)
            {
                if (check(i))
                {
                    cnt++;
                    if (cnt == k)
                    {
                        cout<<i<<endl;
                        return 0;
                    }
                }
            }
        }
        
        cout<<-1<<endl;
    }

    return 0;
}

// 以上为考场做法，素数判断，只能拿下55%分

// 正解是线性筛法（区间筛）
