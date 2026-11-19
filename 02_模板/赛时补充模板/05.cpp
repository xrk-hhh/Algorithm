#include <bits/stdc++.h>
using namespace std;

// 无向图每条边两次入邻接表，使用同一编号；有向图只入一次。
vector<int> euler(vector<vector<pair<int, int>>> g, int s, int m)
{
    vector<int> used(m), st(1, s), ans;
    while (!st.empty())
    {
        int u = st.back();
        while (!g[u].empty() && used[g[u].back().second])
            g[u].pop_back();
        if (g[u].empty())
        {
            ans.push_back(u);
            st.pop_back();
        }
        else
        {
            auto e = g[u].back();
            g[u].pop_back();
            used[e.second] = 1;
            st.push_back(e.first);
        }
    }
    if ((int)ans.size() != m + 1)
        return {}; // 尚须先满足度数条件
    reverse(ans.begin(), ans.end());
    return ans;
}
