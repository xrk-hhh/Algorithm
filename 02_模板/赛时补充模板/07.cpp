#include <bits/stdc++.h>
using namespace std;

int st[200005][20], lg2[200005];
void build_st(int n, int *a)
{
    lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] =
                max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int rmq(int l, int r)
{
    int k = lg2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
