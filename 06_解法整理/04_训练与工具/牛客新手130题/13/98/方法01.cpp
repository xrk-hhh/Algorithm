// 原始稿：04_训练与工具/牛客新手130题/13/98.cpp
// 原文行号：1-36；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

int cnt[1010];

int main() 
{
    int M, N;
    cin>>M>>N;

    int ans = 0;

    queue<int> q;

    while (N--)
    {
        int w;
        cin>>w;
        
        if (q.size() > M)
        {
            cnt[q.front()]--;
            q.pop();
        }
        if (cnt[w] == 0)
        {
            q.push(w);
            cnt[w]++;
            ans++;
        }
    }

    cout<<ans;

    return 0;
}
