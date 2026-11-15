// 原始稿：04_训练与工具/牛客新手130题/13/93.cpp
// 原文行号：1-49；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() 
{
    int n;
    cin>>n;

    while (n--)
    {
        int op;
        cin>>op;
        switch(op)
        {
            case 1:
                int x;
                cin>>x;
                q.push(x);
                break;
            case 2:
                if (q.empty())
                {
                    cout<<"ERR_CANNOT_POP"<<endl;
                }
                else
                {
                    q.pop();
                }
                break;
            case 3:
                if (q.empty())
                {
                    cout<<"ERR_CANNOT_QUERY"<<endl;
                }
                else
                {
                    cout<<q.front()<<endl;
                }
                break;
            case 4:
                cout<<q.size()<<endl;
                break;
        }
    }

    return 0;
}
