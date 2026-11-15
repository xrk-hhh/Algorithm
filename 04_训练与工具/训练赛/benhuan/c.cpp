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
//     cin>>T;
//
//    while (T--)
//    {
//        int n, m;
//        cin>>n>>m;
//        
//        string a, s;
//        cin>>a>>s;
//        
//        vector<int> num(n);
//        for (int i = 0; i < n; i++)
//        {
//        	num[i] = a[i] - '0';
//		}
//		
//		int pos = 0;
//		for (int i = 0; i < m; i++)
//		{
//			char c = s[i];
//			if (c == 'L')
//			{
//				if (pos != 0)
//				{
//					pos--;
//				}
//			}
//			else if (c == 'R')
//			{
//				if (pos != n - 1)
//				{
//					pos++;
//				}
//			}
//			else if (c == 'U')
//			{
//				if (num[pos] == 9)
//				{
//					num[pos] = 0;
//				}
//				else
//				{
//					num[pos]++;
//				}
//			}
//			else if (c == 'D')
//			{
//				if (num[pos] == 0)
//				{
//					num[pos] = 9;
//				}
//				else
//				{
//					num[pos]--;
//				}
//			}
//		}
//		
//		for (int i = 0; i < n; i++)
//		{
//			cout<<num[i];
//		}
//		cout<<endl;
//    }
//
//    return 0;
//}
