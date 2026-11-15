// 原始稿：04_训练与工具/训练赛/laoda1/h.cpp
// 原文行号：1-115；恢复外层注释 1 层；保留方法内部注释。
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
       int n, k, m;
       cin>>n>>k>>m;
       
       vector<int> a(n);
       for (int i = 0; i < n; i++)
       {
       	cin>>a[i];
		}
		
		while (m--)
		{
			int op;
			cin>>op;
			
			if (op == 1)
			{
				int p, v;
				cin>>p>>v;
				
				a[p - 1] = v;
			}
			else if (op == 2)
			{
//				int minn = n + 1;
//				for (int i = 0; i < n - k; i++)
//				{
//					vector<bool> vis(k + 1, false);
//					int cnt = 0;
//					int cur = 0;
//					bool ok = false;
//					for (int j = i; j < n; j++)
//					{
//						if (!vis[a[j] - 1])
//						{
//							vis[a[j] - 1] = true;
//							cnt++;
//						}
//						cur++;
//						if (cnt == k)
//						{
//							ok = true;
//							break;
//						}
//					}
//					if (ok)
//					{
//						minn = min(minn, cur);
//					}
//				}
//				if (minn == n + 1)
//				{
//					cout<<-1<<endl;
//				}
//				else
//				{
//					cout<<minn<<endl;
//				}

				int minn = n + 1;
				
				int t = 0;
				vector<int> cnt(k + 1, 0);
				for (int l = 0, r = 0; l < n; l++)
				{
					while (r < n && t < k)
					{
						cnt[a[r]]++;
						if (cnt[a[r]] == 1)
						{
							t++;
						}
						r++;
					}
					if (t == k)
					{
						minn = min(minn, r - 1 - l + 1);
					}
					cnt[a[l]]--;
					if (cnt[a[l]] == 0)
					{
						t--;
					}
				}
				
				if (minn == n + 1)
				{
					cout<<-1<<endl;
				
				}
				else
				{
					cout<<minn<<endl;
				}
			}
		}
   }

   return 0;
}
