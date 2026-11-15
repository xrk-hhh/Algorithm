// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // using ll = long long;

// // const int N = 1.1e7 + 10;
// // const int B = 131, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

// // int n;
// // string s;
// // ll p1[N], p2[N];
// // ll h1[N], h2[N];
// // ll rh1[N], rh2[N];

// // void init()
// // {
// //     p1[0] = p2[0] = 1;
// //     for (int i = 1; i <= n; i++)
// //     {
// //         p1[i] = p1[i - 1] * B % mod1;
// //         p2[i] = p2[i - 1] * B % mod2;
// //         h1[i] = (h1[i - 1] * B + s[i]) % mod1;
// //         h2[i] = (h2[i - 1] * B + s[i]) % mod2;
// //     }
// //     for (int i = n; i >= 1; i--)
// //     {
// //         rh1[i] = (rh1[i + 1] * B + s[i]) % mod1;
// //         rh2[i] = (rh2[i + 1] * B + s[i]) % mod2;
// //     }
// // }

// // pair<ll, ll> getH(int l, int r)
// // {
// //     ll v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
// //     ll v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
// //     return {v1, v2};
// // }
// // pair<ll, ll> getRH(int l, int r)
// // {
// //     ll v1 = (rh1[l] - rh1[r + 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
// //     ll v2 = (rh2[l] - rh2[r + 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
// //     return {v1, v2};
// // }

// // bool check(int len)
// // {
// //     for (int i = 1; i <= n - len + 1; i++)
// //     {
// //         if (getH(i, i + len - 1) == getRH(i, i + len - 1))
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
// //         s = " " + s;

// //         init();

// //         int l = 1, r = n + 1;
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

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// // 马拉车算法求：最长回文子串长度
// int malacher(const string& s)
// {
//     int n = s.size();
//     // 每个字符两边插入 #
//     string t = "#";
//     for (char c : s)
//     {
//         t += c;
//         t += "#";
//     }

//     int m = t.size();
//     // p[i]：位置 i 的回文半径
//     vector<int> p(m, 0);
//     // c：当前已知的、右边界最靠右的回文子串的中心位置
//     // r：这个回文子串的右边界（即 c + p[c]，p[c] 是以 c 为中心的回文半径）
//     int c = 0, r = 0;
//     int maxx = 0;
//     for (int i = 0; i < m; i++)
//     {
//         // 位置 i 关于 c 的镜像位置
//         int mir = 2 * c - i;
//         if (i < r)
//         {
//             p[i] = min(r - i, p[mir]);
//         }

//         // 扩展 p[i]
//         while (i - p[i] - 1 >= 0 && i + p[i] + 1 < m && t[i - p[i] - 1] == t[i + p[i] + 1])
//         {
//             p[i]++;
//         }

//         // 更新 c 和 r
//         if (i + p[i] > r)
//         {
//             c = i;
//             r = i + p[i];
//         }

//         maxx = max(maxx, p[i]);
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

//         cout<<malacher(s)<<endl;
//     }

//     return 0;
// }