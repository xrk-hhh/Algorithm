// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         unordered_set<string> dict;
//         string word;

//         // 读入词典，直到遇到 "."
//         while (cin>>word)
//         {
//             if (word == ".")
//             {
//                 break;
//             }

//             dict.insert(word);
//         }

//         // 读入 s，可能有多行（每 76 个字符换行，也可能最后一行不足 76）
//         string s, line;
//         while (cin>>line)
//         {
//             s += line;
//         }

//         int n = s.length();
//         vector<bool> dp(n + 1, false);
//         // 空前缀总是可以
//         dp[0] = true;

//         // 词典中单词最大长度
//         int maxx = 0;
//         for (auto& w : dict)
//         {
//             maxx = max(maxx, (int)w.length());
//         }

//         for (int i = 1; i <= n; i++)
//         {
//             // 检查所有可能的单词长度
//             for (int len = 1; len <= maxx && i - len >= 0; len++)
//             {
//                 if (dp[i - len])
//                 {
//                     string sub = s.substr(i - len, len);
//                     if (dict.count(sub))
//                     {
//                         dp[i] = true;
//                         // 找到一个合法分割即可
//                         break;
//                     }
//                 }
//             }
//         }

//         // 找最大的 i 满足 dp[i] == true
//         int ans = 0;
//         for (int i = n; i >= 0; i--)
//         {
//             if (dp[i])
//             {
//                 ans = i;
//                 break;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }