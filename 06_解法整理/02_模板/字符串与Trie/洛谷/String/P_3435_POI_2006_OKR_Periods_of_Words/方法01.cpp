// 原始稿：02_模板/字符串与Trie/洛谷/String/P_3435_POI_2006_OKR_Periods_of_Words.cpp
// 原文行号：1-58；恢复外层注释 1 层；保留方法内部注释。
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
        string s;
        cin>>n>>s;

        vector<int> nxt(n + 1, 0);
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            while (j > 0 && s[i] != s[j])
            {
                j = nxt[j];
            }

            if (s[i] == s[j])
            {
                j++;
            }

            nxt[i + 1] = j;
        }
        
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            while (nxt[j])
            {
                j = nxt[j];
            }

            if (nxt[i])
            {
                nxt[i] = j;
            }
            ans += i - j;
        }

        cout<<ans<<endl;
    }

    return 0;
}
