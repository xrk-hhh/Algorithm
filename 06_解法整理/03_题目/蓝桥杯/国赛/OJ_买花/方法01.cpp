// 原始稿：03_题目/蓝桥杯/国赛/OJ_买花.cpp
// 原文行号：1-107；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 26;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        ll ans = 0;
        // 枚举区间内不同字母的数量 t
        for (int t = 1; t <= N && t * k <= n; t++)
        {
            // 窗口长度
            int len = t * k;
            // 当前窗口内各字母的频数
            vector<int> cnt(N, 0);
            // cntk：出现次数恰好 k 的字母种数, cnt0：出现次数大于 0 的字母种数
            int cntk = 0, cnt0 = 0;

            // 初始化第一个窗口
            for (int i = 0; i < len; i++)
            {
                int idx = s[i] - 'a';
                if (cnt[idx] == 0)
                {
                    cnt0++;
                }

                cnt[idx]++;
                if (cnt[idx] == k)
                {
                    cntk++;
                }
                else if (cnt[idx] == k + 1)
                {
                    cntk--;
                }
            }

            if (cntk == cnt0 && cnt0 > 0)
            {
                ans++;
            }

            // 滑动窗口
            for (int i = len; i < n; i++)
            {
                int idx1 = s[i] - 'a';
                if (cnt[idx1] == 0)
                {
                    cnt0++;
                }

                cnt[idx1]++;
                if (cnt[idx1] == k)
                {
                    cntk++;
                }
                else if (cnt[idx1] == k + 1)
                {
                    cntk--;
                }

                int idx2 = s[i - len] - 'a';
                if (cnt[idx2] == k)
                {
                    cntk--;
                }

                cnt[idx2]--;
                if (cnt[idx2] == 0)
                {
                    cnt0--;
                }
                else if (cnt[idx2] == k)
                {
                    cntk++;
                }

                if (cntk == cnt0 && cnt0 > 0)
                {
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
