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
	for (int l1 = 1; l1 < n; l1++)
	{
		for (int r1 = l1; r1 < n; r1++)
		{
			for (int l2 = r1 + 1; l2 <= n; l2++)
			{
				for (int r2 = l2; r2 <= n; r2++)
				{
					ans = min(ans, abs(pre[r1] - pre[l1 - 1] - (pre[r2] - pre[l2 - 1])));
				}
			}
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
