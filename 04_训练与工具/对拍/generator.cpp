#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n = rng() % 10 + 1;
	cout<<n<<endl;
	
	for (int i = 1; i <= n; i++)
	{
		cout<<rng() % 1000000000 + 1<<" ";
	}
	cout<<endl;
	
	return 0;
}
