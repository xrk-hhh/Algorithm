// 原始稿：03_题目/蓝桥杯/国赛/P_12208_蓝桥杯_2023_国_Python_B_偶串.cpp
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
        string s;
        cin>>s;

        int n = s.size();

        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
        }

        bool ok = true;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] & 1)
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
