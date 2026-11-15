// 原始稿：04_训练与工具/训练赛/benhuan/d.cpp
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
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
       
       if (!(n & (n - 1)))
       {
       	cout<<"Fang"<<endl;
		}
		else
		{
			cout<<"Ben"<<endl;
		}
   }

   return 0;
}
