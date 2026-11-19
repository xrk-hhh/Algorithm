#include <bits/stdc++.h>
using namespace std;

struct SA
{
    vector<int> sa, rk, h;
    SA(string s)
    {
        int n = s.size();
        sa.resize(n);
        rk.resize(n);
        h.resize(n);
        if (!n)
            return;
        vector<int> x(n), y(n), c(max(n, 256));
        for (int i = 0; i < n; i++)
            x[i] = (unsigned char)s[i], c[x[i]]++;
        for (int i = 1; i < 256; i++)
            c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--)
            sa[--c[x[i]]] = i;
        int m = 256;
        for (int k = 1; k < n; k <<= 1)
        {
            int p = 0;
            for (int i = n - k; i < n; i++)
                y[p++] = i;
            for (int i : sa)
                if (i >= k)
                    y[p++] = i - k;
            fill(c.begin(), c.begin() + m, 0);
            for (int v : x)
                c[v]++;
            for (int i = 1; i < m; i++)
                c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; i--)
                sa[--c[x[y[i]]]] = y[i];
            y[sa[0]] = 0;
            p = 1;
            for (int i = 1; i < n; i++)
            {
                int a = sa[i - 1], b = sa[i];
                if (x[a] != x[b] ||
                    (a + k < n ? x[a + k] : -1) !=
                        (b + k < n ? x[b + k] : -1))
                    p++;
                y[b] = p - 1;
            }
            x.swap(y);
            m = p;
            if (p == n)
                break;
        }
        for (int i = 0; i < n; i++)
            rk[sa[i]] = i;
        for (int i = 0, k = 0; i < n; i++)
        {
            if (!rk[i])
            {
                k = 0;
                continue;
            }
            int j = sa[rk[i] - 1];
            while (i + k < n && j + k < n &&
                   s[i + k] == s[j + k])
                k++;
            h[rk[i]] = k;
            if (k)
                k--;
        }
    }
}; // 0基；h[i]=LCP(sa[i-1],sa[i])，h[0]=0
