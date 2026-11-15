// 原始稿：03_题目/蓝桥杯/国赛/P_12213_蓝桥杯_2023_国_Python_B_最长回文前后缀.cpp
// 原文行号：165-301；恢复外层注释 2 层；保留方法内部注释。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100005;
const int B = 131, M1 = 1e9 + 7, M2 = 1e9 + 9;

int n;
string s, rev;
ll h1[N], h2[N], rh1[N], rh2[N], p1[N], p2[N];

void init_hash(const string &str) 
{
    int len = str.size() - 1; // str 是 1-indexed
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= len; ++i) 
    {
        p1[i] = p1[i - 1] * B % M1;
        p2[i] = p2[i - 1] * B % M2;
        h1[i] = (h1[i - 1] * B + str[i]) % M1;
        h2[i] = (h2[i - 1] * B + str[i]) % M2;
    }
    // 反向哈希
    rh1[len + 1] = rh2[len + 1] = 0;
    for (int i = len; i >= 1; --i) 
    {
        rh1[i] = (rh1[i + 1] * B + str[i]) % M1;
        rh2[i] = (rh2[i + 1] * B + str[i]) % M2;
    }
}

pair<ll, ll> getH(int l, int r) 
{
    ll v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % M1 + M1) % M1;
    ll v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % M2 + M2) % M2;
    return {v1, v2};
}

pair<ll, ll> getRH(int l, int r) 
{
    ll v1 = (rh1[l] - rh1[r + 1] * p1[r - l + 1] % M1 + M1) % M1;
    ll v2 = (rh2[l] - rh2[r + 1] * p2[r - l + 1] % M2 + M2) % M2;
    return {v1, v2};
}

bool is_pal(int l, int r) 
{
    return getH(l, r) == getRH(l, r);
}

// 求字符串 str（1-indexed）的最长回文前缀长度
int longest_pal_prefix(const string &str) 
{
    int len = str.size() - 1;
    init_hash(str);
    int best = 1;
    for (int i = 1; i <= len; ++i) 
    {
        // 奇数长度回文，中心 i
        int lo = 0, hi = min(i - 1, len - i), ans = 0;
        while (lo <= hi) 
        {
            int mid = (lo + hi) >> 1;
            if (is_pal(i - mid, i + mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (i - ans == 1)
        {
            best = max(best, 2 * ans + 1);
        }
        // 偶数长度回文，中心 i, i+1
        if (i < len && str[i] == str[i + 1]) 
        {
            lo = 0, hi = min(i - 1, len - i - 1), ans = 0;
            while (lo <= hi) 
            {
                int mid = (lo + hi) >> 1;
                if (is_pal(i - mid, i + 1 + mid))
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            if (i - ans == 1)
            {
                best = max(best, 2 * ans + 2);
            }
        }
    }
    return best;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n = s.size();
    string rev = s;
    reverse(rev.begin(), rev.end());

    // 公共前缀
    int L = 0;
    while (L < n && s[L] == rev[L])
    {
        ++L;
    }
    if (L == n) 
    {
        cout<<2 * n<<'\n';
        return 0;
    }

    // 剩余部分
    string s_mid = " " + s.substr(L, n - L);
    string rev_mid = " " + rev.substr(L, n - L);

    int pre = longest_pal_prefix(s_mid);
    int suf = longest_pal_prefix(rev_mid); // rev 的前缀对应原串的后缀
    int add = max(pre, suf);
    cout<<2 * L + add<<'\n';

    return 0;
}

// 还是太复杂了，不如直接 马拉车(Malacher)
