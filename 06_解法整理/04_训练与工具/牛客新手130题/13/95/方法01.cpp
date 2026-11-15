// 原始稿：04_训练与工具/牛客新手130题/13/95.cpp
// 原文行号：1-30；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tickets int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // write code here
        int time = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
            {
                time += min(tickets[i], tickets[k]);
            }
            else
            {
                time += min(tickets[i], tickets[k] - 1);
            }
        }
        return time;
    }
};
