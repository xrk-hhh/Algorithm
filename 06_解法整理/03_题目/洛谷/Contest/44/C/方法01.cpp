// 原始稿：03_题目/洛谷/Contest/44/C.cpp
// 原文行号：1-38；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, x, y;
        cin>>n>>x>>y;

        int cnt = 0;
        int maxx = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin>>a;

            if ((x + y == a) || (x + a == y) || (a + y == x) || (x * y == a) || (x * a == y) || (a * y == x))
            {
                cnt++;
                maxx = max(maxx, a);
            }
        }

        cout<<cnt<<' '<<maxx<<endl;
    }

    return 0;
}
