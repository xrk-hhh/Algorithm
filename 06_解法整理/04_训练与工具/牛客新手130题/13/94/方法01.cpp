// 原始稿：04_训练与工具/牛客新手130题/13/94.cpp
// 原文行号：1-35；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param students int整型vector 
     * @param sandwiches int整型vector 
     * @return int整型
     */

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // write code here
        int cnt[2] = {0, 0};
        for (int i = 0; i < students.size(); i++)
        {
            cnt[students[i]]++;
        }
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (cnt[sandwiches[i]] > 0)
            {
                cnt[sandwiches[i]]--;
            }
            else 
            {
                break;
            }
        }
        return cnt[0] + cnt[1];
    }
};
