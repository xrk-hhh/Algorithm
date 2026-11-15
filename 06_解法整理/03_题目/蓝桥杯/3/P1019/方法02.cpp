// 原始稿：03_题目/蓝桥杯/3/P1019.cpp
// 原文行号：91-161；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
vector<string> word;
vector<int> used;
int maxx = 0;

void dfs(const string& s)
{
    maxx = max(maxx, (int)s.size());
    for (int i = 0; i < n; i++)
    {
        if (used[i] < 2)
        {
            // 保证重叠长度严格小于两个单词的长度
            // 因此不会出现一个单词完全包含另一个的情况。
            for (int j = 1; j < min(s.size(), word[i].size()); j++)
            {
                if (s.substr(s.size() - j) == word[i].substr(0, j))
                {
                    used[i]++;
                    dfs(s + word[i].substr(j));
                    used[i]--;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n;

        word.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin>>word[i];
        }

        char c;
        cin>>c;

        used.assign(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (word[i][0] == c)
            {
                used[i]++;
                dfs(word[i]);
                used[i]--;
            }
        }

        cout<<maxx<<endl;
    }

    return 0;
}
