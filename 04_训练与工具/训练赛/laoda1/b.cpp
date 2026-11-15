////#include <bits/stdc++.h>
////using namespace std;
////
////#define endl '\n'
////using ll = long long;
////
////const int MOD = 1e9 + 7;
////
////int main()
////{
////    ios::sync_with_stdio(false);
////    cin.tie(nullptr);
////
////    int T = 1;
////    // cin>>T;
////
////    while (T--)
////    {
//////    	string ss = "2026";
//////        string s;
//////        int n = 4 * 2026;
//////        for (int i = 0; i < 2026; i++)
//////        {
//////        	s += ss;
//////		}
//////		
//////		int cnt06 = 0, cnt2 = 0;
//////		for (int i = 0; i < n; i++)
//////		{
//////			int x = s[i] - '0';
//////			if (x == 0 || x == 6)
//////			{
//////				cnt06++;
//////			}
//////			else if (x == 2)
//////			{
//////				cnt2++;
//////			}
//////		}
//////		
//////		ll ans = (cnt2 / 3 + cnt06 * (cnt06 - 1) * (cnt06 - 2) / 6);
//////		
////////		ll ans = (cnt2 / 3 + cnt06 * (cnt06 - 1) % MOD * (cnt06 - 2) % MOD / 6) % MOD;
//////		
//////		cout<<ans % MOD<<endl;
//////
////////		cout<<"9139874"<<endl;
////		cout<<"342473210"<<endl;
////    }
////
////    return 0;
////}
//
//#include <iostream>
//using namespace std;
//const int MOD = 1e9 + 7;
//
//int main() {
//    long long cnt = 2 * 2026; // 4052
//    // 计算 C(cnt, 3) = cnt*(cnt-1)*(cnt-2)/6
//    long long c3 = cnt % MOD * ((cnt - 1) % MOD) % MOD * ((cnt - 2) % MOD) % MOD;
//    c3 = c3 * 166666668 % MOD; // 6 的逆元
//    long long ans = c3 * 2 % MOD;
//    cout << ans << endl;
//    return 0;
//}
