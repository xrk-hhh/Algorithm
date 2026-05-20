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
//         int n, m;
//         cin>>n>>m;

//         string s, t;
//         cin>>s>>t;

//         sort(t.begin(), t.end());

//         string ans;
//         int j = 0, k = 0;
//         for (int i = 0; i < n + m; i++)
//         {
//             if (j < n && k < m)
//             {
//                 // 注意：当 s 和 t 当前字符字典序相同时，只能取 s 中的，因为 s 后面还可能有比当前字典序更小的，而 t 字典序是递增的
//                 // 如：s: ba; t: bb
//                 // 答案应该是：babb
//                 // 而当字典序相同时如果取了 t 中的，答案则变成了：bbba
//                 if (t[k] < s[j])
//                 {
//                     ans += t[k];
//                     k++;
//                 }
//                 else
//                 {
//                     ans += s[j];
//                     j++;
//                 }
//             }
//             else if (j < n && k >= m)
//             {
//                 ans += s[j];
//                 j++;
//             }
//             else if (j >= n && k < m)
//             {
//                 ans += t[k];
//                 k++;
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }