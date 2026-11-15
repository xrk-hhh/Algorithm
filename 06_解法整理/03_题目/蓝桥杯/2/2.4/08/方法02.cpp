// 原始稿：03_题目/蓝桥杯/2/2.4/08.cpp
// 原文行号：101-153；恢复外层注释 1 层；保留方法内部注释。
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
        // dp得全部分，核心：选/不选
        // 主要围绕该数的 首尾数字 进行转移
        // dp[i] 表示以末尾数字i结尾的最长接龙子序列的长度
        // 对于一个数 num, 首位数字为 first，末尾数字为 last
        // 则以 num 为结尾的序列长度为 dp[first] + 1
        //                      选num      不选num
        // 则 dp[last] = max(dp[last], dp[first] + 1)

        int n;
        cin>>n;

        vector<int> dp(10, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;

            int last = x % 10;
            int first = x;
            while (first >= 10)
            {
                first /= 10;
            }
            dp[last] = max(dp[last], dp[first] + 1);
            // 也可以用字符串解决
        }

        int maxx = 0;
        for (int i = 0; i < 10; i++)
        {
            maxx = max(maxx, dp[i]);
        }
        cout<<n - maxx<<endl;
    }

    return 0;
}
