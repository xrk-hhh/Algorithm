// 原始稿：03_题目/牛客/weekContest143/小红的冷门副本.cpp
// 原文行号：1-43；恢复外层注释 1 层；保留方法内部注释。
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
        int n, m, x;
        cin>>n>>m>>x;

        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;

            cnt[a]++;
        }

        int ans = 0;
        for (auto& binding_value_01 : cnt)
        {
            auto& a = binding_value_01.first;
            auto& t = binding_value_01.second;
            if (t <= x)
            {
                ans++;
            }
        }
        ans += m - cnt.size();

        cout<<ans<<endl;
    }

    return 0;
}
