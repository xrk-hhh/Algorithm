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
//    cin>>T;
//
//    while (T--)
//    {
//    	int n, x;
//        cin>>n>>x;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++)
//        {
//        	cin>>a[i];
//		}
//		
//		bool ok = true;
//		for (int i = 0; i < n - 1; i++)
//		{
//			if ((a[i + 1] - a[i] > 1) || (a[i] - a[i + 1] > x))
//			{
//				ok = false;
//				break;
//			}
//		}
//		
//		if (ok)
//		{
//			cout<<"Win"<<endl;
//		}
//		else
//		{
//			cout<<"Lose"<<endl;
//		}
//    }
//
//    return 0;
//}
