// 原始稿：04_训练与工具/牛客新手130题/09/68.cpp
// 原文行号：1-22；恢复外层注释 1 层；保留方法内部注释。
// 补入原共享头文件或评测接口所需的标准库头文件。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 进行凯撒解密
     * @param password string字符串 旺仔哥哥的密码
     * @param n int整型 每个字符加密过程中错位的次数
     * @return string字符串
     */
    string decodeWangzai(string password, int n) {
        int shift = n % 26;
        for (int i = 0; i < password.size(); i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                password[i] = (password[i]  - 'a' +26 - shift) % 26 + 'a';
            }
        }
        return password;
    }
};
