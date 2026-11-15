// 原始稿：04_训练与工具/牛客新手130题/07/47.cpp
// 原文行号：1-30；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int tree[10010];

int main()
{
    int L, M;
    cin>>L>>M;

    int cnt = L + 1;
    while (M--)
    {
        int l, r;
        cin>>l>>r;

        for (int i = l; i <= r; i++)
        {
            if (tree[i] == 0)
            {
                cnt--;
                tree[i] = 1;
            }
        }
    }

    cout<<cnt;

    return 0;
}
