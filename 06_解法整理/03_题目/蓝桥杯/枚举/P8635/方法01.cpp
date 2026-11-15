// 原始稿：03_题目/蓝桥杯/枚举/P8635.cpp
// 原文行号：1-42；恢复外层注释 1 层；保留方法内部注释。
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
        int n;
        cin>>n;

        int x = sqrt(n);

        for (int a = 0; a <= x; a++)
        {
            for (int b = a; b <= x; b++)
            {
                for (int c = b; c <= x; c++)
                {
                    for (int d = c; d <= x; d++)
                    {
                        if (a * a + b * b + c * c + d * d == n)
                        {
                            cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
