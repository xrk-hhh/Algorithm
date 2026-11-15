// 原始稿：03_题目/蓝桥杯/1/1.2/01.cpp
// 原文行号：1-47；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

bool check(int x)
{
    for (int i = 1; x; i++)
    {
        int tmp = x % 10;
        if (((i & 1) && !(tmp & 1)) || (!(i & 1) && (tmp & 1)))
        {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n;
        cin>>n;

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (check(i))
            {
                cnt++;
            }
        }

        cout<<cnt<<endl;
    }

    return 0;
}
