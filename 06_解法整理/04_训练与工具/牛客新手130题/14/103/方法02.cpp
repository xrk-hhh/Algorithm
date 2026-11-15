// 原始稿：04_训练与工具/牛客新手130题/14/103.cpp
// 原文行号：35-69；恢复外层注释 1 层；保留方法内部注释。
// 补入原共享头文件或评测接口所需的标准库头文件。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return bool布尔型
     */

    bool happynum(int n) {
        // write code here
        multiset<int> s;
        while (n != 1)
        {
            if (s.count(n))
            {
                return false;
            }

            s.insert(n);

            int sum = 0;
            int tmp = n;
            while (tmp)
            {
                int num = tmp % 10;
                sum += num * num;
                tmp /= 10;
            }
            n = sum;
        }
        return true;
    }
};
