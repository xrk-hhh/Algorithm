// 原始稿：03_题目/AtCoder/abc_455/A_455.cpp
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int a, b, c;
        cin>>a>>b>>c;

        if (a != b && b == c)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
