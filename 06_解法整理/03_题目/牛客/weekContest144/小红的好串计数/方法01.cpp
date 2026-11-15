// 原始稿：03_题目/牛客/weekContest144/小红的好串计数.cpp
// 原文行号：1-41；恢复外层注释 1 层；保留方法内部注释。
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

        ll tot = (1LL * n * (n + 1)) >> 1;

        ll sum = 0;
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && s[i] == s[j])
            {
                j++;
            }

            int len = j - i;
            sum += (1LL * len * (len + 1)) >> 1;
            i = j;
        }

        cout<<tot - sum<<endl;
    }

    return 0;
}
