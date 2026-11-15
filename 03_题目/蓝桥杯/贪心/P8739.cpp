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
//         int k;
//         cin>>k;

//         string s;
//         cin>>s;

//         int n = s.size();
//         // 无法分为 k份
//         if (n % k != 0)
//         {
//             cout<<-1<<endl;
//             return 0;
//         }
//         int ans = 0;
//         // 每份长度
//         int t = n / k;
//         vector<int> cnt(26, 0);
//         // 枚举每一位
//         for (int i = 0; i < t; i++)
//         {
//             // 清零
//             cnt.assign(26, 0);
//             // 各份该位字符数量
//             for (int j = i; j < n; j += t)
//             {
//                 cnt[s[j] - 'a']++;
//             }

//             int maxx = 0;
//             // 求出该位字符数量最多的
//             for (int j = 0; j < 26; j++)
//             {
//                 maxx = max(maxx, cnt[j]);
//             }

//             // 需要修改的最少次数 = 每份长度 - 字符数量最多的
//             ans += k - maxx;
//         }

//         cout<<ans<<endl;
//     }

//     return 0;
// }