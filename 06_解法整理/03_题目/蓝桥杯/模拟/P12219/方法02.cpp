// 原始稿：03_题目/蓝桥杯/模拟/P12219.cpp
// 原文行号：209-287；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

// 从字符串的指定位置开始解析连续数字
int parseNumber(const string& s, int& pos) 
{
    int val = 0;
    while (pos < s.size() && isdigit(s[pos])) 
    {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    return val;
}

int main() 
{
    string s;
    cin >> s;
    int qpos = s.find('?');
    int eqpos = s.find('=');

    if (qpos == 0) 
    { // 缺失 A
        int pos = qpos + 1;
        char op = s[pos++];
        int B = parseNumber(s, pos);
        pos = eqpos + 1;
        int C = parseNumber(s, pos);
        int A;
        if (op == '+') A = C - B;
        else if (op == '-') A = C + B;
        else if (op == '*') A = C / B;
        else if (op == '/') A = C * B;
        cout << A << endl;
    }
    else if (qpos == s.size() - 1) 
    { // 缺失 C
        int pos = 0;
        int A = parseNumber(s, pos);
        char op = s[pos++];
        int B = parseNumber(s, pos);
        int C;
        if (op == '+') C = A + B;
        else if (op == '-') C = A - B;
        else if (op == '*') C = A * B;
        else if (op == '/') C = A / B;
        cout << C << endl;
    }
    else if (s[qpos + 1] == '=') 
    { // 缺失 B
        int pos = 0;
        int A = parseNumber(s, pos);
        char op = s[pos++];
        pos++; // 跳过 ?
        pos = eqpos + 1;
        int C = parseNumber(s, pos);
        int B;
        if (op == '+') B = C - A;
        else if (op == '-') B = A - C;
        else if (op == '*') B = C / A;
        else if (op == '/') B = A / C;
        cout << B << endl;
    }
    else 
    { // 缺失运算符
        int pos = 0;
        int A = parseNumber(s, pos);
        pos++; // 跳过 ?
        int B = parseNumber(s, pos);
        pos = eqpos + 1;
        int C = parseNumber(s, pos);
        if (A + B == C) cout << '+' << endl;
        else if (A - B == C) cout << '-' << endl;
        else if (A * B == C) cout << '*' << endl;
        else if (A / B == C) cout << '/' << endl;
    }
    return 0;
}
