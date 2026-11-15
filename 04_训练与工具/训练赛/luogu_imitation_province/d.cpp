//#include <bits/stdc++.h>
//using namespace std;
//
//#define endl '\n'
//using ll = long long;
//
//const int MOD = 998244353;
//
//ll ksm(ll a, ll b)
//{
//	ll res = 1;
//	a = a % MOD;
//	while (b)
//	{
//		if (b & 1)
//		{
//			res = res * a % MOD;
//		}
//		a = a * a % MOD;
//		b >>= 1;
//	}
//	return res % MOD;
//} 
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int T = 1;
//    cin>>T;
//
//    while (T--)
//    {
//        int x, y;
//        cin>>x>>y;
//        
//        if (x <= y)
//		{
//			cout<<1<<endl;
//		}
//		else if (x == y + 1)
//		{
//			cout<<y + 1<<endl;
//		}
//		else
//		{
//			ll ans = (y + 1) * ksm(2, (x - y - 1)) % MOD;
//			cout<<ans % MOD<<endl;
//		}
//    }
//
//    return 0;
//}
