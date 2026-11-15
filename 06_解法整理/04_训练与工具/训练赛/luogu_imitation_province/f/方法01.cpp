// 原始稿：04_训练与工具/训练赛/luogu_imitation_province/f.cpp
// 原文行号：1-59；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   // cin>>T;

   while (T--)
   {
       int n, x, y;
       ll w;
       cin>>n>>x>>y>>w;
       
       vector<pair<int, ll>> fa(n);
       for (int i = 0; i < n; i++)
       {
       	cin>>fa[i].first>>fa[i].second;
		}
		
		sort(fa.begin(), fa.end());
		
		ll ans = abs(x - fa[0].first);
		for (int i = 0; i < n; i++)
		{
			ans += (fa[i].second / w) * (y - fa[i].first) * 2;
			if (fa[i].second % w > 0)
			{
				if (i + 1 < n)
				{
					fa[i + 1].second += (fa[i].second % w);
					ans += (fa[i + 1].first - fa[i].first);
				}
				else
				{
					ans += (y - fa[i].first);
				}
			}
			else
			{
				ans -= (y - fa[i].first);
				if (i + 1 < n)
				{
					ans += (y - fa[i + 1].first);
				}
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
