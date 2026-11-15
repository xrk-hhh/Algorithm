// 原始稿：04_训练与工具/训练赛/benhuan/e.cpp
// 原文行号：1-91；恢复外层注释 1 层；保留方法内部注释。
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
       int n, k;
       cin>>n>>k;
       
       deque<int> dq;
       int maxx = 0;
       for (int i = 0; i < n; i++)
       {
       	int a;
       	cin>>a;
       	
       	dq.push_back(a);
       	maxx = max(maxx, a);
		}
		
		int cnt = 0;
		while (dq.front() != maxx && cnt < k)
		{
			int a1 = dq.front();
			dq.pop_front();
			int a2 = dq.front();
			dq.pop_front();
			
			if (a1 > a2)
			{
				dq.push_front(a1);
				dq.push_back(a2);
			}
			else
			{
				dq.push_front(a2);
				dq.push_back(a1);
			}
			cnt++;
		}
		
		if (cnt == k)
		{
			for (int i = 0; i < dq.size(); i++)
			{
				cout<<dq[i]<<' ';
			}
			cout<<endl;
			
			continue;
		}
		
		int rem = k - cnt;
		vector<int> a;
		for (int i = 1; i < n; i++)
		{
			a.push_back(dq[i]);
		}
		
		int t = rem % (n - 1);
		
		vector<int> ans;
		for (int i = t; i < n - 1; i++)
		{
			ans.push_back(a[i]);
		}
		for (int i = 0; i < t; i++)
		{
			ans.push_back(a[i]);
		}
		
		cout<<dq[0]<<' ';
		for (int i = 0; i < n - 1; i++)
		{
			cout<<ans[i]<<' ';
		}
		cout<<endl;
   }

   return 0;
}
