// 原始稿：03_题目/蓝桥杯/模拟/P12366.cpp
// 原文行号：1-62；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

struct num
{
    int x, sum;
};

vector<num> d;

void pre(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        num a;
        a.x = i;
        a.sum = sum;
        d.push_back(a);
    }
}

bool cmp(num a, num b)
{
    if (a.sum != b.sum)
    {
        return a.sum < b.sum;
    }
    return a.x < b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        pre(n);

        sort(d.begin(), d.end(), cmp);

        cout<<d[m - 1].x<<endl;
    }

    return 0;
}
