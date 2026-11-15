// 原始稿：04_训练与工具/牛客新手130题/12/87.cpp
// 原文行号：1-51；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here
        int len = s.size();
        stack<char> st;

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }
            else if (s[i] == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
