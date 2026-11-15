// 原始稿：04_训练与工具/训练赛/laoda1/f.cpp
// 原文行号：1-75；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

bool check(int d, const vector<int>& l, const vector<int>& r)
{
	int i = 0, j = 0, cnt = 0;
	while (i < l.size() && j < r.size())
	{
		if (abs(l[i] - r[j]) <= d)
		{
			cnt++;
			i++;
			j++;
		}
		else if (l[i] < r[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	
	return cnt == min(l.size(), r.size());
}

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
       
       vector<int> l(n), r(m);
       for (int i = 0; i < n; i++)
       {
       	cin>>l[i];
		}
		for (int j = 0; j < m; j++)
		{
			cin>>r[j];
		}
		
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		
		int low = 0, high = 1e9;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (check(mid, l, r))
			{
				high = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		
		cout<<low<<endl;
   }

   return 0;
}
