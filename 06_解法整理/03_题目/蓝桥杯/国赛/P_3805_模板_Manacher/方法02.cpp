// 原始稿：03_题目/蓝桥杯/国赛/P_3805_模板_Manacher.cpp
// 原文行号：94-163；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

// 马拉车算法求：最长回文子串长度
int malacher(const string& s)
{
    int n = s.size();
    // 每个字符两边插入 #
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += "#";
    }

    int m = t.size();
    // p[i]：位置 i 的回文半径
    vector<int> p(m, 0);
    // c：当前已知的、右边界最靠右的回文子串的中心位置
    // r：这个回文子串的右边界（即 c + p[c]，p[c] 是以 c 为中心的回文半径）
    int c = 0, r = 0;
    int maxx = 0;
    for (int i = 0; i < m; i++)
    {
        // 位置 i 关于 c 的镜像位置
        int mir = 2 * c - i;
        if (i < r)
        {
            p[i] = min(r - i, p[mir]);
        }

        // 扩展 p[i]
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1])
        {
            p[i]++;
        }

        // 更新 c 和 r
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }

        maxx = max(maxx, p[i]);
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

        cout<<malacher(s)<<endl;
    }

    return 0;
}
