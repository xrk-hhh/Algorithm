// 原始稿：04_训练与工具/训练赛/laoda1/c.cpp
// 原文行号：1-87；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int MAXA = 1e5;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   // cin>>T;

   while (T--)
   {
       int n;
       cin>>n;
       
       vector<int> a(n);
       for (int i = 0; i < n; i++)
       {
       	cin>>a[i];
		}
		
		vector<int> cnt(MAXA + 10, 0);
		vector<int> vis(MAXA + 10, -1);
		
       bool ok = true;
       int ans = 0;
       int pre = 1;
       
       cnt[a[0]]++;
       vis[a[0]] = 0;
       
       if (pre == a[0])
       {
           ans++;
       }
       else
       {
           ok = false;
       }
       int maxx = 1;
       int cur = a[0];
       int idx = 0;
		for (int i = 1; i < n; i++)
		{
           if (!ok)
           {
               pre = cur;
           }
           
           if (pre == a[i])
           {
               ans++;
               ok = true;
           }
           else
           {
               ok = false;
           }
			cnt[a[i]]++;
			if (vis[a[i]] == -1)
			{
				vis[a[i]] = i;
			}
			if (cnt[a[i]] > maxx)
			{
				maxx = cnt[a[i]];
               cur = a[i];
               idx = vis[a[i]];
			}
			else if (cnt[a[i]] == maxx && vis[a[i]] > idx)
			{
				cur = a[i];
               idx = vis[a[i]];
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
