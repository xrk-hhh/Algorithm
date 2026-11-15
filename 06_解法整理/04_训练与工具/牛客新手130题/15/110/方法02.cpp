// 原始稿：04_训练与工具/牛客新手130题/15/110.cpp
// 原文行号：35-74；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;

    priority_queue<int, vector<int>, greater<int> > pq;
    int maxx = 0;

    while (n--)
    {
        int x;
        cin>>x;
        pq.push(x);
        maxx = max(maxx, x);
    }
    while (m--)
    {
        int b;
        cin>>b;
        
        int minn = pq.top();
        pq.pop();
        minn += b;
        pq.push(minn);

        maxx = max(maxx, minn);

        cout<<maxx<<endl;
    }

    return 0;
}
