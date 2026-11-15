// 原始稿：03_题目/蓝桥杯/枚举/P12377.cpp
// 原文行号：1-50；恢复外层注释 1 层；保留方法内部注释。
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
        int ans = 0;
        string ss = "2023";
        for (int i = 12345678; i <= 98765432; i++)
        {
            string s;
            int x = i;
            while (x)
            {
                s += (x % 10) + '0';
                x /= 10;
            }
            int cnt = 0;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == ss[cnt])
                {
                    cnt++;
                    if (cnt == 4)
                    {
                        break;
                    }
                }
            }
            if (cnt != 4)
            {
                ans++;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
