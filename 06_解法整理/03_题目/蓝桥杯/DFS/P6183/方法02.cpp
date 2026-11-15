// 原始稿：03_题目/蓝桥杯/DFS/P6183.cpp
// 原文行号：95-183；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

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

        // 反射法 构造格雷码

        vector<string> gray;
        // 当 n = 1时，格雷码为 ["0", "1"]
        gray.push_back("0");
        gray.push_back("1");

        // 当 n > 1时，先得到 n - 1位的格雷码列表
        // 然后前半部分每个前面加 "0"
        // 后半部分每个前面加 "1" 并逆序
        
        for (int i = 2; i <= n; i++)
        {
            vector<string> next;
            // 前半部分加 0
            for (const string s : gray)
            {
                next.push_back("0" + s);
            }

            // 后半部分加 1 并逆序
            for (int j = gray.size() - 1; j >= 0; j--)
            {
                next.push_back("1" + gray[j]);
            }
            gray = move(next);
        }

        // // 二进制 转 格雷码 公式
        // // g(i) = i 异或 (i >> 1)

        // for (int i = 0; i < (1 << n); i++)
        // {
        //     int g = i ^ (i >> 1);
        //     for (int bit = n - 1; bit >= 0; bit--)
        //     {
        //         if ((g >> bit) & 1)
        //         {
        //             cout<<'X';
        //         }
        //         else
        //         {
        //             cout<<'O';
        //         }
        //     }
        //     cout<<endl;
        // }


        for (const string s : gray)
        {
            for (char c : s)
            {
                if (c == '0')
                {
                    cout<<'O';
                }
                else if (c == '1')
                {
                    cout<<'X';
                }
            }
            cout<<endl;
        }

        cout<<string(n, 'O')<<endl;
    }

    return 0;
}
