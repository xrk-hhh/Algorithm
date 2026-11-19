#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, G = 3;
int power(int a, int b)
{
    int z = 1;
    for (; b; b >>= 1, a = 1LL * a * a % MOD)
        if (b & 1)
            z = 1LL * z * a % MOD;
    return z;
}
void ntt(vector<int> &a, bool inv)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int b = n >> 1;
        for (; j & b; b >>= 1)
            j ^= b;
        j ^= b;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        int w0 = power(G, (MOD - 1) / len);
        if (inv)
            w0 = power(w0, MOD - 2);
        for (int i = 0; i < n; i += len)
        {
            long long w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                int u = a[i + j],
                    v = w * a[i + j + len / 2] % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * w0 % MOD;
            }
        }
    }
    if (inv)
    {
        int z = power(n, MOD - 2);
        for (int &x : a)
            x = 1LL * x * z % MOD;
    }
}
vector<int> convolution(vector<int> a, vector<int> b)
{
    if (a.empty() || b.empty())
        return {};
    int need = a.size() + b.size() - 1, n = 1;
    while (n < need)
        n <<= 1;
    a.resize(n);
    b.resize(n);
    for (int &x : a)
        x = (x % MOD + MOD) % MOD;
    for (int &x : b)
        x = (x % MOD + MOD) % MOD;
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; i++)
        a[i] = 1LL * a[i] * b[i] % MOD;
    ntt(a, true);
    a.resize(need);
    return a;
} // 模998244353，长度<=2^23；不用于要求精确整数系数的FFT题

using cd = complex<double>;
void fft(vector<cd> &a, bool inv)
{
    int n = a.size();
    const double PI = acos(-1);
    for (int i = 1, j = 0; i < n; i++)
    {
        int b = n >> 1;
        for (; j & b; b >>= 1)
            j ^= b;
        j ^= b;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        cd w0 = polar(1.0, (inv ? -2 : 2) * PI / len);
        for (int i = 0; i < n; i += len)
        {
            cd w = 1;
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = w * a[i + j + len / 2];
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= w0;
            }
        }
    }
    if (inv)
        for (cd &x : a)
            x /= n;
}
vector<long long> convolution_integer(const vector<int> &a,
                                      const vector<int> &b)
{
    if (a.empty() || b.empty())
        return {};
    int need = a.size() + b.size() - 1, n = 1;
    while (n < need)
        n <<= 1;
    vector<cd> x(n), y(n);
    for (int i = 0; i < (int)a.size(); i++)
        x[i] = a[i];
    for (int i = 0; i < (int)b.size(); i++)
        y[i] = b[i];
    fft(x, false);
    fft(y, false);
    for (int i = 0; i < n; i++)
        x[i] *= y[i];
    fft(x, true);
    vector<long long> c(need);
    for (int i = 0; i < need; i++)
        c[i] = llround(x[i].real());
    return c;
} // 整数卷积；精度取决于长度和系数，较大系数需拆分
