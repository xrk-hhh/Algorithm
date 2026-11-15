// 原始稿：04_训练与工具/训练赛/laoda2/h.cpp
// 原文行号：1-84；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   cin>>T;

   while (T--)
   {
       int n, m;
       cin>>n>>m;
       
       vector<vector<pair<int, int>>> g(n + 1);
       for (int i = 0; i < m; i++)
       {
       	int x, y ,c;
       	cin>>x>>y>>c;
       	
       	g[x].push_back({y, c});
       	g[y].push_back({x, c});
		}
		
		int k;
		cin>>k;
		
		vector<int> a(k);
		for (int i = 0; i < k; i++)
		{
			cin>>a[i];
		}
		
		vector<ll> dist(n + 1, 1e18);
		vector<int> src(n + 1, -1);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		for (int i = 0; i < k; i++)
		{
			dist[a[i]] = 0;
			src[a[i]] = a[i];
			pq.push({0, a[i]});
		}
		
		
		ll ans = 1e18;
		while (!pq.empty())
		{
			ll d = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			
			if (d != dist[u])
			{
				continue;
			}
			
			for (auto dd : g[u])
			{
				int v = dd.first;
				int w = dd.second;
				
				if (dist[v] > d + w)
				{
					dist[v] = d + w;
					src[v] = src[u];
					pq.push({dist[v], v});
				}
				else if (src[v] != -1 && src[v] != src[u])
				{
					ans = min(ans, d + w + dist[v]);
				}
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
