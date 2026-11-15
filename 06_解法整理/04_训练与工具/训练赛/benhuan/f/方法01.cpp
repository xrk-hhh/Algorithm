// 原始稿：04_训练与工具/训练赛/benhuan/f.cpp
// 原文行号：1-77；恢复外层注释 1 层；保留方法内部注释。
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
       
       vector<int> a(n);
       for (int i = 0; i < n; i++)
       {
       	cin>>a[i];
		}
		
		vector<int> l(n, -1), r(n, n);
		stack<int> st;
		for (int i = 0; i < n; i++)
		{
			while (!st.empty() && a[st.top()] < a[i])
			{
				st.pop();
			}
			
			if (!st.empty())
			{
				l[i] = st.top();
			}
			st.push(i);
		}
		
		while (!st.empty())
		{
			st.pop();
		}
		
		for (int i = n - 1; i >= 0; i--)
		{
			while (!st.empty() && a[st.top()] < a[i])
			{
				st.pop();
			}
			
			if (!st.empty())
			{
				r[i] = st.top();
			}
			st.push(i);
		}
		
		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			int al = max(l[i] + 1, i - a[i] + 1);
			int ar = min(i, r[i] - a[i]);
			
			if (al <= ar)
			{
				ans += ar - al + 1;
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
