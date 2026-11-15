// 原始稿：03_题目/蓝桥杯/国赛/P_9427_蓝桥杯_2023_国_B_拼数字.cpp
// 原文行号：1-179；恢复外层注释 1 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int mod = 2023;
// 连续相同数字的循环节长度
const int cycle = 816;

// 循环左移 s 位（模 MOD）
bitset<mod> shift(const bitset<mod>& b, int s)
{
    s = (s % mod + mod) % mod;
    if (s == 0)
    {
        return b;
    }

    return (b << s) | (b >> (mod - s));
}

// 快速幂
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        b >>= 1;
         a = a * a % mod;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        int n, m;
        cin>>n>>m;

        // 1. 计算前后缀816的倍数
        // 前缀 3 个数
        int t = m / cycle * cycle;
        // 后缀 2 个数
        int s = n / cycle * cycle;
        // 中间段长度
        int rem = m - t + n - s;

        // 留出缓冲
        if (s)
        {
            s -= cycle;
            // 给中间补816个2，保证缓冲
            rem += cycle;
        }

        // 中间段还需要选的 3 个数
        int mm = m - t;
        // 2. 预处理中间段每一位的权值（从2变成3时对余数的贡献）
        vector<int> a(rem + 1, 0);
        // 最低位
        a[rem] = ksm(10, t * cycle);

        // 3. 全2余数
        for (int i = rem - 1; i >= 1; i--)
        {
            a[i] = a[i + 1] * 10 % mod;
        }
        // 计算中间段全为2时的余数 r
        int r = 0;
        for (int i = 1; i <= rem; i++)
        {
            r = (r + (a[i] << 1)) % mod;
        }
        // 目标余数：需要增加的余数 target
        int tar = (mod - r) % mod;

        // 3. DP，dp[i][j] 表示从位置i到n，选j个3能得到的余数集合
        vector<vector<bitset<mod>>> dp(rem + 2, vector<bitset<mod>>(mm + 1));
        dp[rem + 1][0].set(0);
        for (int i = rem; i >= 1; i--)
        {
            for (int j = 0; j <= mm; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    // 不选i：dp[i+1][j]；选i：dp[i+1][j-1] 左移 a[i]
                    auto cur = shift(dp[i + 1][j - 1], a[i]);
                    dp[i][j] = dp[i + 1][j] | cur;
                }
            }
        }

        // 4. 检查是否有解
        if (!dp[1][mm][tar])
        {
            cout<<-1<<endl;
            return 0;
        }

        // 5. 贪心构造最优解（3尽量靠左）
        // 记录选择3的位置（中间段的内部下标1~n）
        vector<int> pos3;
        int j = mm, k = tar;
        for (int i = 1; i <= rem; i++)
        {
            if (j == 0)
            {
                break;
            }

            int nxt = (k - a[i] + mod) % mod;
            if (dp[i + 1][j - 1][nxt])
            {
                pos3.push_back(i);
                j--;
                k = nxt;
            }
        }

        // 6. 输出
        // 前缀 t个3
        for (int i = 0; i < t; i++)
        {
            cout<<'3';
        }
        // 中间段：按照pos3插入3，其余是2
        pos3.push_back(rem + 1);
        int last = 0;
        for (int p : pos3)
        {
            // 输出last+1 到 p-1 之间的2
            for (int i = last + 1; i < p; i++)
            {
                cout<<'2';
            }
            // 选择3的位置
            if (p != rem + 1)
            {
                cout<<'3';
            }

            last = p;
        }
        // 后缀 s个2
        for (int i=  0; i < s; i++)
        {
            cout<<'2';
        }
        cout<<endl;
    }

    return 0;
}

// // 40%分数解法
// // 设 dp[i][j] 为一个 bitset<2023>，表示用 i 个 2 和 j 个 3 任意排列能组成的所有余数集合
// // 转移：在已有排列的最低位追加一个数字：
// // 贪心时，设已经确定的前缀余数为 R，剩余 a 个 2 和 b 个 3，总剩余长度 len=a+b。
// // 若本位放 d (2 或 3)，新前缀余数 R′=(R×10+d)mod2023。
// // 最终整个数要求模 2023=0，则剩余部分需满足：(R′×10^len+X)mod2023=0⇒X≡−R′×10^len (mod2023)
// // 其中 X 是由剩余a ′个 2 和b′个 3 组成的任意排列的余数。因此只需检查 dp[a′][b′] 中是否包含目标余数。
// // 优先尝试放 3，若不合法再放 2，即可得到字典序最大的解。
