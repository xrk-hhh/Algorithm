// 原始稿：04_训练与工具/牛客新手130题/12/91.cpp
// 原文行号：1-32；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<int> st;
    stack<int> minn;
    void push(int value) {
        st.push(value);
        if (minn.empty())
        {
            minn.push(value);
        }
        else if (minn.top() >= value)
        {
            minn.push(value);
        }
    }
    void pop() {
        if (!minn.empty() && minn.top() == st.top())
        {
            minn.pop();
        }
        st.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return minn.top();
    }
};
