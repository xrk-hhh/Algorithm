//#include <bits/stdc++.h>
//using namespace std;
//
//#define endl '\n'
//using ll = long long;
//
//struct OP
//{
//	int op, x, y, len;	
//};
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
//        int n, q;
//        cin>>n>>q;
//        
//        vector<OP> ops(q);
//        for (int i = 0; i < q; i++)
//        {
//        	cin>>ops[i].op>>ops[i].x>>ops[i].y>>ops[i].len;
//		}
//		
//		int d;
//		cin>>d;
//		vector<pair<int, int>> qq(d);
//		for (int i = 0; i < d; i++)
//		{
//			cin>>qq[i].first>>qq[i].second;
//		}
//		
//		for (int i = 0; i < d; i++)
//		{
//			int x = qq[i].first, y = qq[i].second;
//			for (int j = q - 1; j >= 0; j--)
//			{
//				int op = ops[j].op, x0 = ops[j].x, y0 = ops[j].y, len = ops[j].len;
//				if (x >= x0 && x <= x0 + len - 1 && y >= y0 && y <= y0 + len - 1)
//				{
//					int r = x - x0, c = y - y0;
//					if (op == 1)
//					{
//						int nx = x0 + (len - 1 - c);
//						int ny = y0 + r;
//						x = nx;
//						y = ny;
//					}
//					else if (op == 2)
//					{
//						int nx = x0 + c;
//						int ny = y0 + (len - 1 - r);
//						x = nx;
//						y = ny;
//					}
//				}
//			}
//			
//			ll ans = 1LL * (x - 1) * n + y;
//			
//			cout<<ans<<endl;
//		}
//    }
//
//    return 0;
//}
