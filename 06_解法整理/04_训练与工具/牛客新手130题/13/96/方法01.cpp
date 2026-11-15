// 原始稿：04_训练与工具/牛客新手130题/13/96.cpp
// 原文行号：1-28；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
