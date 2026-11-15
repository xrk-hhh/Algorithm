// 原始稿：03_题目/蓝桥杯/DFS/P12266.cpp
// 原文行号：1-48；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define endl '\n'
using ll = long long;

vector<int> a = {5, 5, 10, 10, 15, 15, 20, 20, 25, 25};
set<int> score;
int ans = 0;

void dfs(int pos, int cur)
{
    if (pos == 10)
    {
        // 该分数之前没有出现过
        if (!score.count(cur))
        {
            score.insert(cur);
            ans++;
        }
        return;
    }

    // 得 0 分
    dfs(pos + 1, cur);

    // 得 a[pos] 分
    dfs(pos + 1, cur + a[pos]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        dfs(0, 0);

        cout<<ans<<endl;
    }

    return 0;
}
