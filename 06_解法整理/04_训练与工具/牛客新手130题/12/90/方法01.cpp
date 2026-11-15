// 原始稿：04_训练与工具/牛客新手130题/12/90.cpp
// 原文行号：1-35；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1E6 + 10

vector<int> a(MAXN), maxx(MAXN);
stack<int> st;

int main()
{
    int n;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        maxx[i] = max(maxx[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        st.push(a[i]);
        while (!st.empty() && st.top() > maxx[i + 1])
        {
            cout<<st.top()<<' ';
            st.pop();
        }
    }

    return 0;
}
