// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;

// #define endl '\n'
// using ll = long long;

// string s, ans;
// int len, a, b;

// // DFS搜索
// void dfs(int pos, int cnt1, int cnt2, string cur)
// {
//     if (pos == len)
//     {
//         if (cur > ans)
//         {
//             ans = cur;
//         }
//         return;
//     }

//     int d = cur[pos] - '0';

//     // 尽可能变大
//     for (int tar = 9; tar >= 0; tar--)
//     {
//         // 操作 1 所需
//         int nd1 = (tar - d + 10) % 10;
//         // 操作 2 所需
//         int nd2 = (d - tar + 10) % 10;
//         if (nd1 <= cnt1 || nd2 <= cnt2)
//         {
//             string t = cur;
//             t[pos] = '0' + tar;
//             if (nd1 <= cnt1 && nd2 <= cnt2)
//             {
//                 dfs(pos + 1, cnt1 - nd1, cnt2, t);          
//                 dfs(pos + 1, cnt1, cnt2 - nd2, t);          
//             }
//             else if (nd1 <= cnt1)
//             {
//                 dfs(pos + 1, cnt1 - nd1, cnt2, t);
//             }
//             else
//             {
//                 dfs(pos + 1, cnt1, cnt2 - nd2, t);
//             }
//             return;
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
//         cin>>s>>a>>b;

//         len = s.size();
        
//         ans = s;

//         dfs(0, a, b, s);

//         cout<<ans<<endl;
//     }

//     return 0;
// }