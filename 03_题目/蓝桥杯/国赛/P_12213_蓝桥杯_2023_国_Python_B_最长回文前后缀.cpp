// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // const int N = 1e5;
// // const int B = 131, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

// // int n;
// // string s, rev;
// // ll p1[N * 2 + 10], p2[N * 2 + 10];
// // vector<ll> h1, h2;
// // vector<ll> rh1, rh2;

// // void initP(int len)
// // {
// //     p1[0] = p2[0] = 1;
// //     for (int i = 1; i <= len; i++)
// //     {
// //         p1[i] = p1[i - 1] * B % mod1;
// //         p2[i] = p2[i - 1] * B % mod2;
// //     }
// // }

// // void initH(const string& t, vector<ll>& ha1, vector<ll>& ha2)
// // {
// //     ha1.resize(n + 1);
// //     ha2.resize(n + 1);
// //     ha1[0] = ha2[0] = 0;
// //     for (int i = 1; i <= n; i++)
// //     {
// //         ha1[i] = (ha1[i - 1] * B + t[i]) % mod1;
// //         ha2[i] = (ha2[i - 1] * B + t[i]) % mod2;
// //     }
// // }

// // pair<ll, ll> getH(const vector<ll>& ha1, const vector<ll>& ha2, int l, int r)
// // {
// //     ll v1 = (ha1[r] - ha1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
// //     ll v2 = (ha2[r] - ha2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;

// //     return {v1, v2};
// // }

// // pair<ll, ll> concat(pair<ll, ll> hash1, int len1, pair<ll, ll> hash2, int len2)
// // {
// //     ll v1 = (hash1.first * p1[len2] + hash2.first) % mod1;
// //     ll v2 = (hash1.second * p2[len2] + hash2.second) % mod2;

// //     return {v1, v2};
// // }

// // bool check(int L)
// // {
// //     for (int i = max(0, L - n); i <= min(n, L); i++)
// //     {
// //         int j = n - L + i + 1;
// //         if (j < 1 || j > n + 1)
// //         {
// //             continue;
// //         }

// //         int preL = i, sufL = n - j + 1;

// //         pair<ll, ll> hashP;
// //         if (preL == 0)
// //         {
// //             hashP = getH(h1, h2, j, n);
// //         }
// //         else if (sufL == 0)
// //         {
// //             hashP = getH(h1, h2, 1, i);
// //         }
// //         else
// //         {
// //             auto pre = getH(h1, h2, 1, i);
// //             auto suf = getH(h1, h2, j, n);

// //             hashP = concat(pre, preL, suf, sufL);
// //         }

// //         pair<ll, ll> hashS;
// //         if (preL == 0)
// //         {
// //             hashS = getH(rh1, rh2, 1, sufL);
// //         }
// //         else if (sufL == 0)
// //         {
// //             hashS = getH(rh1, rh2, n - i + 1, n);
// //         }
// //         else
// //         {
// //             auto rsuf = getH(rh1, rh2, 1, sufL);
// //             auto rpre = getH(rh1, rh2, n - i + 1, n);

// //             hashS = concat(rsuf, sufL, rpre, preL);
// //         }

// //         if (hashP == hashS)
// //         {
// //             return true;
// //         }
// //     }

// //     return false;
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         cin>>s;
// //         n = s.size();
// //         rev = s;
// //         reverse(rev.begin(), rev.end());
// //         s = " " + s;
// //         rev = " " + rev;
        
// //         initP(2 * n);
// //         initH(s, h1, h2);
// //         initH(rev, rh1, rh2);

// //         int l = 1, r = 2 * n + 1;
// //         while (l < r)
// //         {
// //             int mid = (l + r + 1) >> 1;
// //             if (check(mid))
// //             {
// //                 l = mid;
// //             }
// //             else
// //             {
// //                 r = mid - 1;
// //             }
// //         }

// //         cout<<r<<endl;
// //     }

// //     return 0;
// // }

// // 以上是哈希 + 二分，但只能拿 90%，策略问题

// // 以下是新策略：

// // 令 T = reverse(S)，先求 S 和 T 的最长公共前缀长度（直接暴力匹配）

// // 剩余部分：
// // 若 L == n，则整个串已经对称，答案是 2*n
// // 否则，设 S' = S[L+1 .. n]，T' = T[L+1 .. n]
// // 答案 = 2*L + max( S' 的最长回文前缀长度, T' 的最长回文后缀长度 )（注意 T' 的最长回文后缀相当于 S 的对称部分）

// // 求一个字符串的最长回文前缀（或后缀）可以用 哈希 + 二分回文半径 实现：
// // 枚举所有可能的回文中心（奇数和偶数长度），对每个中心二分最大扩展半径，判断回文用哈希 O(1) 完成
// // 在所有以位置 1 为起点的回文串中取最大长度，即为最长回文前缀
// // 最长回文后缀同理，或直接对反转后的串求最长回文前缀
// // #include <bits/stdc++.h>
// // using namespace std;
// // using ll = long long;

// // const int N = 100005;
// // const int B = 131, M1 = 1e9 + 7, M2 = 1e9 + 9;

// // int n;
// // string s, rev;
// // ll h1[N], h2[N], rh1[N], rh2[N], p1[N], p2[N];

