// 原始稿：03_题目/牛客/contest/01/e.cpp
// 原文行号：1-37；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    
    while (T--)
    {
        int n, k;
        cin>>n>>k;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        int maxx = a[0] + k;
        maxx = max(maxx, a[n - 1] + k);
        for (int i = 0; i < n - 1; i++)
        {
            maxx = max(maxx, a[i] + a[i + 1]);
        }
        
        cout<<maxx<<endl;
    }

    return 0;
}
