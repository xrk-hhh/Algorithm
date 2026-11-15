// 原始稿：03_题目/蓝桥杯/国赛/P_10576_蓝桥杯_2024_国_A_儿童节快乐.cpp
// 原文行号：1-101；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
using i128 = __int128;

const ll t = 10120300500;

// 输出 i128 
void print(i128 x)
{
    if (x == 0)
    {
        cout<<0<<endl;
        return;
    }

    if (x < 0)
    {
        cout<<'-';
        x = -x;
    }

    string s;
    while (x)
    {
        s.push_back(x % 10 + '0');
        x /= 10;
    }

    reverse(s.begin(), s.end());

    cout<<s<<endl;
}

i128 ksm(i128 a, int b)
{
    i128 res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        i128 M = t >> 1;
        vector<pair<i128, int>> fac;
        i128 tmp = M;
        // 对 M 分解质因数
        for (i128 p = 2; p * p <= tmp; p++)
        {
            if (tmp % p == 0)
            {
                int cnt = 0;
                while (tmp % p == 0)
                {
                    tmp /= p;
                    cnt++;
                }
                fac.push_back({p, cnt});
            }
        }
        if (tmp > 1)
        {
            fac.push_back({tmp, 1});
        }

        i128 ans = 1;
        // 积性函数
        for (auto binding_value_01 : fac)
        {
            auto p = binding_value_01.first;
            auto e = binding_value_01.second;
            i128 term = 0;
            for (int i = 0; i <= e; i++)
            {
                term += ksm(p, i << 1);
            }

            ans *= term;
        }

        print(ans);
    }

    return 0;
}
