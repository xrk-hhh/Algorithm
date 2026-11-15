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
//         string s;
//         cin>>s;

//         int n = s.size();
//         int q;
//         cin>>q;

//         vector<vector<pair<int, int>>> qs(26);
//         for (int i = 0; i < q; i++)
//         {
//             char c;
//             int x;
//             cin>>c>>x;

//             qs[c - 'a'].push_back({x, i});
//         }

//         // 预处理：括号匹配
//         stack<int> st;
//         vector<pair<int, int>> match;
//         for (int i = 0; i < n; i++)
//         {
//             if (s[i] == '(')
//             {
//                 st.push(i);
//             }
//             else if (s[i] == ')')
//             {
//                 int l = st.top();
//                 st.pop();

//                 match.push_back({l, i});
//             }
//         }

//         int m = match.size();
//         // pre[i] ：前 i 个字符中字母 c 出现的次数
//         // freq[cnt]：cnt 出现次数
//         vector<int> pre(n + 1, 0), freq(n + 1, 0);
//         vector<int> modify;
//         vector<int> ans(q + 1);
//         // 按字母单独处理
//         for (int c = 0; c < 26; c++)
//         {
//             // 若没有询问过该字母，直接跳过
//             if (qs[c].empty())
//             {
//                 continue;
//             }

//             pre[0] = 0;
//             for (int i = 0; i < n; i++)
//             {
//                 pre[i + 1] = pre[i] + (s[i] - 'a' == c);
//             }

//             modify.clear();
//             for (auto& [l, r] : match)
//             {
//                 // 对于匹配对(l,r)，中间区域是[l+1,r-1]
//                 // 内部字母 c 个数
//                 int cnt = pre[r] - pre[l + 1];
//                 // modify 记录了哪些 cnt 值被修改过，方便后面快速清空桶
//                 if (freq[cnt] == 0)
//                 {
//                     modify.push_back(cnt);
//                 }

//                 freq[cnt]++;
//             }

//             int maxx = 0;
//             for (int x : modify)
//             {
//                 maxx = max(maxx, x);
//             }

//             // suf[x]：计数 ≥ x 的匹配对数量。
//             vector<int> suf(maxx + 2, 0);
//             for (int x : modify)
//             {
//                 suf[x] += freq[x];
//             }
//             // 后缀和
//             for (int i = maxx; i >= 0; i--)
//             {
//                 suf[i] += suf[i + 1];
//             }

//             // 回答该字母的所有询问
//             for (auto& [x, idx] : qs[c])
//             {
//                 if (x > maxx)
//                 {
//                     ans[idx] = 0;
//                 }
//                 else
//                 {
//                     ans[idx] = suf[x];
//                 }
//             }

//             // 只清空 modify 中出现过的 cnt 值
//             for (int x : modify)
//             {
//                 freq[x] = 0;
//             }
//         }

//         for (int i = 0; i < q; i++)
//         {
//             cout<<ans[i]<<endl;
//         }
//     }

//     return 0;
// }