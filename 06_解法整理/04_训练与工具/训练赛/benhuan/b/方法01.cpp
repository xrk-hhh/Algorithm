// 原始稿：04_训练与工具/训练赛/benhuan/b.cpp
// 原文行号：1-96；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

//ll ans = 0;
//vector<vector<int>> b;
//vector<vector<bool>> vis;
//
//const int a[6][6] =
//{
//	{11, 8, 3, 27, 24, 1},
//	{2, 21, 16, 35, 17, 4},
//	{9, 29, 20, 30, 5, 10},
//	{36, 33, 13, 6, 23, 7},
//	{31, 14, 15, 28, 12, 25},
//	{34, 19, 18, 37, 22, 39}
//};
//
//void dfs(int cnt, int x, int y)
//{
//	if (cnt == 3)
//	{
//		bool ok = true;
//		for (int i = 0; i < 3; i++)
//		{
//			int sum = 0;
//			for (int j = 0; j < 2; j++)
//			{
//				sum += b[i][j];
//			}
//			if (!(sum & 1))
//			{
//				ok = false;
//				break;
//			}
//		}
//		if (ok)
//		{
//			ans++;
//		}
//		return;
//	}
//	
//	for (int i = x; i < 6; i++)
//    {
//    	for (int j = (i == x ? y : 0); j < 6; j++)
//    	{
//    		if (!vis[i][j])
//    		{
//    			if (i + 1 < 6 && !vis[i + 1][j])
//    			{
//    				vis[i][j] = true;
//    				vis[i + 1][j] = true;
//    				b.push_back({a[i][j], a[i + 1][j]});
//    				dfs(cnt + 1, i, j + 1);
//    				vis[i][j] = false;
//    				vis[i + 1][j] = false;
//    				b.pop_back();
//				}
//				if (j + 1 < 6 && !vis[i][j + 1])
//				{
//					vis[i][j] = true;
//					vis[i][j + 1] = true;
//					b.push_back({a[i][j], a[i][j + 1]});
//					dfs(cnt + 1, i, j + 1);
//					vis[i][j] = false;
//					vis[i][j + 1] = false;
//					b.pop_back();
//				}
//			}
//		}
//	}
//}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int T = 1;
   // cin>>T;

   while (T--)
   {
//        vis.assign(6, vector<bool>(6, false));
//        dfs(0, 0, 0);
//        
//        cout<<ans<<endl;
       
       cout<<"7794"<<endl;
   }

   return 0;
}
