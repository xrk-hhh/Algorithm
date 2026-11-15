// 原始稿：03_题目/蓝桥杯/国赛/P_9427_蓝桥杯_2023_国_B_拼数字.cpp
// 原文行号：180-286；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

const int MOD = 2023;
const int MAXN = 500;  // 40% 数据限制

bitset<MOD> dp[MAXN + 1][MAXN + 1];
int pow10[MAXN * 2 + 5];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int L = N + M;

    // 预处理 10 的幂次
    pow10[0] = 1;
    for (int i = 1; i <= L; ++i)
    {
        pow10[i] = pow10[i - 1] * 10 % MOD;
    }

    // DP 计算所有可能的余数集合
    dp[0][0].set(0);
    for (int i = 0; i <= N; ++i) 
    {
        for (int j = 0; j <= M; ++j) 
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i > 0) 
            {
                // 从 dp[i-1][j] 转移，添加 2
                for (int r = 0; r < MOD; ++r) 
                {
                    if (dp[i - 1][j][r])
                    {
                        dp[i][j].set((r * 10 + 2) % MOD);
                    }
                }
            }
            if (j > 0) 
            {
                // 从 dp[i][j-1] 转移，添加 3
                for (int r = 0; r < MOD; ++r) 
                {
                    if (dp[i][j - 1][r])
                    {
                        dp[i][j].set((r * 10 + 3) % MOD);
                    }
                }
            }
        }
    }

    // 初始检查是否有解
    if (!dp[N][M][0]) 
    {
        cout << -1 << '\n';
        return 0;
    }

    // 贪心构造
    int curR = 0;   // 当前前缀余数
    int rem2 = N, rem3 = M;
    string ans;
    while (rem2 > 0 || rem3 > 0) 
    {
        int len = rem2 + rem3 - 1; // 放完本位后的剩余长度
        // 尝试放 3
        if (rem3 > 0) 
        {
            int nxtR = (curR * 10 + 3) % MOD;
            int target = (MOD - nxtR * pow10[len] % MOD) % MOD;
            if (dp[rem2][rem3 - 1][target]) 
            {
                ans.push_back('3');
                curR = nxtR;
                --rem3;
                continue;
            }
        }
        // 尝试放 2（此时 rem2 > 0 必然成立，否则无解）
        int nxtR = (curR * 10 + 2) % MOD;
        int target = (MOD - nxtR * pow10[len] % MOD) % MOD;
        if (dp[rem2 - 1][rem3][target]) 
        {
            ans.push_back('2');
            curR = nxtR;
            --rem2;
        } 
        else 
        {
            // 理论上不会发生
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << ans << '\n';
    return 0;
}
