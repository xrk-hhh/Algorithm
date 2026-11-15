// 原始稿：03_题目/蓝桥杯/DFS/P15435.cpp
// 原文行号：84-145；恢复外层注释 2 层；保留方法内部注释。
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

        // 初始化升序排列
        vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8};
        int cur = -1;
        int ans = 1e9;

        do
        {
            // 将当前排列转化为 8 位数字符串
            string s;
            for (int d : digits)
            {
                s += d + '0';
            }

            // 枚举插入位置和插入数字
            for (int pos = 0; pos <= 8; pos++)
            {
                for (int d = 1; d <= 8; d++)
                {
                    string t = s;
                    t.insert(pos, 1, d + '0');

                    int num = stoi(t);
                    int g = __gcd(num, n);
                    if (g > cur)
                    {
                        cur = g;
                        ans = num;
                    }
                    else if (g == cur)
                    {
                        ans = min(ans, num);
                    }
                }
            }
        }
        while (next_permutation(digits.begin(), digits.end()));

        cout<<ans<<endl;
    }

    return 0;
}