// // void init_hash(const string &str) 
// // {
// //     int len = str.size() - 1; // str 是 1-indexed
// //     p1[0] = p2[0] = 1;
// //     for (int i = 1; i <= len; ++i) 
// //     {
// //         p1[i] = p1[i - 1] * B % M1;
// //         p2[i] = p2[i - 1] * B % M2;
// //         h1[i] = (h1[i - 1] * B + str[i]) % M1;
// //         h2[i] = (h2[i - 1] * B + str[i]) % M2;
// //     }
// //     // 反向哈希
// //     rh1[len + 1] = rh2[len + 1] = 0;
// //     for (int i = len; i >= 1; --i) 
// //     {
// //         rh1[i] = (rh1[i + 1] * B + str[i]) % M1;
// //         rh2[i] = (rh2[i + 1] * B + str[i]) % M2;
// //     }
// // }

// // pair<ll, ll> getH(int l, int r) 
// // {
// //     ll v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % M1 + M1) % M1;
// //     ll v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % M2 + M2) % M2;
// //     return {v1, v2};
// // }

// // pair<ll, ll> getRH(int l, int r) 
// // {
// //     ll v1 = (rh1[l] - rh1[r + 1] * p1[r - l + 1] % M1 + M1) % M1;
// //     ll v2 = (rh2[l] - rh2[r + 1] * p2[r - l + 1] % M2 + M2) % M2;
// //     return {v1, v2};
// // }

// // bool is_pal(int l, int r) 
// // {
// //     return getH(l, r) == getRH(l, r);
// // }

// // // 求字符串 str（1-indexed）的最长回文前缀长度
// // int longest_pal_prefix(const string &str) 
// // {
// //     int len = str.size() - 1;
// //     init_hash(str);
// //     int best = 1;
// //     for (int i = 1; i <= len; ++i) 
// //     {
// //         // 奇数长度回文，中心 i
// //         int lo = 0, hi = min(i - 1, len - i), ans = 0;
// //         while (lo <= hi) 
// //         {
// //             int mid = (lo + hi) >> 1;
// //             if (is_pal(i - mid, i + mid))
// //             {
// //                 ans = mid;
// //                 lo = mid + 1;
// //             }
// //             else
// //             {
// //                 hi = mid - 1;
// //             }
// //         }
// //         if (i - ans == 1)
// //         {
// //             best = max(best, 2 * ans + 1);
// //         }
// //         // 偶数长度回文，中心 i, i+1
// //         if (i < len && str[i] == str[i + 1]) 
// //         {
// //             lo = 0, hi = min(i - 1, len - i - 1), ans = 0;
// //             while (lo <= hi) 
// //             {
// //                 int mid = (lo + hi) >> 1;
// //                 if (is_pal(i - mid, i + 1 + mid))
// //                 {
// //                     ans = mid;
// //                     lo = mid + 1;
// //                 }
// //                 else
// //                 {
// //                     hi = mid - 1;
// //                 }
// //             }
// //             if (i - ans == 1)
// //             {
// //                 best = max(best, 2 * ans + 2);
// //             }
// //         }
// //     }
// //     return best;
// // }

// // int main() 
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);
// //     cin>>s;
// //     n = s.size();
// //     string rev = s;
// //     reverse(rev.begin(), rev.end());

// //     // 公共前缀
// //     int L = 0;
// //     while (L < n && s[L] == rev[L])
// //     {
// //         ++L;
// //     }
// //     if (L == n) 
// //     {
// //         cout<<2 * n<<'\n';
// //         return 0;
// //     }

// //     // 剩余部分
// //     string s_mid = " " + s.substr(L, n - L);
// //     string rev_mid = " " + rev.substr(L, n - L);

// //     int pre = longest_pal_prefix(s_mid);
// //     int suf = longest_pal_prefix(rev_mid); // rev 的前缀对应原串的后缀
// //     int add = max(pre, suf);
// //     cout<<2 * L + add<<'\n';

// //     return 0;
// // }

// // 还是太复杂了，不如直接 马拉车(Malacher)
// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 经典马拉车：求以某位置开头的最长回文前缀长度
// vector<int> malacher(const string& s)
// {
//     int n = s.size();
//     string t = "#";
//     for (char c : s)
//     {
//         t += c;
//         t += "#";
//     }

//     int m = t.size();
//     vector<int> p(m, 0);
//     vector<int> maxx(n, 0);
//     int c = 0, r = 0;
//     for (int i = 0; i < m; i++)
//     {
//         int mir = 2 * c - i;
//         if (i < r)
//         {
//             p[i] = min(r - i, p[mir]);
//         }

//         while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1])
//         {
//             p[i]++;
//         }

//         if (i + p[i] > r)
//         {
//             c = i;
//             r = i + p[i];
//         }

//         // i 对应在原字符串 s 中的位置
//         int l = (i - p[i]) >> 1;
//         int len = p[i];
//         if (l >= 0 && l < n)
//         {
//             maxx[l] = max(maxx[l], len);
//         }
//     }

//     return maxx;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         int n = s.size();
//         string t = s;
//         reverse(t.begin(), t.end());

//         // s 和 t的最长公共前缀长度
//         int L = 0;
//         // 暴力匹配
//         while (L < n && s[L] == t[L])
//         {
//             L++;
//         }

//         if (L == n)
//         {
//             cout<<2 * n<<endl;
//             return 0;
//         }

//         vector<int> preS = malacher(s);
//         vector<int> preT = malacher(t);

//         // 以 L 位置为起点的最长回文前缀长度
//         int add = max(preS[L], preT[L]);
//         int ans = 2 * L + add;

//         cout<<ans<<endl;
//     }

//     return 0;
// }