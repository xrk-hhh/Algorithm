// // #include <bits/stdc++.h>
// // using namespace std;

// // #define endl '\n'
// // #define ll long long

// // int n;
// // vector<string> word;
// // vector<int> used;
// // // overlaps[i][j] 存储所有可行重叠长度
// // vector<vector<vector<int>>> overlaps;
// // int maxx = 0;

// // // 记录 最后一个单词索引 和 当前字符串长度
// // // 避免字符串复制，能减少性能开销，提高性能
// // void dfs(int last, int cur)
// // {
// //     maxx = max(maxx, cur);
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (used[i] < 2)
// //         {
// //             const auto& ov = overlaps[last][i];
// //             for (int len : ov)
// //             {
// //                 used[i]++;
// //                 dfs(i, cur + (int)word[i].size() - len);
// //                 used[i]--;
// //             }
// //         }
// //     }
// // }

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int T = 1;
// //     // cin>>T;

// //     while (T--)
// //     {
// //         cin>>n;

// //         word.resize(n);
// //         for (int i = 0; i < n; i++)
// //         {
// //             cin>>word[i];
// //         }

// //         char start;
// //         cin>>start;

// //         // 预处理所有重叠长度
// //         overlaps.resize(n, vector<vector<int>>(n));
// //         for (int i = 0; i < n; i++)
// //         {
// //             for (int j = 0; j < n; j++)
// //             {
// //                 const string& a = word[i], b = word[j];
// //                 int la = a.size(), lb = b.size();
// //                 for (int len = 1; len < min(la, lb); len++)
// //                 {
// //                     if (a.substr(la - len) == b.substr(0, len))
// //                     {
// //                         overlaps[i][j].push_back(len);
// //                     }
// //                 }
// //             }
// //         }

// //         used.assign(n, 0);

// //         for (int i = 0; i < n; i++)
// //         {
// //             if (word[i][0] == start)
// //             {
// //                 used[i] = 1;
// //                 dfs(i, word[i].size());
// //                 used[i] = 0;
// //             }
// //         }

// //         cout<<maxx<<endl;
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define endl '\n'
// #define ll long long

// int n;
// vector<string> word;
// vector<int> used;
// int maxx = 0;

// void dfs(const string& s)
// {
//     maxx = max(maxx, (int)s.size());
//     for (int i = 0; i < n; i++)
//     {
//         if (used[i] < 2)
//         {
//             // 保证重叠长度严格小于两个单词的长度
//             // 因此不会出现一个单词完全包含另一个的情况。
//             for (int j = 1; j < min(s.size(), word[i].size()); j++)
//             {
//                 if (s.substr(s.size() - j) == word[i].substr(0, j))
//                 {
//                     used[i]++;
//                     dfs(s + word[i].substr(j));
//                     used[i]--;
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T = 1;
//     // cin>>T;

//     while (T--)
//     {
//         cin>>n;

//         word.resize(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin>>word[i];
//         }

//         char c;
//         cin>>c;

//         used.assign(n, 0);

//         for (int i = 0; i < n; i++)
//         {
//             if (word[i][0] == c)
//             {
//                 used[i]++;
//                 dfs(word[i]);
//                 used[i]--;
//             }
//         }

//         cout<<maxx<<endl;
//     }

//     return 0;
// }