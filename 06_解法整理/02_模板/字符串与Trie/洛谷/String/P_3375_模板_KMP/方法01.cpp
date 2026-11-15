// 原始稿：02_模板/字符串与Trie/洛谷/String/P_3375_模板_KMP.cpp
// 原文行号：1-67；恢复外层注释 1 层；保留方法内部注释。
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
        string s, p;
        cin>>s>>p;

        int n = s.size(), m = p.size();

        // 计算 next 数组
        vector<int> nxt(m + 1, 0);
        int j = 0;
        for (int i = 1; i < m; i++)
        {
            while (j > 0 && p[i] != p[j])
            {
                j = nxt[j];
            }

            if (p[i] == p[j])
            {
                j++;
            }

            nxt[i + 1] = j;
        }

        // 匹配
        j = 0;
        for (int i = 0; i < n; i++)
        {
            while (j > 0 && s[i] != p[j])
            {
                j = nxt[j];
            }

            if (s[i] == p[j])
            {
                j++;
            }
            if (j == m)
            {
                cout<<i - m + 2<<endl;
                j = nxt[j];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            cout<<nxt[i]<<' ';
        }
    }

    return 0;
}
