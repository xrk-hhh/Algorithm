#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int l, r, id;
};
// a使用0基下标，值先离散化至[0,V)；询问为闭区间
vector<long long> mo(vector<int> a, vector<Query> q, int V)
{
    int n = a.size(), B = max(1, (int)sqrt(n));
    sort(q.begin(), q.end(),
         [&](Query x, Query y)
         {
             if (x.l / B != y.l / B)
                 return x.l / B < y.l / B;
             return (x.l / B & 1) ? x.r > y.r : x.r < y.r;
         });
    vector<int> cnt(V);
    vector<long long> ans(q.size());
    long long cur = 0;
    int l = 0, r = -1;
    auto add = [&](int p)
    {
        int x = a[p];
        cur += 2LL * cnt[x] + 1;
        cnt[x]++;
    };
    auto del = [&](int p)
    {
        int x = a[p];
        cnt[x]--;
        cur -= 2LL * cnt[x] + 1;
    };
    for (auto x : q)
    {
        while (l > x.l)
            add(--l);
        while (r < x.r)
            add(++r);
        while (l < x.l)
            del(l++);
        while (r > x.r)
            del(r--);
        ans[x.id] = cur;
    }
    return ans;
}
