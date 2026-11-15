// 原始稿：03_题目/蓝桥杯/BFS/P1141.cpp
// 原文行号：84-185；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

// 并查集板子
struct DSU
{
    vector<int> parent, sz;
    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
        {
            return;
        }

        if (sz[x] < sz[y])
        {
            swap(x, y);
        }

        parent[y] = x;
        sz[x] += sz[y];
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        vector<string> g(n);
        for (int i = 0; i < n; i++)
        {
            cin>>g[i];
        }

        DSU dsu(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n && g[ni][nj] != g[i][j])
                    {
                        // 二维坐标一维映射（行数 * 列宽 + 列数）
                        dsu.unite(i * n + j, ni * n + nj);
                    }
                }
            }
        }

        while (m--)
        {
            int i, j;
            cin>>i>>j;

            i--;
            j--;

            cout<<dsu.size(i * n + j)<<endl;
        }
    }

    return 0;
}
