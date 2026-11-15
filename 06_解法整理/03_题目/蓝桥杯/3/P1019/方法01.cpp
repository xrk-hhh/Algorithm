// 原始稿：03_题目/蓝桥杯/3/P1019.cpp
// 原文行号：1-90；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n;
vector<string> word;
vector<int> used;
// overlaps[i][j] 存储所有可行重叠长度
vector<vector<vector<int>>> overlaps;
int maxx = 0;

// 记录 最后一个单词索引 和 当前字符串长度
// 避免字符串复制，能减少性能开销，提高性能
void dfs(int last, int cur)
{
    maxx = max(maxx, cur);
    for (int i = 0; i < n; i++)
    {
        if (used[i] < 2)
        {
            const auto& ov = overlaps[last][i];
            for (int len : ov)
            {
                used[i]++;
                dfs(i, cur + (int)word[i].size() - len);
                used[i]--;
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

        char start;
        cin>>start;

        // 预处理所有重叠长度
        overlaps.resize(n, vector<vector<int>>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                const string& a = word[i], b = word[j];
                int la = a.size(), lb = b.size();
                for (int len = 1; len < min(la, lb); len++)
                {
                    if (a.substr(la - len) == b.substr(0, len))
                    {
                        overlaps[i][j].push_back(len);
                    }
                }
            }
        }

        used.assign(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (word[i][0] == start)
            {
                used[i] = 1;
                dfs(i, word[i].size());
                used[i] = 0;
            }
        }

        cout<<maxx<<endl;
    }

    return 0;
}
