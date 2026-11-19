#include <bits/stdc++.h>
using namespace std;

// child为有向孩子表；虚根0，w[0]=0，目标M门时查询f[0][M+1]
vector<vector<long long>>
dependency_pack(const vector<vector<int>> &child,
                const vector<int> &w, int K)
{
    const long long NEG = LLONG_MIN / 4;
    int n = child.size();
    vector<vector<long long>> f(n,
                                vector<long long>(K + 1, NEG));
    function<int(int)> dfs = [&](int u)
    {
        f[u][0] = 0;
        f[u][1] = w[u];
        int sz = 1;
        for (int v : child[u])
        {
            int z = dfs(v);
            vector<long long> nf = f[u];
            for (int a = 1; a <= min(sz, K); a++)
                if (f[u][a] != NEG)
                    for (int b = 1; b <= min(z, K - a); b++)
                        if (f[v][b] != NEG)
                            nf[a + b] = max(nf[a + b],
                                            f[u][a] + f[v][b]);
            f[u].swap(nf);
            sz += z;
        }
        return sz;
    };
    dfs(0);
    return f;
} // K>=1；a从1开始保证选子先选父
