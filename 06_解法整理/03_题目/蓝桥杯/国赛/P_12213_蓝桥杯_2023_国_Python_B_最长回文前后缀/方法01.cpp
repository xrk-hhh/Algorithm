// 原始稿：03_题目/蓝桥杯/国赛/P_12213_蓝桥杯_2023_国_Python_B_最长回文前后缀.cpp
// 原文行号：1-164；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

const int N = 1e5;
const int B = 131, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int n;
string s, rev;
ll p1[N * 2 + 10], p2[N * 2 + 10];
vector<ll> h1, h2;
vector<ll> rh1, rh2;

void initP(int len)
{
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        p1[i] = p1[i - 1] * B % mod1;
        p2[i] = p2[i - 1] * B % mod2;
    }
}

void initH(const string& t, vector<ll>& ha1, vector<ll>& ha2)
{
    ha1.resize(n + 1);
    ha2.resize(n + 1);
    ha1[0] = ha2[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ha1[i] = (ha1[i - 1] * B + t[i]) % mod1;
        ha2[i] = (ha2[i - 1] * B + t[i]) % mod2;
    }
}

pair<ll, ll> getH(const vector<ll>& ha1, const vector<ll>& ha2, int l, int r)
{
    ll v1 = (ha1[r] - ha1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
    ll v2 = (ha2[r] - ha2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;

    return {v1, v2};
}

pair<ll, ll> concat(pair<ll, ll> hash1, int len1, pair<ll, ll> hash2, int len2)
{
    ll v1 = (hash1.first * p1[len2] + hash2.first) % mod1;
    ll v2 = (hash1.second * p2[len2] + hash2.second) % mod2;

    return {v1, v2};
}

bool check(int L)
{
    for (int i = max(0, L - n); i <= min(n, L); i++)
    {
        int j = n - L + i + 1;
        if (j < 1 || j > n + 1)
        {
            continue;
        }

        int preL = i, sufL = n - j + 1;

        pair<ll, ll> hashP;
        if (preL == 0)
        {
            hashP = getH(h1, h2, j, n);
        }
        else if (sufL == 0)
        {
            hashP = getH(h1, h2, 1, i);
        }
        else
        {
            auto pre = getH(h1, h2, 1, i);
            auto suf = getH(h1, h2, j, n);

            hashP = concat(pre, preL, suf, sufL);
        }

        pair<ll, ll> hashS;
        if (preL == 0)
        {
            hashS = getH(rh1, rh2, 1, sufL);
        }
        else if (sufL == 0)
        {
            hashS = getH(rh1, rh2, n - i + 1, n);
        }
        else
        {
            auto rsuf = getH(rh1, rh2, 1, sufL);
            auto rpre = getH(rh1, rh2, n - i + 1, n);

            hashS = concat(rsuf, sufL, rpre, preL);
        }

        if (hashP == hashS)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        cin>>s;
        n = s.size();
        rev = s;
        reverse(rev.begin(), rev.end());
        s = " " + s;
        rev = " " + rev;
        
        initP(2 * n);
        initH(s, h1, h2);
        initH(rev, rh1, rh2);

        int l = 1, r = 2 * n + 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        cout<<r<<endl;
    }

    return 0;
}

// 以上是哈希 + 二分，但只能拿 90%，策略问题

// 以下是新策略：

// 令 T = reverse(S)，先求 S 和 T 的最长公共前缀长度（直接暴力匹配）

// 剩余部分：
// 若 L == n，则整个串已经对称，答案是 2*n
// 否则，设 S' = S[L+1 .. n]，T' = T[L+1 .. n]
// 答案 = 2*L + max( S' 的最长回文前缀长度, T' 的最长回文后缀长度 )（注意 T' 的最长回文后缀相当于 S 的对称部分）

// 求一个字符串的最长回文前缀（或后缀）可以用 哈希 + 二分回文半径 实现：
// 枚举所有可能的回文中心（奇数和偶数长度），对每个中心二分最大扩展半径，判断回文用哈希 O(1) 完成
// 在所有以位置 1 为起点的回文串中取最大长度，即为最长回文前缀
// 最长回文后缀同理，或直接对反转后的串求最长回文前缀
