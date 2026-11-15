// 原始稿：03_题目/蓝桥杯/模拟/P12164.cpp
// 原文行号：1-36；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const string s = "2025";
const int mod = 4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int h, w;
        cin>>h>>w;

        for (int i = 0; i < h; i++)
        {
            int cnt = i % mod;
            for (int j = 0; j < w; j++)
            {
                cout<<s[cnt % mod];
                cnt++;
            }
            cout<<endl;
        }
    }

    return 0;
}
