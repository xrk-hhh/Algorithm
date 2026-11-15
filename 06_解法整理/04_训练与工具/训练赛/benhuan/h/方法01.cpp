// 原始稿：04_训练与工具/训练赛/benhuan/h.cpp
// 原文行号：1-56；恢复外层注释 1 层；保留方法内部注释。
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
       int n;
       cin>>n;
       
       vector<int> p(n + 1);
       for (int i = 1; i <= n; i++)
       {
       	cin>>p[i];
		}
		
		vector<ll> cur(n + 1, 1e18);
		cur[0] = p[1];
		
		for (int i = 1; i < n; i++)
		{
			vector<ll> nxt(n + 1, 1e18);
			for (int j = 0; j < i; j++)
			{
				if (cur[j] == 1e18)
				{
					continue;
				}
				
				nxt[j] = min(nxt[j], cur[j] + abs(p[i + 1] - p[i]));
				
				nxt[i] = min(nxt[i], cur[j] + abs(p[i + 1] - p[j]));
			}
			cur.swap(nxt);
		}
		
		ll ans = 1e18;
		for (int j = 0; j < n; j++)
		{
			ans = min(ans, cur[j]);
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
