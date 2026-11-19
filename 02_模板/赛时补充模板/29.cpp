#include <bits/stdc++.h>
using namespace std;

vector<long long> catalan(int n, long long mod)
{
    vector<long long> c(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            c[i] = (c[i] + c[j] * c[i - 1 - j]) % mod;
    return c;
}
