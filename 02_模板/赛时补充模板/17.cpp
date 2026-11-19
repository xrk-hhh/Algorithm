#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x, y;
    bool operator<(const Point &o) const
    {
        return x != o.x ? x < o.x : y < o.y;
    }
    bool operator==(const Point &o) const
    {
        return x == o.x && y == o.y;
    }
};
long long cr(Point a, Point b, Point c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
long long dist2(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
vector<Point> hull(vector<Point> p)
{
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    if (p.size() < 2)
        return p;
    vector<Point> h;
    for (auto q : p)
    {
        while (h.size() > 1 &&
               cr(h[h.size() - 2], h.back(), q) <= 0)
            h.pop_back();
        h.push_back(q);
    }
    int k = h.size();
    for (int i = (int)p.size() - 2; i >= 0; i--)
    {
        while ((int)h.size() > k &&
               cr(h[h.size() - 2], h.back(), p[i]) <= 0)
            h.pop_back();
        h.push_back(p[i]);
    }
    h.pop_back();
    return h;
}
long long diameter2(const vector<Point> &h)
{
    int n = h.size(), j = 1;
    long long ans = 0;
    if (n < 2)
        return 0;
    for (int i = 0; i < n; i++)
    {
        int k = (i + 1) % n;
        while (cr(h[i], h[k], h[(j + 1) % n]) >
               cr(h[i], h[k], h[j]))
            j = (j + 1) % n;
        ans = max({ans, dist2(h[i], h[j]), dist2(h[k], h[j])});
    }
    return ans;
} // h逆时针、不重复首点；坐标差平方/叉积须不溢出
