// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// const int mod = 1e9 + 7;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     cin>>T;

//     while (T--)
//     {
//         string s;
//         cin>>s;

//         int n = s.size();
//         // 1-based 索引方便 KMP
//         s = " " + s;

//         vector<int> nxt(n + 1, 0);
//         // cnt[i]：表示长度为 i 的前缀的所有真 border 的个数（不管是否重叠）
//         vector<int> cnt(n + 1, 0);
//         // 计算 next 和 cnt
//         for (int i = 2, j = 0; i <= n; i++)
//         {
//             while (j && s[i] != s[j + 1])
//             {
//                 j = nxt[j];
//             }

//             if (s[i] == s[j + 1])
//             {
//                 j++;
//             }

//             nxt[i] = j;
//             cnt[i] = (j > 0) ? cnt[j] + 1 : 0;
//         }

//         ll ans = 1;
//         // 计算每个前缀的不重叠 border 个数
//         for (int i = 2, j = 0; i <= n; i++)
//         {
//             while (j && s[i] != s[j + 1])
//             {
//                 j = nxt[j];
//             }

//             if (s[i] == s[j + 1])
//             {
//                 j++;
//             }

//             // 要求 border 不重叠
//             while (j * 2 > i)
//             {
//                 j = nxt[j];
//             }

//             int num = (j > 0) ? cnt[j] + 1 : 0;

//             ans = ans * (num + 1) % mod;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }