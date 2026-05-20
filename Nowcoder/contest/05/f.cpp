#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const int lcm = 56;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin>>T;

    while (T--)
    {
        int n, a, b;
        cin>>n>>a>>b;

        int c = a + b;

        vector<int> dp(lcm + 1, 0);
        for (int i = 1; i <= lcm; i++)
        {
            if (i >= 2)
            {
                dp[i] = max(dp[i], dp[i - 2] + b);
            }

            if (i >= 7)
            {
                dp[i] = max(dp[i], dp[i - 7] + a);
            }

            if (i >= 8)
            {
                dp[i] = max(dp[i], dp[i - 8] + c);
            }
        }

        if (n < lcm)
        {
            cout<<dp[n]<<endl;
            continue;
        }

        double va = a / 7.0;
        double vb = b / 2.0;
        double vc = c / 8.0;

        double v = max({va, vb, vc});

        int k = n / lcm;
        int r = n % lcm;

        int ans = 0;

        if (v == vb)
        {
            ans = k * lcm / 2 * b + dp[r]; 
        }
        else if (v == va)
        {
            ans = k * lcm / 7 * a + dp[r];
        }
        else
        {
            ans = k * lcm / 8 * c + dp[r];
        }

        cout<<ans<<endl;
    }

    return 0;
}