// 原始稿：04_训练与工具/牛客新手130题/07/44.cpp
// 原文行号：1-34；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;

    while (T--)
    {
        int n, k;
        cin>>n>>k;

        int cnt = 0;
        int S = 0;
        while (n--)
        {
            int a;
            cin>>a;
            if (a >= k)
            {
                S += a;
            }
            else if (a == 0 && S >= 1)
            {
                S -= 1;
                cnt += 1;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
