#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	
	vector<ll> pre(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	
	ll ans = 4e18;
	set<ll> st;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int sum = pre[j] - pre[i - 1];
			if (!st.empty())
			{
				auto it = st.lower_bound(sum);
				ans = min(ans, abs(*it - sum));
				if (it != st.begin())
				{
					ans = min(ans, abs(*(--it) - sum));
				}
			}
		}
		
		for (int j = 1; j <= i; j++)
		{
			st.insert(pre[i] - pre[j - 1]);
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
 } 
