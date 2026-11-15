// 原始稿：03_题目/蓝桥杯/国赛/P_12213_蓝桥杯_2023_国_Python_B_最长回文前后缀.cpp
// 原文行号：302-396；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 经典马拉车：求以某位置开头的最长回文前缀长度
vector<int> malacher(const string& s)
{
    int n = s.size();
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }

    int m = t.size();
    vector<int> p(m, 0);
    vector<int> maxx(n, 0);
    int c = 0, r = 0;
    for (int i = 0; i < m; i++)
    {
        int mir = 2 * c - i;
        if (i < r)
        {
            p[i] = min(r - i, p[mir]);
        }

        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1])
        {
            p[i]++;
        }

        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }

        // i 对应在原字符串 s 中的位置
        int l = (i - p[i]) >> 1;
        int len = p[i];
        if (l >= 0 && l < n)
        {
            maxx[l] = max(maxx[l], len);
        }
    }

    return maxx;
}

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
        string t = s;
        reverse(t.begin(), t.end());

        // s 和 t的最长公共前缀长度
        int L = 0;
        // 暴力匹配
        while (L < n && s[L] == t[L])
        {
            L++;
        }

        if (L == n)
        {
            cout<<2 * n<<endl;
            return 0;
        }

        vector<int> preS = malacher(s);
        vector<int> preT = malacher(t);

        // 以 L 位置为起点的最长回文前缀长度
        int add = max(preS[L], preT[L]);
        int ans = 2 * L + add;

        cout<<ans<<endl;
    }

    return 0;
}
