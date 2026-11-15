// 原始稿：03_题目/蓝桥杯/2/2.4/04.cpp
// 原文行号：1-79；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int n, k;
vector<int> a;
int ans = 0;

bool check(int x)
{
    if (x == 1)
    {
        return false;
    }
    if (x == 2)
    {
        return true;
    }

    if (!(x & 1))
    {
        return false;
    }

    int tmp = sqrt(x);
    for (int i = 3; i <= tmp; i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void dfs(int idx, int sum, int cnt)
{
    if (cnt == k)
    {
        if (check(sum))
        {
            ans++;
        }
        return;
    }

    for (int i = idx + 1; i < n; i++)
    {
        dfs(i, sum + a[i], cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>n>>k;

        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        dfs(-1, 0, 0);

        cout<<ans<<endl;
    }

    return 0;
}
