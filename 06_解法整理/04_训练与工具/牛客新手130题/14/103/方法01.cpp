// 原始稿：04_训练与工具/牛客新手130题/14/103.cpp
// 原文行号：1-34；恢复外层注释 2 层；保留方法内部注释。
// 补入原共享头文件或评测接口所需的标准库头文件。
#include <bits/stdc++.h>
using namespace std;
// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return bool布尔型
     */

    int happy(int t)
    {
        int res = 0;
        while (t)
        {
            res += (t % 10) * (t % 10);
            t /= 10;
        }
        return res;
    }

    bool happynum(int n) {
        // write code here
        while (n > 9)
        {
            n = happy(n);
        }
        return n == 1;
    }
};
