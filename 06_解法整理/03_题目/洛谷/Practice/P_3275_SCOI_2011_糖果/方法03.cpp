// 原始稿：03_题目/洛谷/Practice/P_3275_SCOI_2011_糖果.cpp
// 原文行号：291-486；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1e5 + 10;
const ll INF = 1e18;

// 原图 (u -> (v, w))
vector<pair<int, int>> g[N];
// dfn[u]：点 u 在 DFS 中的访问序号（时间戳），从 1 开始递增
// low[u]：顶点 u 能回溯到的最早访问的祖先的 dfn 值（即通过子树内的边或一条回边能到达的 dfn 最小的节点）
int dfn[N], low[N], stk[N], top, scc_id[N], scc_cnt, idx;
// ins[u]：标记节点 u 是否在栈中，用于判断回边是否指向当前 DFS 路径上的祖先
bool ins[N];
int n, k;
// 入度
int deg[N];
// 缩点后的 DAG
vector<pair<int, int>> dag[N];
// 最长路距离
ll dist[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++idx;
    stk[++top] = u;
    ins[u] = true;
    for (auto binding_value_01 : g[u])
    {
        auto v = binding_value_01.first;
        auto w = binding_value_01.second;
        // v 未访问
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        // v 已访问且在栈中（说明是回边）
        else if (ins[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
     
    // u 是其所在强连通分量的“根”，此时栈中 u 之上的所有节点构成一个 SCC
    if (dfn[u] == low[u])
    {
        ++scc_cnt;
        int v;
        // 不断弹出栈顶元素直到弹出 u，这些元素构成一个强连通分量
        do
        {
            v = stk[top--];
            ins[v] = false;
            scc_id[v] = scc_cnt;
        } while (v != u);
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
        cin>>n>>k;
        bool bad = false;
        for (int i = 0; i < k; i++)
        {
            int x, a, b;
            cin>>x>>a>>b;

            if (x == 1)
            {
                g[a].push_back({b, 0});
                g[b].push_back({a, 0});
            }
            else if (x == 2)
            {
                if (a == b)
                {
                    bad = true;
                }
                g[a].push_back({b, 1});
            }
            else if (x == 3)
            {
                g[b].push_back({a, 0});
            }
            else if (x == 4)
            {
                if (a == b)
                {
                    bad = true;
                }
                g[b].push_back({a, 1});
            }
            else if (x == 5)
            {
                g[a].push_back({b, 0});
            }
        }

        if (bad)
        {
            cout<<-1<<endl;
            return 0;
        }

        // 添加超级源点 0
        for (int i = 1; i <= n; i++)
        {
            g[0].push_back({i, 1});
        }

        // Tarjan 求强连通分量
        // 强连通：在有向图中，如果两个顶点 u 和 v 互相可达（即存在 u→v 和 v→u 的路径），则称它们强连通
        // 强连通分量：极大的强连通子图，即子图内任意两点强连通，且无法再加入其他顶点保持该性质
        for (int i = 0; i <= n; i++)
        {
            if (!dfn[i])
            {
                tarjan(i);
            }
        }

        // 检查每个 SCC 内部是否有正权边，同时建 DAG
        for (int u = 0; u <= n; u++)
        {
            for (auto binding_value_02 : g[u])
            {
                auto v = binding_value_02.first;
                auto w = binding_value_02.second;
                if (scc_id[u] == scc_id[v])
                {
                    if (w > 0)
                    {
                        cout<<-1<<endl;
                        return 0;
                    }
                }
                else
                {
                    dag[scc_id[u]].push_back({scc_id[v], w});
                    deg[scc_id[v]]++;
                }
            }
        }

        // 拓扑排序求最长路
        queue<int> q;
        for (int i = 1; i <= scc_cnt; i++)
        {
            if (deg[i] == 0)
            {
                q.push(i);
            }
        }

        // 超级源点所在的分量
        int src = scc_id[0];
        for (int i = 1; i <= scc_cnt; i++)
        {
            dist[i] = -INF;
        }
        dist[src] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto binding_value_03 : dag[u])
            {
                auto v = binding_value_03.first;
                auto w = binding_value_03.second;
                if (dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
                if (--deg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += dist[scc_id[i]];
        }
        cout<<ans<<endl;
    }

    return 0;
}
