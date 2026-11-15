// 原始稿：04_训练与工具/牛客新手130题/12/85.cpp
// 原文行号：1-44；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int len = s.size();
    stack<char> st;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a')
        {
            st.push(s[i]);
        }
        else if (s[i] == 'b')
        {
            if (st.empty())
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin>>s;

    stack<char> st;

    if (check(s))
    {
        cout<<"Good"<<endl;
    }
    else
    {
        cout<<"Bad"<<endl;
    }

    return 0;
}
