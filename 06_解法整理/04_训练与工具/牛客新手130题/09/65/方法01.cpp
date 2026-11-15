// 原始稿：04_训练与工具/牛客新手130题/09/65.cpp
// 原文行号：1-23；恢复外层注释 1 层；保留方法内部注释。
// 补入原共享头文件或评测接口所需的标准库头文件。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断二元一次方程组是否有解
     * @param a int整型 二次项系数
     * @param b int整型 一次项系数
     * @param c int整型 常数项
     * @return bool布尔型
     */
    bool judgeSolutions(int a, int b, int c) {
        int derta = b * b - 4 * a * c;
        if (derta >= 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};
