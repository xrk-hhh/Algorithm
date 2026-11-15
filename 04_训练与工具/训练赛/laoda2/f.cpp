//#include <bits/stdc++.h>
//using namespace std;
//
//#define endl '\n'
//using ll = long long;
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T = 1;
//    // cin>>T;
//
//    while (T--)
//    {
//    	int n, m;
//        cin>>n>>m;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++)
//        {
//        	cin>>a[i];
//		}
//		
//		// 前缀异或和 
//		vector<int> pre(n + 1, 0);
//		for (int i = 1; i <= n; i++)
//		{
//			pre[i] = pre[i - 1] ^ a[i - 1];
//		}
//		
//		int ans = 0;
//		// 从高位到低位贪心 
//		for (int mask = 30; mask >= 0; mask--)
//		{
//			int cand = ans | (1 << mask);
//			
//			int cnt = 0;
//			 // 当前需要的值（交替为 cand 或 0）
//			int cur = cand;
//			for (int i = 1; i <= n && cnt < m - 1; i++)
//			{
//				if ((pre[i] & cand) == cur)
//				{
//					cnt++;
//					// 翻转需要的值
//					cur ^= cand;
//				}
//			}
//			
//			// 最后一段必须满足 (pre[n] & cand) == cur
//			if (cnt == m - 1 && (pre[n] & cand) == cur)
//			{
//				ans = cand;
//			}
//		}
//		
//		cout<<ans<<endl;
//    }
//
//    return 0;
//}
