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
//         int n;
//         cin>>n;

//         string s;
//         cin>>s;

//         // 计算最小循环节
//         // 结论：T = n - nxt[n]
//         // 显然，最优情况是前缀 ((k - 1)个 A) + L，后缀是((k - 1)个 A) + L
//         // 而 s 是 (k 个 A) + L，故 剩余部分即为 A（s - 后缀）
//         vector<int> nxt(n + 1, 0);
//         int j = 0;
//         for (int i = 1; i < n; i++)
//         {
//             while (j > 0 && s[i] != s[j])
//             {
//                 j = nxt[j];
//             }

//             if (s[i] == s[j])
//             {
//                 j++;
//             }

//             nxt[i + 1] = j;
//         }

//         cout<<n - nxt[n]<<endl;
//     }

//     return 0;
// }