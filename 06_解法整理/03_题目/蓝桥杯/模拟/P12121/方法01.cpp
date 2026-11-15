// 原始稿：03_题目/蓝桥杯/模拟/P12121.cpp
// 原文行号：1-49；恢复外层注释 1 层；保留方法内部注释。
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
        ll num;
        cin>>num;

        for (int x = 11; x <= 36; x++)
        {
            vector<int> ans;
            ll t = num;
            // 整数进制转换
            // 采用 除 x 取余
            while (t)
            {
                ans.push_back(t % x);
                t /= x;
            }
            bool ok = true;
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] >= 10)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout<<x<<endl;
                return 0;
            }
        }
    }

    return 0;
}
