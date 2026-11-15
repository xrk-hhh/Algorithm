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
//    	int n, m, k;
//        cin>>n>>m>>k;
//        vector<int> c(n - 1), a(n);
//        for (int i = 0; i < n - 1; i++)
//        {
//        	cin>>c[i];
//		}
//		for (int i = 0; i < n; i++)
//		{
//			cin>>a[i];
//		}
//		
//		vector<ll> pre(n + 1, 0);
//		for (int i = 1; i < n; i++)
//		{
//			pre[i + 1] = pre[i] + c[i - 1];
//		}
//		
//		priority_queue<int, vector<int>, greater<int>> pq;
//		ll sum = 0, ans = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			pq.push(a[i - 1]);
//			sum += a[i - 1];
//			
//			if (pq.size() > k)
//			{
//				sum -= pq.top();
//				pq.pop();
//			}
//			
//			ll cost = pre[i];
//			if (cost > m)
//			{
//				break;
//			}
//			
//			ll rem = m - cost;
//			
//			ll t = min(rem, sum);
//			
//			ans = max(ans, t);
//		}
//		
//		cout<<ans<<endl;
//    }
//
//    return 0;
//}
