// 原始稿：04_训练与工具/训练赛/laoda1/d.cpp
// 原文行号：1-47；恢复外层注释 1 层；保留方法内部注释。
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
       int n, k;
       cin>>n>>k;
       
       string s;
       cin>>s;
       
       map<string, int> mp;
       for (int i = 0; i < n; i++)
       {
       	string t;
       	for (int j = i; j < i + k; j++)
       	{
       		t += s[j];
			}
			mp[t]++;
		}
		
		int ans = 0;
		for (auto it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second > 1)
			{
				ans++;
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
