// 原始稿：04_训练与工具/训练赛/benhuan/g.cpp
// 原文行号：1-148；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXN = 2e5 + 10;
const int LOG = 20;

vector<int> g[MAXN];
int depth[MAXN], up[MAXN][LOG];

void dfs(int u, int p)
{
	depth[u] = depth[p] + 1;
	up[u][0] = p;
	
	for (int i = 1; i < LOG; i++)
	{
		up[u][i] = up[up[u][i - 1]][i - 1];
	
	}
	
	for (int v : g[u])
	{
		if (v != p)
		{
			dfs(v, u);
		}
	}
}

int lca(int u, int v)
{
	if (depth[u] < depth[v])
	{
		swap(u, v);
	}
	
	int dif = depth[u] - depth[v];
	
	for (int i = 0; i < LOG; i++)
	{
		if (dif & (1 << i))
		{
			u = up[u][i];
		}
	}
	
	if (u == v)
	{
		return u;
	}
	
	for (int i = LOG - 1; i >= 0; i--)
	{
		if (up[u][i] != up[v][i])
		{
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
}

int dist(int u, int v)
{
	int l = lca(u, v);
	
	return depth[u] + depth[v] - 2 * depth[l];
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   cin>>T;

   while (T--)
   {
       int n;
       cin>>n;
       
       for (int i = 1; i <= n; i++)
       {
       	g[i].clear();
		}
       
       for (int i = 0; i < n - 1; i++)
       {
       	int u, v;
       	cin>>u>>v;
       	
       	g[u].push_back(v);
       	g[v].push_back(u);
		}
		
		depth[0] = -1;
		dfs(1, 0);
		
		vector<int> p(n);
		for (int i = 0; i < n; i++)
		{
			cin>>p[i];
		}
		
		if (n == 1)
		{
			cout<<"1"<<endl;
			continue;
		}
		
		int a = p[0], b = p[0];
		int ans = n;
		for (int i = 1; i < n; i++)
		{
			int x = p[i];
			
			if (dist(a, x) + dist(x, b) == dist(a, b))
			{
				continue;
			}
			else
			{
				if (dist(a, b) + dist(b, x) == dist(a, x))
				{
					b = x;
				}
				else if (dist(a, b) + dist(a, x) == dist(b, x))
				{
					a = x;
				}
				else
				{
					ans = i;
					break;
				}
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
