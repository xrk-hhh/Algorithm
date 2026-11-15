// 原始稿：04_训练与工具/牛客新手130题/14/104.cpp
// 原文行号：1-36；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param jewels string字符串 
     * @param stones string字符串 
     * @return int整型
     */
    int numJewelsInStones(string jewels, string stones) {
        // write code here

        set<char> s;

        for (int i = 0; i < jewels.size(); i++)
        {
            s.insert(jewels[i]);
        }

        int cnt = 0;

        for (int i = 0; i < stones.size(); i++)
        {
            if (s.count(stones[i]))
            {
                cnt++;
            }
        }

        return cnt;
    }
};
