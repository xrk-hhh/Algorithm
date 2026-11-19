#include <bits/stdc++.h>
using namespace std;

struct Lucas
{
    long long p;
    vector<long long> fac, inv;
    long long power(long long a, long long b)
    {
        long long z = 1;
        for (; b; b >>= 1, a = a * a % p)
            if (b & 1)
                z = z * a % p;
        return z;
    }
    Lucas(int prime) : p(prime), fac(prime), inv(prime)
    {
        fac[0] = 1;
        for (int i = 1; i < p; i++)
            fac[i] = fac[i - 1] * i % p;
        inv[p - 1] = power(fac[p - 1], p - 2);
        for (int i = p - 1; i; i--)
            inv[i - 1] = inv[i] * i % p;
    }
    long long C(long long n, long long k)
    {
        long long ans = 1;
        while (n || k)
        {
            int a = n % p, b = k % p;
            if (b > a)
                return 0;
            ans = ans * fac[a] % p * inv[b] % p * inv[a - b] % p;
            n /= p;
            k /= p;
        }
        return ans;
    }
}; // p为质数，O(p)空间；原题调用C(n+m,n)
