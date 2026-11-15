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
//         string s, tar;
//         cin>>s>>tar;

//         // 因为把相邻两个硬币翻转两次相当于不翻，所以同一组硬币最多只会翻转一次
//         // 故翻转顺序无后效性，考虑贪心
//         // 从前往后比较，发现一个不同的硬币就把它和它后面的硬币翻转，计数器累加

//         int n = s.size();
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (s[i] != tar[i])
//             {
//                 ans++;
//                 s[i] = tar[i];
//                 s[i + 1] = s[i + 1] == 'o' ? '*' : 'o';
//             }
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }