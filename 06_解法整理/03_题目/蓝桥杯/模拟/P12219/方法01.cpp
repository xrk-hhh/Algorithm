// 原始稿：03_题目/蓝桥杯/模拟/P12219.cpp
// 原文行号：1-208；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        string s;
        cin>>s;

        int n = s.size();
        // '?' 索引
        int idx = 0;
        while (s[idx] != '?')
        {
            idx++;
        }

        // A 是 '?'
        if (idx == 0)
        {
            char op = s[idx + 1];
            int b = 0, c = 0;
            // 是否找到 '='
            bool ok = false;
            for (int i = idx + 2; i < n; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    if (!ok)
                    {
                        b = b * 10 + s[i] - '0';
                    }
                    else
                    {
                        c = c * 10 + s[i] - '0';
                    }
                }
                if (s[i] == '=')
                {
                    ok = true;
                }
            }

            if (op == '+')
            {
                cout<<c - b<<endl;
                continue;
            }
            else if (op == '-')
            {
                cout<<c + b<<endl;
                continue;
            }
            else if (op == '*')
            {
                cout<<c / b<<endl;
                continue;
            }
            else if (op == '/')
            {
                cout<<c * b<<endl;
                continue;
            }
        }
        // C 是 '?'
        else if (idx == n - 1)
        {
            char op;
            int a = 0, b = 0;
            // 是否找到 '='
            bool ok = false;
            for (int i = 0; i < n; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    if (!ok)
                    {
                        a = a * 10 + s[i] - '0';
                    }
                    else
                    {
                        b = b * 10 + s[i] - '0';
                    }
                }
                else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                {
                    op = s[i];
                    ok = true;
                }
            }

            if (op == '+')
            {
                cout<<a + b<<endl;
                continue;
            }
            else if (op == '-')
            {
                cout<<a - b<<endl;
                continue;
            }
            else if (op == '*')
            {
                cout<<a * b<<endl;
                continue;
            }
            else if (op == '/')
            {
                cout<<a / b<<endl;
                continue;
            }
        }
        // B 是 '?'
        else if (s[idx - 1] == '+' || s[idx - 1] == '-' || s[idx - 1] == '*' || s[idx - 1] == '/')
        {
            char op = s[idx - 1];
            int a = 0, c = 0;
            for (int i = 0; i < idx - 1; i++)
            {
                a = a * 10 + s[i] - '0';
            }
            for (int i = idx + 2; i < n; i++)
            {
                c = c * 10 + s[i] - '0';
            }

            if (op == '+')
            {
                cout<<c - a<<endl;
                continue;
            }
            else if (op == '-')
            {
                cout<<a - c<<endl;
                continue;
            }
            else if (op == '*')
            {
                cout<<c / a<<endl;
                continue;
            }
            else if (op == '/')
            {
                cout<<a / c<<endl;
                continue;
            }
        }
        // op 是 '?'
        else
        {
            int a = 0, b = 0, c = 0;
            // 是否找到 '='
            bool ok = false;
            for (int i = 0; i < idx; i++)
            {
                a = a * 10 + s[i] - '0';
            }
            for (int i = idx + 1; i < n; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    if (!ok)
                    {
                        b = b * 10 + s[i] - '0';
                    }
                    else
                    {
                        c = c * 10 + s[i] - '0';
                    }
                }
                else if (s[i] == '=')
                {
                    ok = true;
                }
            }

            if (a + b == c)
            {
                cout<<'+'<<endl;
            }
            else if (a - b == c)
            {
                cout<<'-'<<endl;
            }
            else if (a * b == c)
            {
                cout<<'*'<<endl;
            }
            else if (a / b == c)
            {
                cout<<'/'<<endl;
            }
        }
    }

    return 0;
}
