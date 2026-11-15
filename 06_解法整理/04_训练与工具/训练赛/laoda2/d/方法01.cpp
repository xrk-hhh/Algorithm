// 原始稿：04_训练与工具/训练赛/laoda2/d.cpp
// 原文行号：1-73；恢复外层注释 1 层；保留方法内部注释。
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
       string s;
       cin>>s;
       
       int n = s.size();
       int ans = 0;
       for (int i = 0; i < n; i++)
       {
       	int t = i;
       	if (s[t] == '(')
       	{
   			t++;
   			int sum = 0;
       		int num = 0;
       		bool ok = true;
       		while (s[t] != ')' && t < n)
       		{
       			if (s[t] == '(')
       			{
       				ok = false;
       				break;
					}
       			if (s[t] >= '0' && s[t] <= '9')
       			{
       				num = num * 10 + s[t] - '0';
					}
					else if (s[t] == '.')
					{
						sum += num;
						num = 0;
					}
					t++;
				}

				sum += num;
				if (!ok)
				{
					i = t - 1;
					continue;
				}
				else if (s[t] == ')')
				{
					ans = max(ans, sum);
				}
				
				if (t == n)
				{
					break;
				}
				i = t;
			}
		}
		
		cout<<ans<<endl;
   }

   return 0;
}
