#include <bits/stdc++.h>
using namespace std;

struct AC
{
    struct N
    {
        array<int, 26> ch{};
        int fail = 0;
    };
    vector<N> t;
    vector<int> ord, end;
    AC() : t(1) {}
    void insert(string s)
    {
        int u = 0;
        for (char c : s)
        {
            int x = c - 'a';
            if (!t[u].ch[x])
            {
                t[u].ch[x] = t.size();
                t.emplace_back();
            }
            u = t[u].ch[x];
        }
        end.push_back(u);
    }
    void build()
    {
        queue<int> q;
        for (int x : t[0].ch)
            if (x)
                q.push(x);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ord.push_back(u);
            for (int i = 0; i < 26; i++)
            {
                int v = t[u].ch[i];
                if (v)
                    t[v].fail = t[t[u].fail].ch[i], q.push(v);
                else
                    t[u].ch[i] = t[t[u].fail].ch[i];
            }
        }
    }
    vector<long long> count(string s)
    {
        vector<long long> cnt(t.size()), ans;
        int u = 0;
        for (char c : s)
        {
            u = t[u].ch[c - 'a'];
            cnt[u]++;
        }
        for (int i = (int)ord.size() - 1; i >= 0; i--)
        {
            int v = ord[i];
            cnt[t[v].fail] += cnt[v];
        }
        for (int v : end)
            ans.push_back(cnt[v]);
        return ans;
    }
}; // 小写字母、非空模式串；重复模式按编号分别返回次数
