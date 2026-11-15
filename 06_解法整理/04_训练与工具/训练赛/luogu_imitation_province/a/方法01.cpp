// 原始稿：04_训练与工具/训练赛/luogu_imitation_province/a.cpp
// 原文行号：1-174；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   // cin>>T;

   while (T--)
   {
   	ll ans = 0;
   	
   	for (int d = 9; d <= 30; d++)
   	{
   		vector<int> cnt0(10, 0);
	    	cnt0[2] += 2;
	    	cnt0[3]++;
	    	cnt0[9] += 2;
   		int td = d;
   		while (td)
   		{
   			cnt0[td % 10]++;
   			td /= 10;
			}
			bool ok0 = true;
			int cur = -1;
			for (int i = 0; i < 10; i++)
			{
				// 注意是比较出现次数不为 0 的
				if (cnt0[i] > 0)
				{
					// 第一次出现不为 0 的 
					if (cur == -1)
					{
						cur = cnt0[i];
					}
					else if (cur != cnt0[i])
					{
						ok0 = false;
						break;
					}
				}
			}
			if (ok0)
			{
				ans++;
			}
		}
		
		
		
   	for (int m = 10; m <= 12; m++)
   	{
   		int dd = days[m - 1];
   		for (int d = 1; d <= dd; d++)
   		{
   			vector<int> cnt1(10, 0);
		    	cnt1[2] += 2;
		    	cnt1[3]++;
		    	cnt1[9]++;
	    		int tm = m;
	    		while (tm)
	    		{
	    			cnt1[tm % 10]++;
	    			tm /= 10;
				}
   			int td = d;
   			while (td)
   			{
   				cnt1[td % 10]++;
   				td /= 10;
				}
				bool ok1 = true;
				int cur = -1;
				for (int i = 0; i < 10; i++)
				{
					if (cnt1[i] > 0)
					{
						if (cur == -1)
						{
							cur = cnt1[i];
						}
						else if (cur != cnt1[i])
						{
							ok1 = false;
							break;
						}
					}
				}
				if (ok1)
				{
					ans++;
				}
			}
		}
		    	
		    	
       for (int y = 2240; y <= 9875; y++)
       {
       	for (int m = 1; m <= 12; m++)
       	{
       		int dd = days[m - 1];
       		if (is_leap(y) && m == 2)
       		{
       			dd++;
				}
				for (int d = 1; d <= dd; d++)
				{
					vector<int> cnt(10, 0);
		        	int ty = y;
		        	while (ty)
		        	{
		        		cnt[ty % 10]++;
		        		ty /= 10;
					}
					int tm = m;
	        		while (tm)
	        		{
	        			cnt[tm % 10]++;
	        			tm /= 10;
					}
					int td = d;
					while (td)
					{
						cnt[td % 10]++;
						td /= 10;
					}
					bool ok = true;
					int cur = -1;
					for (int i = 0; i < 10; i++)
					{
						if (cnt[i] > 0)
						{
							if (cur == -1)
						{
							cur = cnt[i];
						}
						else if (cur != cnt[i])
						{
							ok = false;
							break;
						}
						}
					}
					if (ok)
					{
						ans++;
					}
				}
			}
		}
		
		cout<<ans<<endl;

//		cout<<"210778"<<endl;
   }

   return 0;
}
